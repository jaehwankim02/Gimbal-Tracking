// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rohang25_test:srv/SetGuidanceParam.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rohang25_test/srv/detail/set_guidance_param__rosidl_typesupport_introspection_c.h"
#include "rohang25_test/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rohang25_test/srv/detail/set_guidance_param__functions.h"
#include "rohang25_test/srv/detail/set_guidance_param__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void rohang25_test__srv__SetGuidanceParam_Request__rosidl_typesupport_introspection_c__SetGuidanceParam_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rohang25_test__srv__SetGuidanceParam_Request__init(message_memory);
}

void rohang25_test__srv__SetGuidanceParam_Request__rosidl_typesupport_introspection_c__SetGuidanceParam_Request_fini_function(void * message_memory)
{
  rohang25_test__srv__SetGuidanceParam_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember rohang25_test__srv__SetGuidanceParam_Request__rosidl_typesupport_introspection_c__SetGuidanceParam_Request_message_member_array[2] = {
  {
    "index",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rohang25_test__srv__SetGuidanceParam_Request, index),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "value",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rohang25_test__srv__SetGuidanceParam_Request, value),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rohang25_test__srv__SetGuidanceParam_Request__rosidl_typesupport_introspection_c__SetGuidanceParam_Request_message_members = {
  "rohang25_test__srv",  // message namespace
  "SetGuidanceParam_Request",  // message name
  2,  // number of fields
  sizeof(rohang25_test__srv__SetGuidanceParam_Request),
  rohang25_test__srv__SetGuidanceParam_Request__rosidl_typesupport_introspection_c__SetGuidanceParam_Request_message_member_array,  // message members
  rohang25_test__srv__SetGuidanceParam_Request__rosidl_typesupport_introspection_c__SetGuidanceParam_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  rohang25_test__srv__SetGuidanceParam_Request__rosidl_typesupport_introspection_c__SetGuidanceParam_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rohang25_test__srv__SetGuidanceParam_Request__rosidl_typesupport_introspection_c__SetGuidanceParam_Request_message_type_support_handle = {
  0,
  &rohang25_test__srv__SetGuidanceParam_Request__rosidl_typesupport_introspection_c__SetGuidanceParam_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rohang25_test
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rohang25_test, srv, SetGuidanceParam_Request)() {
  if (!rohang25_test__srv__SetGuidanceParam_Request__rosidl_typesupport_introspection_c__SetGuidanceParam_Request_message_type_support_handle.typesupport_identifier) {
    rohang25_test__srv__SetGuidanceParam_Request__rosidl_typesupport_introspection_c__SetGuidanceParam_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rohang25_test__srv__SetGuidanceParam_Request__rosidl_typesupport_introspection_c__SetGuidanceParam_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "rohang25_test/srv/detail/set_guidance_param__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rohang25_test/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "rohang25_test/srv/detail/set_guidance_param__functions.h"
// already included above
// #include "rohang25_test/srv/detail/set_guidance_param__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void rohang25_test__srv__SetGuidanceParam_Response__rosidl_typesupport_introspection_c__SetGuidanceParam_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rohang25_test__srv__SetGuidanceParam_Response__init(message_memory);
}

void rohang25_test__srv__SetGuidanceParam_Response__rosidl_typesupport_introspection_c__SetGuidanceParam_Response_fini_function(void * message_memory)
{
  rohang25_test__srv__SetGuidanceParam_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember rohang25_test__srv__SetGuidanceParam_Response__rosidl_typesupport_introspection_c__SetGuidanceParam_Response_message_member_array[1] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rohang25_test__srv__SetGuidanceParam_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rohang25_test__srv__SetGuidanceParam_Response__rosidl_typesupport_introspection_c__SetGuidanceParam_Response_message_members = {
  "rohang25_test__srv",  // message namespace
  "SetGuidanceParam_Response",  // message name
  1,  // number of fields
  sizeof(rohang25_test__srv__SetGuidanceParam_Response),
  rohang25_test__srv__SetGuidanceParam_Response__rosidl_typesupport_introspection_c__SetGuidanceParam_Response_message_member_array,  // message members
  rohang25_test__srv__SetGuidanceParam_Response__rosidl_typesupport_introspection_c__SetGuidanceParam_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  rohang25_test__srv__SetGuidanceParam_Response__rosidl_typesupport_introspection_c__SetGuidanceParam_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rohang25_test__srv__SetGuidanceParam_Response__rosidl_typesupport_introspection_c__SetGuidanceParam_Response_message_type_support_handle = {
  0,
  &rohang25_test__srv__SetGuidanceParam_Response__rosidl_typesupport_introspection_c__SetGuidanceParam_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rohang25_test
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rohang25_test, srv, SetGuidanceParam_Response)() {
  if (!rohang25_test__srv__SetGuidanceParam_Response__rosidl_typesupport_introspection_c__SetGuidanceParam_Response_message_type_support_handle.typesupport_identifier) {
    rohang25_test__srv__SetGuidanceParam_Response__rosidl_typesupport_introspection_c__SetGuidanceParam_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rohang25_test__srv__SetGuidanceParam_Response__rosidl_typesupport_introspection_c__SetGuidanceParam_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rohang25_test/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rohang25_test/srv/detail/set_guidance_param__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers rohang25_test__srv__detail__set_guidance_param__rosidl_typesupport_introspection_c__SetGuidanceParam_service_members = {
  "rohang25_test__srv",  // service namespace
  "SetGuidanceParam",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // rohang25_test__srv__detail__set_guidance_param__rosidl_typesupport_introspection_c__SetGuidanceParam_Request_message_type_support_handle,
  NULL  // response message
  // rohang25_test__srv__detail__set_guidance_param__rosidl_typesupport_introspection_c__SetGuidanceParam_Response_message_type_support_handle
};

static rosidl_service_type_support_t rohang25_test__srv__detail__set_guidance_param__rosidl_typesupport_introspection_c__SetGuidanceParam_service_type_support_handle = {
  0,
  &rohang25_test__srv__detail__set_guidance_param__rosidl_typesupport_introspection_c__SetGuidanceParam_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rohang25_test, srv, SetGuidanceParam_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rohang25_test, srv, SetGuidanceParam_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rohang25_test
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rohang25_test, srv, SetGuidanceParam)() {
  if (!rohang25_test__srv__detail__set_guidance_param__rosidl_typesupport_introspection_c__SetGuidanceParam_service_type_support_handle.typesupport_identifier) {
    rohang25_test__srv__detail__set_guidance_param__rosidl_typesupport_introspection_c__SetGuidanceParam_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)rohang25_test__srv__detail__set_guidance_param__rosidl_typesupport_introspection_c__SetGuidanceParam_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rohang25_test, srv, SetGuidanceParam_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rohang25_test, srv, SetGuidanceParam_Response)()->data;
  }

  return &rohang25_test__srv__detail__set_guidance_param__rosidl_typesupport_introspection_c__SetGuidanceParam_service_type_support_handle;
}
