// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rosbag2_storage_mcap_testdata:srv\BasicSrv.idl
// generated code does not contain a copyright notice

#ifndef ROSBAG2_STORAGE_MCAP_TESTDATA__SRV__DETAIL__BASIC_SRV__TRAITS_HPP_
#define ROSBAG2_STORAGE_MCAP_TESTDATA__SRV__DETAIL__BASIC_SRV__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rosbag2_storage_mcap_testdata/srv/detail/basic_srv__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rosbag2_storage_mcap_testdata
{

namespace srv
{

inline void to_flow_style_yaml(
  const BasicSrv_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: req
  {
    out << "req: ";
    rosidl_generator_traits::value_to_yaml(msg.req, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BasicSrv_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: req
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "req: ";
    rosidl_generator_traits::value_to_yaml(msg.req, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BasicSrv_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace rosbag2_storage_mcap_testdata

namespace rosidl_generator_traits
{

[[deprecated("use rosbag2_storage_mcap_testdata::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rosbag2_storage_mcap_testdata::srv::BasicSrv_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  rosbag2_storage_mcap_testdata::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rosbag2_storage_mcap_testdata::srv::to_yaml() instead")]]
inline std::string to_yaml(const rosbag2_storage_mcap_testdata::srv::BasicSrv_Request & msg)
{
  return rosbag2_storage_mcap_testdata::srv::to_yaml(msg);
}

template<>
inline const char * data_type<rosbag2_storage_mcap_testdata::srv::BasicSrv_Request>()
{
  return "rosbag2_storage_mcap_testdata::srv::BasicSrv_Request";
}

template<>
inline const char * name<rosbag2_storage_mcap_testdata::srv::BasicSrv_Request>()
{
  return "rosbag2_storage_mcap_testdata/srv/BasicSrv_Request";
}

template<>
struct has_fixed_size<rosbag2_storage_mcap_testdata::srv::BasicSrv_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rosbag2_storage_mcap_testdata::srv::BasicSrv_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rosbag2_storage_mcap_testdata::srv::BasicSrv_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosbag2_storage_mcap_testdata
{

namespace srv
{

inline void to_flow_style_yaml(
  const BasicSrv_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: resp
  {
    out << "resp: ";
    rosidl_generator_traits::value_to_yaml(msg.resp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BasicSrv_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: resp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "resp: ";
    rosidl_generator_traits::value_to_yaml(msg.resp, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BasicSrv_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace rosbag2_storage_mcap_testdata

namespace rosidl_generator_traits
{

[[deprecated("use rosbag2_storage_mcap_testdata::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rosbag2_storage_mcap_testdata::srv::BasicSrv_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  rosbag2_storage_mcap_testdata::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rosbag2_storage_mcap_testdata::srv::to_yaml() instead")]]
inline std::string to_yaml(const rosbag2_storage_mcap_testdata::srv::BasicSrv_Response & msg)
{
  return rosbag2_storage_mcap_testdata::srv::to_yaml(msg);
}

template<>
inline const char * data_type<rosbag2_storage_mcap_testdata::srv::BasicSrv_Response>()
{
  return "rosbag2_storage_mcap_testdata::srv::BasicSrv_Response";
}

template<>
inline const char * name<rosbag2_storage_mcap_testdata::srv::BasicSrv_Response>()
{
  return "rosbag2_storage_mcap_testdata/srv/BasicSrv_Response";
}

template<>
struct has_fixed_size<rosbag2_storage_mcap_testdata::srv::BasicSrv_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rosbag2_storage_mcap_testdata::srv::BasicSrv_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rosbag2_storage_mcap_testdata::srv::BasicSrv_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<rosbag2_storage_mcap_testdata::srv::BasicSrv>()
{
  return "rosbag2_storage_mcap_testdata::srv::BasicSrv";
}

template<>
inline const char * name<rosbag2_storage_mcap_testdata::srv::BasicSrv>()
{
  return "rosbag2_storage_mcap_testdata/srv/BasicSrv";
}

template<>
struct has_fixed_size<rosbag2_storage_mcap_testdata::srv::BasicSrv>
  : std::integral_constant<
    bool,
    has_fixed_size<rosbag2_storage_mcap_testdata::srv::BasicSrv_Request>::value &&
    has_fixed_size<rosbag2_storage_mcap_testdata::srv::BasicSrv_Response>::value
  >
{
};

template<>
struct has_bounded_size<rosbag2_storage_mcap_testdata::srv::BasicSrv>
  : std::integral_constant<
    bool,
    has_bounded_size<rosbag2_storage_mcap_testdata::srv::BasicSrv_Request>::value &&
    has_bounded_size<rosbag2_storage_mcap_testdata::srv::BasicSrv_Response>::value
  >
{
};

template<>
struct is_service<rosbag2_storage_mcap_testdata::srv::BasicSrv>
  : std::true_type
{
};

template<>
struct is_service_request<rosbag2_storage_mcap_testdata::srv::BasicSrv_Request>
  : std::true_type
{
};

template<>
struct is_service_response<rosbag2_storage_mcap_testdata::srv::BasicSrv_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROSBAG2_STORAGE_MCAP_TESTDATA__SRV__DETAIL__BASIC_SRV__TRAITS_HPP_
