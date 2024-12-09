// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rosbag2_storage_mcap_testdata:msg\BasicIdl.idl
// generated code does not contain a copyright notice

#ifndef ROSBAG2_STORAGE_MCAP_TESTDATA__MSG__DETAIL__BASIC_IDL__STRUCT_H_
#define ROSBAG2_STORAGE_MCAP_TESTDATA__MSG__DETAIL__BASIC_IDL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/BasicIdl in the package rosbag2_storage_mcap_testdata.
typedef struct rosbag2_storage_mcap_testdata__msg__BasicIdl
{
  float x;
} rosbag2_storage_mcap_testdata__msg__BasicIdl;

// Struct for a sequence of rosbag2_storage_mcap_testdata__msg__BasicIdl.
typedef struct rosbag2_storage_mcap_testdata__msg__BasicIdl__Sequence
{
  rosbag2_storage_mcap_testdata__msg__BasicIdl * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosbag2_storage_mcap_testdata__msg__BasicIdl__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROSBAG2_STORAGE_MCAP_TESTDATA__MSG__DETAIL__BASIC_IDL__STRUCT_H_
