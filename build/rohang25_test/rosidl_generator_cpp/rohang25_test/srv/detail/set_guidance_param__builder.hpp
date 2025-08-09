// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rohang25_test:srv/SetGuidanceParam.idl
// generated code does not contain a copyright notice

#ifndef ROHANG25_TEST__SRV__DETAIL__SET_GUIDANCE_PARAM__BUILDER_HPP_
#define ROHANG25_TEST__SRV__DETAIL__SET_GUIDANCE_PARAM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rohang25_test/srv/detail/set_guidance_param__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rohang25_test
{

namespace srv
{

namespace builder
{

class Init_SetGuidanceParam_Request_value
{
public:
  explicit Init_SetGuidanceParam_Request_value(::rohang25_test::srv::SetGuidanceParam_Request & msg)
  : msg_(msg)
  {}
  ::rohang25_test::srv::SetGuidanceParam_Request value(::rohang25_test::srv::SetGuidanceParam_Request::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rohang25_test::srv::SetGuidanceParam_Request msg_;
};

class Init_SetGuidanceParam_Request_index
{
public:
  Init_SetGuidanceParam_Request_index()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetGuidanceParam_Request_value index(::rohang25_test::srv::SetGuidanceParam_Request::_index_type arg)
  {
    msg_.index = std::move(arg);
    return Init_SetGuidanceParam_Request_value(msg_);
  }

private:
  ::rohang25_test::srv::SetGuidanceParam_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rohang25_test::srv::SetGuidanceParam_Request>()
{
  return rohang25_test::srv::builder::Init_SetGuidanceParam_Request_index();
}

}  // namespace rohang25_test


namespace rohang25_test
{

namespace srv
{

namespace builder
{

class Init_SetGuidanceParam_Response_success
{
public:
  Init_SetGuidanceParam_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rohang25_test::srv::SetGuidanceParam_Response success(::rohang25_test::srv::SetGuidanceParam_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rohang25_test::srv::SetGuidanceParam_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rohang25_test::srv::SetGuidanceParam_Response>()
{
  return rohang25_test::srv::builder::Init_SetGuidanceParam_Response_success();
}

}  // namespace rohang25_test

#endif  // ROHANG25_TEST__SRV__DETAIL__SET_GUIDANCE_PARAM__BUILDER_HPP_
