// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rosbag2_storage_mcap_testdata:srv\BasicSrv.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rosbag2_storage_mcap_testdata/srv/detail/basic_srv__rosidl_typesupport_introspection_c.h"
#include "rosbag2_storage_mcap_testdata/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rosbag2_storage_mcap_testdata/srv/detail/basic_srv__functions.h"
#include "rosbag2_storage_mcap_testdata/srv/detail/basic_srv__struct.h"


// Include directives for member types
// Member `req`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void rosbag2_storage_mcap_testdata__srv__BasicSrv_Request__rosidl_typesupport_introspection_c__BasicSrv_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rosbag2_storage_mcap_testdata__srv__BasicSrv_Request__init(message_memory);
}

void rosbag2_storage_mcap_testdata__srv__BasicSrv_Request__rosidl_typesupport_introspection_c__BasicSrv_Request_fini_function(void * message_memory)
{
  rosbag2_storage_mcap_testdata__srv__BasicSrv_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember rosbag2_storage_mcap_testdata__srv__BasicSrv_Request__rosidl_typesupport_introspection_c__BasicSrv_Request_message_member_array[1] = {
  {
    "req",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rosbag2_storage_mcap_testdata__srv__BasicSrv_Request, req),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rosbag2_storage_mcap_testdata__srv__BasicSrv_Request__rosidl_typesupport_introspection_c__BasicSrv_Request_message_members = {
  "rosbag2_storage_mcap_testdata__srv",  // message namespace
  "BasicSrv_Request",  // message name
  1,  // number of fields
  sizeof(rosbag2_storage_mcap_testdata__srv__BasicSrv_Request),
  rosbag2_storage_mcap_testdata__srv__BasicSrv_Request__rosidl_typesupport_introspection_c__BasicSrv_Request_message_member_array,  // message members
  rosbag2_storage_mcap_testdata__srv__BasicSrv_Request__rosidl_typesupport_introspection_c__BasicSrv_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  rosbag2_storage_mcap_testdata__srv__BasicSrv_Request__rosidl_typesupport_introspection_c__BasicSrv_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rosbag2_storage_mcap_testdata__srv__BasicSrv_Request__rosidl_typesupport_introspection_c__BasicSrv_Request_message_type_support_handle = {
  0,
  &rosbag2_storage_mcap_testdata__srv__BasicSrv_Request__rosidl_typesupport_introspection_c__BasicSrv_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rosbag2_storage_mcap_testdata
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosbag2_storage_mcap_testdata, srv, BasicSrv_Request)() {
  if (!rosbag2_storage_mcap_testdata__srv__BasicSrv_Request__rosidl_typesupport_introspection_c__BasicSrv_Request_message_type_support_handle.typesupport_identifier) {
    rosbag2_storage_mcap_testdata__srv__BasicSrv_Request__rosidl_typesupport_introspection_c__BasicSrv_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rosbag2_storage_mcap_testdata__srv__BasicSrv_Request__rosidl_typesupport_introspection_c__BasicSrv_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "rosbag2_storage_mcap_testdata/srv/detail/basic_srv__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosbag2_storage_mcap_testdata/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "rosbag2_storage_mcap_testdata/srv/detail/basic_srv__functions.h"
// already included above
// #include "rosbag2_storage_mcap_testdata/srv/detail/basic_srv__struct.h"


// Include directives for member types
// Member `resp`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void rosbag2_storage_mcap_testdata__srv__BasicSrv_Response__rosidl_typesupport_introspection_c__BasicSrv_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rosbag2_storage_mcap_testdata__srv__BasicSrv_Response__init(message_memory);
}

void rosbag2_storage_mcap_testdata__srv__BasicSrv_Response__rosidl_typesupport_introspection_c__BasicSrv_Response_fini_function(void * message_memory)
{
  rosbag2_storage_mcap_testdata__srv__BasicSrv_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember rosbag2_storage_mcap_testdata__srv__BasicSrv_Response__rosidl_typesupport_introspection_c__BasicSrv_Response_message_member_array[1] = {
  {
    "resp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rosbag2_storage_mcap_testdata__srv__BasicSrv_Response, resp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rosbag2_storage_mcap_testdata__srv__BasicSrv_Response__rosidl_typesupport_introspection_c__BasicSrv_Response_message_members = {
  "rosbag2_storage_mcap_testdata__srv",  // message namespace
  "BasicSrv_Response",  // message name
  1,  // number of fields
  sizeof(rosbag2_storage_mcap_testdata__srv__BasicSrv_Response),
  rosbag2_storage_mcap_testdata__srv__BasicSrv_Response__rosidl_typesupport_introspection_c__BasicSrv_Response_message_member_array,  // message members
  rosbag2_storage_mcap_testdata__srv__BasicSrv_Response__rosidl_typesupport_introspection_c__BasicSrv_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  rosbag2_storage_mcap_testdata__srv__BasicSrv_Response__rosidl_typesupport_introspection_c__BasicSrv_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rosbag2_storage_mcap_testdata__srv__BasicSrv_Response__rosidl_typesupport_introspection_c__BasicSrv_Response_message_type_support_handle = {
  0,
  &rosbag2_storage_mcap_testdata__srv__BasicSrv_Response__rosidl_typesupport_introspection_c__BasicSrv_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rosbag2_storage_mcap_testdata
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosbag2_storage_mcap_testdata, srv, BasicSrv_Response)() {
  if (!rosbag2_storage_mcap_testdata__srv__BasicSrv_Response__rosidl_typesupport_introspection_c__BasicSrv_Response_message_type_support_handle.typesupport_identifier) {
    rosbag2_storage_mcap_testdata__srv__BasicSrv_Response__rosidl_typesupport_introspection_c__BasicSrv_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rosbag2_storage_mcap_testdata__srv__BasicSrv_Response__rosidl_typesupport_introspection_c__BasicSrv_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosbag2_storage_mcap_testdata/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosbag2_storage_mcap_testdata/srv/detail/basic_srv__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers rosbag2_storage_mcap_testdata__srv__detail__basic_srv__rosidl_typesupport_introspection_c__BasicSrv_service_members = {
  "rosbag2_storage_mcap_testdata__srv",  // service namespace
  "BasicSrv",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // rosbag2_storage_mcap_testdata__srv__detail__basic_srv__rosidl_typesupport_introspection_c__BasicSrv_Request_message_type_support_handle,
  NULL  // response message
  // rosbag2_storage_mcap_testdata__srv__detail__basic_srv__rosidl_typesupport_introspection_c__BasicSrv_Response_message_type_support_handle
};

static rosidl_service_type_support_t rosbag2_storage_mcap_testdata__srv__detail__basic_srv__rosidl_typesupport_introspection_c__BasicSrv_service_type_support_handle = {
  0,
  &rosbag2_storage_mcap_testdata__srv__detail__basic_srv__rosidl_typesupport_introspection_c__BasicSrv_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosbag2_storage_mcap_testdata, srv, BasicSrv_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosbag2_storage_mcap_testdata, srv, BasicSrv_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rosbag2_storage_mcap_testdata
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosbag2_storage_mcap_testdata, srv, BasicSrv)() {
  if (!rosbag2_storage_mcap_testdata__srv__detail__basic_srv__rosidl_typesupport_introspection_c__BasicSrv_service_type_support_handle.typesupport_identifier) {
    rosbag2_storage_mcap_testdata__srv__detail__basic_srv__rosidl_typesupport_introspection_c__BasicSrv_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)rosbag2_storage_mcap_testdata__srv__detail__basic_srv__rosidl_typesupport_introspection_c__BasicSrv_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosbag2_storage_mcap_testdata, srv, BasicSrv_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rosbag2_storage_mcap_testdata, srv, BasicSrv_Response)()->data;
  }

  return &rosbag2_storage_mcap_testdata__srv__detail__basic_srv__rosidl_typesupport_introspection_c__BasicSrv_service_type_support_handle;
}
