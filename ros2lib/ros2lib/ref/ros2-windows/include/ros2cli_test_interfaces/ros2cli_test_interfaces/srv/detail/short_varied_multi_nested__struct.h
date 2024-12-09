// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ros2cli_test_interfaces:srv\ShortVariedMultiNested.idl
// generated code does not contain a copyright notice

#ifndef ROS2CLI_TEST_INTERFACES__SRV__DETAIL__SHORT_VARIED_MULTI_NESTED__STRUCT_H_
#define ROS2CLI_TEST_INTERFACES__SRV__DETAIL__SHORT_VARIED_MULTI_NESTED__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'short_varied_nested'
#include "ros2cli_test_interfaces/msg/detail/short_varied_nested__struct.h"

/// Struct defined in srv/ShortVariedMultiNested in the package ros2cli_test_interfaces.
typedef struct ros2cli_test_interfaces__srv__ShortVariedMultiNested_Request
{
  /// Comment - Nesting Level 3: 1 of 2
  ros2cli_test_interfaces__msg__ShortVariedNested short_varied_nested;
} ros2cli_test_interfaces__srv__ShortVariedMultiNested_Request;

// Struct for a sequence of ros2cli_test_interfaces__srv__ShortVariedMultiNested_Request.
typedef struct ros2cli_test_interfaces__srv__ShortVariedMultiNested_Request__Sequence
{
  ros2cli_test_interfaces__srv__ShortVariedMultiNested_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2cli_test_interfaces__srv__ShortVariedMultiNested_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/ShortVariedMultiNested in the package ros2cli_test_interfaces.
typedef struct ros2cli_test_interfaces__srv__ShortVariedMultiNested_Response
{
  /// Comment - Nesting Level 3: 2 of 2
  bool bool_value;
} ros2cli_test_interfaces__srv__ShortVariedMultiNested_Response;

// Struct for a sequence of ros2cli_test_interfaces__srv__ShortVariedMultiNested_Response.
typedef struct ros2cli_test_interfaces__srv__ShortVariedMultiNested_Response__Sequence
{
  ros2cli_test_interfaces__srv__ShortVariedMultiNested_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2cli_test_interfaces__srv__ShortVariedMultiNested_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROS2CLI_TEST_INTERFACES__SRV__DETAIL__SHORT_VARIED_MULTI_NESTED__STRUCT_H_
