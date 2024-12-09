// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rosbag2_storage_mcap_testdata:msg\ComplexMsg.idl
// generated code does not contain a copyright notice

#ifndef ROSBAG2_STORAGE_MCAP_TESTDATA__MSG__DETAIL__COMPLEX_MSG__TRAITS_HPP_
#define ROSBAG2_STORAGE_MCAP_TESTDATA__MSG__DETAIL__COMPLEX_MSG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rosbag2_storage_mcap_testdata/msg/detail/complex_msg__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'b'
#include "rosbag2_storage_mcap_testdata/msg/detail/basic_msg__traits.hpp"

namespace rosbag2_storage_mcap_testdata
{

namespace msg
{

inline void to_flow_style_yaml(
  const ComplexMsg & msg,
  std::ostream & out)
{
  out << "{";
  // member: b
  {
    out << "b: ";
    to_flow_style_yaml(msg.b, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ComplexMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: b
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "b:\n";
    to_block_style_yaml(msg.b, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ComplexMsg & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace rosbag2_storage_mcap_testdata

namespace rosidl_generator_traits
{

[[deprecated("use rosbag2_storage_mcap_testdata::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rosbag2_storage_mcap_testdata::msg::ComplexMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  rosbag2_storage_mcap_testdata::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rosbag2_storage_mcap_testdata::msg::to_yaml() instead")]]
inline std::string to_yaml(const rosbag2_storage_mcap_testdata::msg::ComplexMsg & msg)
{
  return rosbag2_storage_mcap_testdata::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rosbag2_storage_mcap_testdata::msg::ComplexMsg>()
{
  return "rosbag2_storage_mcap_testdata::msg::ComplexMsg";
}

template<>
inline const char * name<rosbag2_storage_mcap_testdata::msg::ComplexMsg>()
{
  return "rosbag2_storage_mcap_testdata/msg/ComplexMsg";
}

template<>
struct has_fixed_size<rosbag2_storage_mcap_testdata::msg::ComplexMsg>
  : std::integral_constant<bool, has_fixed_size<rosbag2_storage_mcap_testdata::msg::BasicMsg>::value> {};

template<>
struct has_bounded_size<rosbag2_storage_mcap_testdata::msg::ComplexMsg>
  : std::integral_constant<bool, has_bounded_size<rosbag2_storage_mcap_testdata::msg::BasicMsg>::value> {};

template<>
struct is_message<rosbag2_storage_mcap_testdata::msg::ComplexMsg>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROSBAG2_STORAGE_MCAP_TESTDATA__MSG__DETAIL__COMPLEX_MSG__TRAITS_HPP_
