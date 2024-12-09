// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rosbag2_storage_mcap_testdata:msg\ComplexIdl.idl
// generated code does not contain a copyright notice

#ifndef ROSBAG2_STORAGE_MCAP_TESTDATA__MSG__DETAIL__COMPLEX_IDL__BUILDER_HPP_
#define ROSBAG2_STORAGE_MCAP_TESTDATA__MSG__DETAIL__COMPLEX_IDL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rosbag2_storage_mcap_testdata/msg/detail/complex_idl__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rosbag2_storage_mcap_testdata
{

namespace msg
{

namespace builder
{

class Init_ComplexIdl_a
{
public:
  Init_ComplexIdl_a()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rosbag2_storage_mcap_testdata::msg::ComplexIdl a(::rosbag2_storage_mcap_testdata::msg::ComplexIdl::_a_type arg)
  {
    msg_.a = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_storage_mcap_testdata::msg::ComplexIdl msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_storage_mcap_testdata::msg::ComplexIdl>()
{
  return rosbag2_storage_mcap_testdata::msg::builder::Init_ComplexIdl_a();
}

}  // namespace rosbag2_storage_mcap_testdata

#endif  // ROSBAG2_STORAGE_MCAP_TESTDATA__MSG__DETAIL__COMPLEX_IDL__BUILDER_HPP_
