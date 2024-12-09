// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rosbag2_storage_mcap_testdata:msg\BasicMsg.idl
// generated code does not contain a copyright notice

#ifndef ROSBAG2_STORAGE_MCAP_TESTDATA__MSG__DETAIL__BASIC_MSG__BUILDER_HPP_
#define ROSBAG2_STORAGE_MCAP_TESTDATA__MSG__DETAIL__BASIC_MSG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rosbag2_storage_mcap_testdata/msg/detail/basic_msg__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rosbag2_storage_mcap_testdata
{

namespace msg
{

namespace builder
{

class Init_BasicMsg_c
{
public:
  Init_BasicMsg_c()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rosbag2_storage_mcap_testdata::msg::BasicMsg c(::rosbag2_storage_mcap_testdata::msg::BasicMsg::_c_type arg)
  {
    msg_.c = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_storage_mcap_testdata::msg::BasicMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_storage_mcap_testdata::msg::BasicMsg>()
{
  return rosbag2_storage_mcap_testdata::msg::builder::Init_BasicMsg_c();
}

}  // namespace rosbag2_storage_mcap_testdata

#endif  // ROSBAG2_STORAGE_MCAP_TESTDATA__MSG__DETAIL__BASIC_MSG__BUILDER_HPP_
