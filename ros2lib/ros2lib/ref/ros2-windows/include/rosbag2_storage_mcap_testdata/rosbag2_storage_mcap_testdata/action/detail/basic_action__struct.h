// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rosbag2_storage_mcap_testdata:action\BasicAction.idl
// generated code does not contain a copyright notice

#ifndef ROSBAG2_STORAGE_MCAP_TESTDATA__ACTION__DETAIL__BASIC_ACTION__STRUCT_H_
#define ROSBAG2_STORAGE_MCAP_TESTDATA__ACTION__DETAIL__BASIC_ACTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'goal'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/BasicAction in the package rosbag2_storage_mcap_testdata.
typedef struct rosbag2_storage_mcap_testdata__action__BasicAction_Goal
{
  rosidl_runtime_c__String goal;
} rosbag2_storage_mcap_testdata__action__BasicAction_Goal;

// Struct for a sequence of rosbag2_storage_mcap_testdata__action__BasicAction_Goal.
typedef struct rosbag2_storage_mcap_testdata__action__BasicAction_Goal__Sequence
{
  rosbag2_storage_mcap_testdata__action__BasicAction_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosbag2_storage_mcap_testdata__action__BasicAction_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/BasicAction in the package rosbag2_storage_mcap_testdata.
typedef struct rosbag2_storage_mcap_testdata__action__BasicAction_Result
{
  rosidl_runtime_c__String result;
} rosbag2_storage_mcap_testdata__action__BasicAction_Result;

// Struct for a sequence of rosbag2_storage_mcap_testdata__action__BasicAction_Result.
typedef struct rosbag2_storage_mcap_testdata__action__BasicAction_Result__Sequence
{
  rosbag2_storage_mcap_testdata__action__BasicAction_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosbag2_storage_mcap_testdata__action__BasicAction_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'feedback'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/BasicAction in the package rosbag2_storage_mcap_testdata.
typedef struct rosbag2_storage_mcap_testdata__action__BasicAction_Feedback
{
  rosidl_runtime_c__String feedback;
} rosbag2_storage_mcap_testdata__action__BasicAction_Feedback;

// Struct for a sequence of rosbag2_storage_mcap_testdata__action__BasicAction_Feedback.
typedef struct rosbag2_storage_mcap_testdata__action__BasicAction_Feedback__Sequence
{
  rosbag2_storage_mcap_testdata__action__BasicAction_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosbag2_storage_mcap_testdata__action__BasicAction_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "rosbag2_storage_mcap_testdata/action/detail/basic_action__struct.h"

/// Struct defined in action/BasicAction in the package rosbag2_storage_mcap_testdata.
typedef struct rosbag2_storage_mcap_testdata__action__BasicAction_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  rosbag2_storage_mcap_testdata__action__BasicAction_Goal goal;
} rosbag2_storage_mcap_testdata__action__BasicAction_SendGoal_Request;

// Struct for a sequence of rosbag2_storage_mcap_testdata__action__BasicAction_SendGoal_Request.
typedef struct rosbag2_storage_mcap_testdata__action__BasicAction_SendGoal_Request__Sequence
{
  rosbag2_storage_mcap_testdata__action__BasicAction_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosbag2_storage_mcap_testdata__action__BasicAction_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/BasicAction in the package rosbag2_storage_mcap_testdata.
typedef struct rosbag2_storage_mcap_testdata__action__BasicAction_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} rosbag2_storage_mcap_testdata__action__BasicAction_SendGoal_Response;

// Struct for a sequence of rosbag2_storage_mcap_testdata__action__BasicAction_SendGoal_Response.
typedef struct rosbag2_storage_mcap_testdata__action__BasicAction_SendGoal_Response__Sequence
{
  rosbag2_storage_mcap_testdata__action__BasicAction_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosbag2_storage_mcap_testdata__action__BasicAction_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/BasicAction in the package rosbag2_storage_mcap_testdata.
typedef struct rosbag2_storage_mcap_testdata__action__BasicAction_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} rosbag2_storage_mcap_testdata__action__BasicAction_GetResult_Request;

// Struct for a sequence of rosbag2_storage_mcap_testdata__action__BasicAction_GetResult_Request.
typedef struct rosbag2_storage_mcap_testdata__action__BasicAction_GetResult_Request__Sequence
{
  rosbag2_storage_mcap_testdata__action__BasicAction_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosbag2_storage_mcap_testdata__action__BasicAction_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "rosbag2_storage_mcap_testdata/action/detail/basic_action__struct.h"

/// Struct defined in action/BasicAction in the package rosbag2_storage_mcap_testdata.
typedef struct rosbag2_storage_mcap_testdata__action__BasicAction_GetResult_Response
{
  int8_t status;
  rosbag2_storage_mcap_testdata__action__BasicAction_Result result;
} rosbag2_storage_mcap_testdata__action__BasicAction_GetResult_Response;

// Struct for a sequence of rosbag2_storage_mcap_testdata__action__BasicAction_GetResult_Response.
typedef struct rosbag2_storage_mcap_testdata__action__BasicAction_GetResult_Response__Sequence
{
  rosbag2_storage_mcap_testdata__action__BasicAction_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosbag2_storage_mcap_testdata__action__BasicAction_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "rosbag2_storage_mcap_testdata/action/detail/basic_action__struct.h"

/// Struct defined in action/BasicAction in the package rosbag2_storage_mcap_testdata.
typedef struct rosbag2_storage_mcap_testdata__action__BasicAction_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  rosbag2_storage_mcap_testdata__action__BasicAction_Feedback feedback;
} rosbag2_storage_mcap_testdata__action__BasicAction_FeedbackMessage;

// Struct for a sequence of rosbag2_storage_mcap_testdata__action__BasicAction_FeedbackMessage.
typedef struct rosbag2_storage_mcap_testdata__action__BasicAction_FeedbackMessage__Sequence
{
  rosbag2_storage_mcap_testdata__action__BasicAction_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosbag2_storage_mcap_testdata__action__BasicAction_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROSBAG2_STORAGE_MCAP_TESTDATA__ACTION__DETAIL__BASIC_ACTION__STRUCT_H_
