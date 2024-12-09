// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rosbag2_storage_mcap_testdata:srv\BasicSrv.idl
// generated code does not contain a copyright notice

#ifndef ROSBAG2_STORAGE_MCAP_TESTDATA__SRV__DETAIL__BASIC_SRV__STRUCT_H_
#define ROSBAG2_STORAGE_MCAP_TESTDATA__SRV__DETAIL__BASIC_SRV__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'req'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/BasicSrv in the package rosbag2_storage_mcap_testdata.
typedef struct rosbag2_storage_mcap_testdata__srv__BasicSrv_Request
{
  rosidl_runtime_c__String req;
} rosbag2_storage_mcap_testdata__srv__BasicSrv_Request;

// Struct for a sequence of rosbag2_storage_mcap_testdata__srv__BasicSrv_Request.
typedef struct rosbag2_storage_mcap_testdata__srv__BasicSrv_Request__Sequence
{
  rosbag2_storage_mcap_testdata__srv__BasicSrv_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosbag2_storage_mcap_testdata__srv__BasicSrv_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'resp'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/BasicSrv in the package rosbag2_storage_mcap_testdata.
typedef struct rosbag2_storage_mcap_testdata__srv__BasicSrv_Response
{
  rosidl_runtime_c__String resp;
} rosbag2_storage_mcap_testdata__srv__BasicSrv_Response;

// Struct for a sequence of rosbag2_storage_mcap_testdata__srv__BasicSrv_Response.
typedef struct rosbag2_storage_mcap_testdata__srv__BasicSrv_Response__Sequence
{
  rosbag2_storage_mcap_testdata__srv__BasicSrv_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosbag2_storage_mcap_testdata__srv__BasicSrv_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROSBAG2_STORAGE_MCAP_TESTDATA__SRV__DETAIL__BASIC_SRV__STRUCT_H_
