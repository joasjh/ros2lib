// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rosbag2_storage_mcap_testdata:msg\BasicIdl.idl
// generated code does not contain a copyright notice

#ifndef ROSBAG2_STORAGE_MCAP_TESTDATA__MSG__DETAIL__BASIC_IDL__BUILDER_HPP_
#define ROSBAG2_STORAGE_MCAP_TESTDATA__MSG__DETAIL__BASIC_IDL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rosbag2_storage_mcap_testdata/msg/detail/basic_idl__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rosbag2_storage_mcap_testdata
{

namespace msg
{

namespace builder
{

class Init_BasicIdl_x
{
public:
  Init_BasicIdl_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rosbag2_storage_mcap_testdata::msg::BasicIdl x(::rosbag2_storage_mcap_testdata::msg::BasicIdl::_x_type arg)
  {
    msg_.x = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_storage_mcap_testdata::msg::BasicIdl msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_storage_mcap_testdata::msg::BasicIdl>()
{
  return rosbag2_storage_mcap_testdata::msg::builder::Init_BasicIdl_x();
}

}  // namespace rosbag2_storage_mcap_testdata

#endif  // ROSBAG2_STORAGE_MCAP_TESTDATA__MSG__DETAIL__BASIC_IDL__BUILDER_HPP_
