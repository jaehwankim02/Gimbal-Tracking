// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rohang25_test:srv/SetGuidanceParam.idl
// generated code does not contain a copyright notice

#ifndef ROHANG25_TEST__SRV__DETAIL__SET_GUIDANCE_PARAM__TRAITS_HPP_
#define ROHANG25_TEST__SRV__DETAIL__SET_GUIDANCE_PARAM__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rohang25_test/srv/detail/set_guidance_param__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rohang25_test
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetGuidanceParam_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: index
  {
    out << "index: ";
    rosidl_generator_traits::value_to_yaml(msg.index, out);
    out << ", ";
  }

  // member: value
  {
    out << "value: ";
    rosidl_generator_traits::value_to_yaml(msg.value, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetGuidanceParam_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: index
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "index: ";
    rosidl_generator_traits::value_to_yaml(msg.index, out);
    out << "\n";
  }

  // member: value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "value: ";
    rosidl_generator_traits::value_to_yaml(msg.value, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetGuidanceParam_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace rohang25_test

namespace rosidl_generator_traits
{

[[deprecated("use rohang25_test::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rohang25_test::srv::SetGuidanceParam_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  rohang25_test::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rohang25_test::srv::to_yaml() instead")]]
inline std::string to_yaml(const rohang25_test::srv::SetGuidanceParam_Request & msg)
{
  return rohang25_test::srv::to_yaml(msg);
}

template<>
inline const char * data_type<rohang25_test::srv::SetGuidanceParam_Request>()
{
  return "rohang25_test::srv::SetGuidanceParam_Request";
}

template<>
inline const char * name<rohang25_test::srv::SetGuidanceParam_Request>()
{
  return "rohang25_test/srv/SetGuidanceParam_Request";
}

template<>
struct has_fixed_size<rohang25_test::srv::SetGuidanceParam_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rohang25_test::srv::SetGuidanceParam_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rohang25_test::srv::SetGuidanceParam_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rohang25_test
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetGuidanceParam_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetGuidanceParam_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetGuidanceParam_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace rohang25_test

namespace rosidl_generator_traits
{

[[deprecated("use rohang25_test::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rohang25_test::srv::SetGuidanceParam_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  rohang25_test::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rohang25_test::srv::to_yaml() instead")]]
inline std::string to_yaml(const rohang25_test::srv::SetGuidanceParam_Response & msg)
{
  return rohang25_test::srv::to_yaml(msg);
}

template<>
inline const char * data_type<rohang25_test::srv::SetGuidanceParam_Response>()
{
  return "rohang25_test::srv::SetGuidanceParam_Response";
}

template<>
inline const char * name<rohang25_test::srv::SetGuidanceParam_Response>()
{
  return "rohang25_test/srv/SetGuidanceParam_Response";
}

template<>
struct has_fixed_size<rohang25_test::srv::SetGuidanceParam_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rohang25_test::srv::SetGuidanceParam_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rohang25_test::srv::SetGuidanceParam_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<rohang25_test::srv::SetGuidanceParam>()
{
  return "rohang25_test::srv::SetGuidanceParam";
}

template<>
inline const char * name<rohang25_test::srv::SetGuidanceParam>()
{
  return "rohang25_test/srv/SetGuidanceParam";
}

template<>
struct has_fixed_size<rohang25_test::srv::SetGuidanceParam>
  : std::integral_constant<
    bool,
    has_fixed_size<rohang25_test::srv::SetGuidanceParam_Request>::value &&
    has_fixed_size<rohang25_test::srv::SetGuidanceParam_Response>::value
  >
{
};

template<>
struct has_bounded_size<rohang25_test::srv::SetGuidanceParam>
  : std::integral_constant<
    bool,
    has_bounded_size<rohang25_test::srv::SetGuidanceParam_Request>::value &&
    has_bounded_size<rohang25_test::srv::SetGuidanceParam_Response>::value
  >
{
};

template<>
struct is_service<rohang25_test::srv::SetGuidanceParam>
  : std::true_type
{
};

template<>
struct is_service_request<rohang25_test::srv::SetGuidanceParam_Request>
  : std::true_type
{
};

template<>
struct is_service_response<rohang25_test::srv::SetGuidanceParam_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROHANG25_TEST__SRV__DETAIL__SET_GUIDANCE_PARAM__TRAITS_HPP_
