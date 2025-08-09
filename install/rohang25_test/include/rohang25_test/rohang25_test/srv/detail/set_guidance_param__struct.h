// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rohang25_test:srv/SetGuidanceParam.idl
// generated code does not contain a copyright notice

#ifndef ROHANG25_TEST__SRV__DETAIL__SET_GUIDANCE_PARAM__STRUCT_H_
#define ROHANG25_TEST__SRV__DETAIL__SET_GUIDANCE_PARAM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/SetGuidanceParam in the package rohang25_test.
typedef struct rohang25_test__srv__SetGuidanceParam_Request
{
  /// 요청: 몇 번째 파라미터(index) 를 어떤 값(value) 으로 바꿀지
  uint8_t index;
  double value;
} rohang25_test__srv__SetGuidanceParam_Request;

// Struct for a sequence of rohang25_test__srv__SetGuidanceParam_Request.
typedef struct rohang25_test__srv__SetGuidanceParam_Request__Sequence
{
  rohang25_test__srv__SetGuidanceParam_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rohang25_test__srv__SetGuidanceParam_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/SetGuidanceParam in the package rohang25_test.
typedef struct rohang25_test__srv__SetGuidanceParam_Response
{
  bool success;
} rohang25_test__srv__SetGuidanceParam_Response;

// Struct for a sequence of rohang25_test__srv__SetGuidanceParam_Response.
typedef struct rohang25_test__srv__SetGuidanceParam_Response__Sequence
{
  rohang25_test__srv__SetGuidanceParam_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rohang25_test__srv__SetGuidanceParam_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROHANG25_TEST__SRV__DETAIL__SET_GUIDANCE_PARAM__STRUCT_H_
