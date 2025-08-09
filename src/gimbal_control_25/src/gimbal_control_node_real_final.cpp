#include <rclcpp/rclcpp.hpp>
#include <rcl_interfaces/msg/set_parameters_result.hpp>

#include <iostream>
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <cerrno>
#include <chrono>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cmath>
#include <vector>
#include <sstream>
#include <iomanip>
#include <geometry_msgs/msg/point32.hpp>
#include <px4_msgs/msg/vehicle_local_position.hpp>
#include <std_msgs/msg/bool.hpp>
#include <std_msgs/msg/int32.hpp>
#include <std_msgs/msg/float64_multi_array.hpp>
#include <yolov11_msgs/msg/detection.hpp>
#include <sensor_msgs/msg/camera_info.hpp>
#include <Eigen/Dense>
#include <sstream>
#include <Eigen/Geometry>
#include <stdint.h>
#include <chrono>
#include <array>
#include <algorithm> // std::min/max

using namespace px4_msgs::msg;
using namespace std::chrono;
using namespace std::chrono_literals;

class GimbalControlNode : public rclcpp::Node {
public:
    GimbalControlNode()
    : Node("gimbal_control_node")
    , detection_ready_(true)
    , camera_info_ready_(false)
    , det_center_x_(0.0f)
    , det_center_y_(0.0f)
    , last_pan_deg_(0.0)
    , last_tilt_deg_(0.0)
    {
        auto qos = rclcpp::SensorDataQoS();
        RCLCPP_INFO(get_logger(), "Gimbal Control Node 시작됨");

        // 파라미터 선언
        this->declare_parameter("deadband_pan_deg",  params_.deadband_pan_deg);
        this->declare_parameter("deadband_tilt_deg", params_.deadband_tilt_deg);
        this->declare_parameter("alpha_tilt",        params_.alpha_tilt);
        this->declare_parameter("alpha_pan",         params_.alpha_pan);
        this->declare_parameter("tilt_bias_deg",     params_.tilt_bias_deg);
        this->declare_parameter("timer_ms",          params_.timer_ms);
        this->declare_parameter("server_ip",         params_.server_ip);
        this->declare_parameter("server_port",       params_.server_port);

        // 현재 값 로드
        this->get_parameter("deadband_pan_deg",  params_.deadband_pan_deg);
        this->get_parameter("deadband_tilt_deg", params_.deadband_tilt_deg);
        this->get_parameter("alpha_tilt",        params_.alpha_tilt);
        this->get_parameter("alpha_pan",         params_.alpha_pan);
        this->get_parameter("tilt_bias_deg",     params_.tilt_bias_deg);
        this->get_parameter("timer_ms",          params_.timer_ms);
        this->get_parameter("server_ip",         params_.server_ip);
        this->get_parameter("server_port",       params_.server_port);

        RCLCPP_INFO(get_logger(),
          "Params: deadband_pan=%.2f, deadband_tilt=%.2f, alpha_pan=%.2f, alpha_tilt=%.2f, "
          "tilt_bias=%.1f, timer=%dms, ip=%s, port=%d",
          params_.deadband_pan_deg, params_.deadband_tilt_deg,
          params_.alpha_pan, params_.alpha_tilt,
          params_.tilt_bias_deg, params_.timer_ms,
          params_.server_ip.c_str(), params_.server_port);

        // 구독
        caminfo_sub_ = create_subscription<sensor_msgs::msg::CameraInfo>(
            "/camera/camera_info", qos, [this](sensor_msgs::msg::CameraInfo::SharedPtr msg) {
                fx_ = msg->k[0]; fy_ = msg->k[4];
                cx_ = msg->k[2]; cy_ = msg->k[5];
                img_w_ = msg->width; img_h_ = msg->height;
                camera_info_ready_ = true;
            });

        det_sub_ = create_subscription<yolov11_msgs::msg::Detection>(
            "/yolov11/detection", qos, [this](yolov11_msgs::msg::Detection::SharedPtr msg) {
                if (msg->center_x < 1e-2 && msg->center_y < 1e-2) {
                    detection_ready_ = false; return;
                }
                det_center_x_ = msg->center_x;
                det_center_y_ = msg->center_y;
                detection_ready_ = true;
            });

        // 동적 파라미터 콜백
        param_cb_ = this->add_on_set_parameters_callback(
            [this](const std::vector<rclcpp::Parameter> &params) {
                rcl_interfaces::msg::SetParametersResult res;
                res.successful = true;
                res.reason = "ok";

                int new_timer_ms = params_.timer_ms;

                auto clamp = [](double v, double lo, double hi){
                    return std::max(lo, std::min(v, hi));
                };

                for (const auto &p : params) {
                    const auto &name = p.get_name();

                    if (name == "deadband_pan_deg") {
                        params_.deadband_pan_deg = clamp(p.as_double(), 0.0, 30.0);
                        RCLCPP_INFO(get_logger(), "[param] deadband_pan_deg=%.3f", params_.deadband_pan_deg);

                    } else if (name == "deadband_tilt_deg") {
                        params_.deadband_tilt_deg = clamp(p.as_double(), 0.0, 30.0);
                        RCLCPP_INFO(get_logger(), "[param] deadband_tilt_deg=%.3f", params_.deadband_tilt_deg);

                    } else if (name == "alpha_pan") {
                        params_.alpha_pan = clamp(p.as_double(), 0.0, 1.0);
                        RCLCPP_INFO(get_logger(), "[param] alpha_pan=%.3f", params_.alpha_pan);

                    } else if (name == "alpha_tilt") {
                        params_.alpha_tilt = clamp(p.as_double(), 0.0, 1.0);
                        RCLCPP_INFO(get_logger(), "[param] alpha_tilt=%.3f", params_.alpha_tilt);

                    } else if (name == "tilt_bias_deg") {
                        params_.tilt_bias_deg = clamp(p.as_double(), -180.0, 180.0);
                        RCLCPP_INFO(get_logger(), "[param] tilt_bias_deg=%.3f", params_.tilt_bias_deg);

                    } else if (name == "server_ip") {
                        params_.server_ip = p.as_string();
                        RCLCPP_INFO(get_logger(), "[param] server_ip=%s", params_.server_ip.c_str());

                    } else if (name == "server_port") {
                        params_.server_port = static_cast<int>(p.as_int());
                        RCLCPP_INFO(get_logger(), "[param] server_port=%d", params_.server_port);

                    } else if (name == "timer_ms") {
                        new_timer_ms = static_cast<int>(p.as_int());
                        if (new_timer_ms < 5) new_timer_ms = 5;
                    }
                    RCLCPP_INFO(get_logger(),
                    "[param applied] pan_db=%.2f tilt_db=%.2f alpha_pan=%.2f alpha_tilt=%.2f tilt_bias=%.1f timer=%d",
                    params_.deadband_pan_deg, params_.deadband_tilt_deg,
                    params_.alpha_pan, params_.alpha_tilt,
                    params_.tilt_bias_deg, params_.timer_ms);
                }

                // timer_ms 변경시 타이머 재설정
                if (new_timer_ms != params_.timer_ms) {
                    params_.timer_ms = new_timer_ms;
                    RCLCPP_INFO(get_logger(), "[param] timer_ms=%d (timer reset)", params_.timer_ms);
                    if (timer_) timer_->cancel();
                    timer_ = create_wall_timer(
                        std::chrono::milliseconds(params_.timer_ms),
                        std::bind(&GimbalControlNode::control_loop, this));
                }

                return res;
            }
        );

        // 타이머 시작
        timer_ = create_wall_timer(
            std::chrono::milliseconds(params_.timer_ms),
            std::bind(&GimbalControlNode::control_loop, this));
    }

private:
    // --------- 파라미터 구조체 ----------
    struct ControlParams {
        double      deadband_pan_deg  {2.0};
        double      deadband_tilt_deg {0.5};
        double      alpha_tilt        {0.8};
        double      alpha_pan         {0.85};
        double      tilt_bias_deg     {-90.0};   // 직하방 오프셋
        int         timer_ms          {500};
        std::string server_ip         {"172.16.15.224"};
        int         server_port       {37260};
        int         recv_buf_size     {64};
    } params_;

    // --------- 동적 파라미터 핸들 ----------
    rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr param_cb_;

    // --------- ROS 통신 멤버 ----------
    rclcpp::Subscription<sensor_msgs::msg::CameraInfo>::SharedPtr caminfo_sub_;
    rclcpp::Subscription<yolov11_msgs::msg::Detection>::SharedPtr det_sub_;
    rclcpp::TimerBase::SharedPtr                                   timer_;

    // --------- 상태/버퍼 ----------
    bool   detection_ready_, camera_info_ready_;
    float  det_center_x_, det_center_y_;
    double last_pan_deg_, last_tilt_deg_;

    // 카메라 내부 파라미터
    float fx_{0}, fy_{0}, cx_{0}, cy_{0};
    int   img_w_{1280}, img_h_{720};

    // 짐벌 명령 인코딩 바이트
    uint8_t yaw_hex_[2]{0,0}, pitch_hex_[2]{0,0};

    // CRC16 테이블
    const uint16_t crc16_tab[256]= {0x0,0x1021,0x2042,0x3063,0x4084,0x50a5,0x60c6,0x70e7,
        0x8108,0x9129,0xa14a,0xb16b,0xc18c,0xd1ad,0xe1ce,0xf1ef,
        0x1231,0x210,0x3273,0x2252,0x52b5,0x4294,0x72f7,0x62d6,
        0x9339,0x8318,0xb37b,0xa35a,0xd3bd,0xc39c,0xf3ff,0xe3de,
        0x2462,0x3443,0x420,0x1401,0x64e6,0x74c7,0x44a4,0x5485,
        0xa56a,0xb54b,0x8528,0x9509,0xe5ee,0xf5cf,0xc5ac,0xd58d,
        0x3653,0x2672,0x1611,0x630,0x76d7,0x66f6,0x5695,0x46b4,
        0xb75b,0xa77a,0x9719,0x8738,0xf7df,0xe7fe,0xd79d,0xc7bc,
        0x48c4,0x58e5,0x6886,0x78a7,0x840,0x1861,0x2802,0x3823,
        0xc9cc,0xd9ed,0xe98e,0xf9af,0x8948,0x9969,0xa90a,0xb92b,
        0x5af5,0x4ad4,0x7ab7,0x6a96,0x1a71,0xa50,0x3a33,0x2a12,
        0xdbfd,0xcbdc,0xfbbf,0xeb9e,0x9b79,0x8b58,0xbb3b,0xab1a,
        0x6ca6,0x7c87,0x4ce4,0x5cc5,0x2c22,0x3c03,0xc60,0x1c41,
        0xedae,0xfd8f,0xcdec,0xddcd,0xad2a,0xbd0b,0x8d68,0x9d49,
        0x7e97,0x6eb6,0x5ed5,0x4ef4,0x3e13,0x2e32,0x1e51,0xe70,
        0xff9f,0xefbe,0xdfdd,0xcffc,0xbf1b,0xaf3a,0x9f59,0x8f78,
        0x9188,0x81a9,0xb1ca,0xa1eb,0xd10c,0xc12d,0xf14e,0xe16f,
        0x1080,0xa1,0x30c2,0x20e3,0x5004,0x4025,0x7046,0x6067,
        0x83b9,0x9398,0xa3fb,0xb3da,0xc33d,0xd31c,0xe37f,0xf35e,
        0x2b1,0x1290,0x22f3,0x32d2,0x4235,0x5214,0x6277,0x7256,
        0xb5ea,0xa5cb,0x95a8,0x8589,0xf56e,0xe54f,0xd52c,0xc50d,
        0x34e2,0x24c3,0x14a0,0x481,0x7466,0x6447,0x5424,0x4405,
        0xa7db,0xb7fa,0x8799,0x97b8,0xe75f,0xf77e,0xc71d,0xd73c,
        0x26d3,0x36f2,0x691,0x16b0,0x6657,0x7676,0x4615,0x5634,
        0xd94c,0xc96d,0xf90e,0xe92f,0x99c8,0x89e9,0xb98a,0xa9ab,
        0x5844,0x4865,0x7806,0x6827,0x18c0,0x8e1,0x3882,0x28a3,
        0xcb7d,0xdb5c,0xeb3f,0xfb1e,0x8bf9,0x9bd8,0xabbb,0xbb9a,
        0x4a75,0x5a54,0x6a37,0x7a16,0xaf1,0x1ad0,0x2ab3,0x3a92,
        0xfd2e,0xed0f,0xdd6c,0xcd4d,0xbdaa,0xad8b,0x9de8,0x8dc9,
        0x7c26,0x6c07,0x5c64,0x4c45,0x3ca2,0x2c83,0x1ce0,0xcc1,
        0xef1f,0xff3e,0xcf5d,0xdf7c,0xaf9b,0xbfba,0x8fd9,0x9ff8,
        0x6e17,0x7e36,0x4e55,0x5e74,0x2e93,0x3eb2,0xed1,0x1ef0
    };

    // CRC 계산
    uint16_t CRC16_cal(uint8_t *ptr, uint32_t len, uint16_t crc_init) {
        uint16_t crc = crc_init;
        while (len--) {
            uint8_t temp = (crc >> 8) & 0xFF;
            uint16_t table_val = crc16_tab[*ptr++ ^ temp];
            crc = (crc << 8) ^ table_val;
        }
        return crc;
    }

    // 각도 인코딩
    void encode_attitude(double yaw_deg, double pitch_deg, uint8_t* oy, uint8_t* op) {
        int16_t vy = static_cast<int16_t>(yaw_deg * 10);
        int16_t vp = static_cast<int16_t>(pitch_deg * 10);
        oy[0] = vy & 0xFF;     oy[1] = (vy >> 8) & 0xFF;
        op[0] = vp & 0xFF;     op[1] = (vp >> 8) & 0xFF;
    }

    // 메인 루프
    void control_loop() {
        if (!camera_info_ready_) { RCLCPP_WARN(get_logger(), "waiting for camera_info..."); return; }
        if (!detection_ready_) return;
        detection_ready_ = false;

        // YOLO → 원본 이미지 좌표
        const float net_w = 640.0f, net_h = 640.0f;
        float scale_w = net_w / static_cast<float>(img_w_);
        float scale_h = net_h / static_cast<float>(img_h_);

        float u = det_center_x_ / scale_w;
        float v = det_center_y_ / scale_h;

        // 카메라 좌표계
        float Z = 1.0f;
        float X = (u - cx_) * Z / fx_;
        float Y = (v - cy_) * Z / fy_;
        Eigen::Vector3f v_world{X, Y, Z};

        // raw pan/tilt
        double new_pan_deg  = -std::atan2(v_world[0], v_world[2]) * 180.0 / M_PI;
        //double denom    = std::hypot(v_world[0], v_world[2]);
        //double new_tilt_deg = -std::atan2(v_world[1], denom) * 180.0 / M_PI;

        // tilt 보정 + EMA
        constexpr double TILT_SIGN = -1.0;
        double tilt_err_deg    = std::atan2((v - cy_), fy_) * 180.0 / M_PI * TILT_SIGN;
        double target_tilt_deg = last_tilt_deg_ + tilt_err_deg;
        double new_tilt_deg = params_.alpha_tilt * target_tilt_deg + (1.0 - params_.alpha_tilt) * last_tilt_deg_;

        // 데드밴드
        if (std::fabs(new_pan_deg  - last_pan_deg_)  < params_.deadband_pan_deg &&
            std::fabs(new_tilt_deg - last_tilt_deg_) < params_.deadband_tilt_deg) {
            return;
        }

        new_pan_deg = new_pan_deg + params_.alpha_pan * last_pan_deg_;

        // bias 적용
        double cmd_pan  = new_pan_deg;
        double cmd_tilt = new_tilt_deg + params_.tilt_bias_deg;

        // 전송
        encode_attitude(cmd_pan, cmd_tilt, yaw_hex_, pitch_hex_);
        send_gimbal_command();

        last_pan_deg_  = new_pan_deg;
        last_tilt_deg_ = new_tilt_deg;
    }

    void send_gimbal_command() {
        int sock = socket(AF_INET, SOCK_DGRAM, 0);
        if (sock < 0) { RCLCPP_ERROR(get_logger(), "socket creation failed"); return; }

        sockaddr_in addr{};
        addr.sin_family      = AF_INET;
        addr.sin_port        = htons(params_.server_port);
        addr.sin_addr.s_addr = inet_addr(params_.server_ip.c_str());

        uint8_t buf[14] = {
            0x55,0x66,0x01,0x04, 0x00,0x00,0x00,0x0E,
            yaw_hex_[0], yaw_hex_[1],
            pitch_hex_[0], pitch_hex_[1],
            0x00,0x00
        };

        uint16_t crc = CRC16_cal(buf, 12, 0);
        buf[12] = crc & 0xFF;
        buf[13] = (crc >> 8) & 0xFF;

        sendto(sock, buf, sizeof(buf), 0, (sockaddr*)&addr, sizeof(addr));
        close(sock);

        int16_t vy = static_cast<int16_t>((static_cast<uint16_t>(yaw_hex_[1])   << 8) | yaw_hex_[0]);
        int16_t vp = static_cast<int16_t>((static_cast<uint16_t>(pitch_hex_[1]) << 8) | pitch_hex_[0]);
        RCLCPP_INFO_THROTTLE(get_logger(), *get_clock(), 200,
            "TX angles: yaw=%d (%.1f deg), pitch=%d (%.1f deg)  CRC=0x%04X",
            static_cast<int>(vy), vy/10.0, static_cast<int>(vp), vp/10.0, crc);
    }
};

int main(int argc, char *argv[]) {
    //setenv("ROS_LOG_DIR", "/home/jaehwan/gimbal_logs", 1);
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<GimbalControlNode>());
    rclcpp::shutdown();
    return 0;
}
