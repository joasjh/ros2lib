// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rcl_interfaces:msg\Log.idl
// generated code does not contain a copyright notice

#ifndef RCL_INTERFACES__MSG__DETAIL__LOG__STRUCT_H_
#define RCL_INTERFACES__MSG__DETAIL__LOG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'DEBUG'.
/**
  * Debug is for pedantic information, which is useful when debugging issues.
 */
enum
{
  rcl_interfaces__msg__Log__DEBUG = 10
};

/// Constant 'INFO'.
/**
  * Info is the standard informational level and is used to report expected
  * information.
 */
enum
{
  rcl_interfaces__msg__Log__INFO = 20
};

/// Constant 'WARN'.
/**
  * Warning is for information that may potentially cause issues or possibly unexpected
  * behavior.
 */
enum
{
  rcl_interfaces__msg__Log__WARN = 30
};

/// Constant 'ERROR'.
/**
  * Error is for information that this node cannot resolve.
 */
enum
{
  rcl_interfaces__msg__Log__ERROR = 40
};

/// Constant 'FATAL'.
/**
  * Information about a impending node shutdown.
 */
enum
{
  rcl_interfaces__msg__Log__FATAL = 50
};

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"
// Member 'name'
// Member 'msg'
// Member 'file'
// Member 'function'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Log in the package rcl_interfaces.
/**
  * Severity level constants
  *
  * These logging levels follow the Python Standard
  * https://docs.python.org/3/library/logging.html#logging-levels
  * And are implemented in rcutils as well
  * https://github.com/ros2/rcutils/blob/35f29850064e0c33a4063cbc947ebbfeada11dba/include/rcutils/logging.h#L164-L172
  * This leaves space for other standard logging levels to be inserted in the middle in the future,
  * as well as custom user defined levels.
  * Since there are several other logging enumeration standard for different implementations,
  * other logging implementations may need to provide level mappings to match their internal implementations.
 */
typedef struct rcl_interfaces__msg__Log
{
  /// Fields
  ///
  /// Timestamp when this message was generated by the node.
  builtin_interfaces__msg__Time stamp;
  /// Corresponding log level, see above definitions.
  uint8_t level;
  /// The name representing the logger this message came from.
  rosidl_runtime_c__String name;
  /// The full log message.
  rosidl_runtime_c__String msg;
  /// The file the message came from.
  rosidl_runtime_c__String file;
  /// The function the message came from.
  rosidl_runtime_c__String function;
  /// The line in the file the message came from.
  uint32_t line;
} rcl_interfaces__msg__Log;

// Struct for a sequence of rcl_interfaces__msg__Log.
typedef struct rcl_interfaces__msg__Log__Sequence
{
  rcl_interfaces__msg__Log * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rcl_interfaces__msg__Log__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RCL_INTERFACES__MSG__DETAIL__LOG__STRUCT_H_
