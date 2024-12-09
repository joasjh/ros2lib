// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rosbag2_storage_mcap_testdata:msg\ComplexMsgDependsOnIdl.idl
// generated code does not contain a copyright notice

#ifndef ROSBAG2_STORAGE_MCAP_TESTDATA__MSG__DETAIL__COMPLEX_MSG_DEPENDS_ON_IDL__BUILDER_HPP_
#define ROSBAG2_STORAGE_MCAP_TESTDATA__MSG__DETAIL__COMPLEX_MSG_DEPENDS_ON_IDL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rosbag2_storage_mcap_testdata/msg/detail/complex_msg_depends_on_idl__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rosbag2_storage_mcap_testdata
{

namespace msg
{

namespace builder
{

class Init_ComplexMsgDependsOnIdl_a
{
public:
  Init_ComplexMsgDependsOnIdl_a()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rosbag2_storage_mcap_testdata::msg::ComplexMsgDependsOnIdl a(::rosbag2_storage_mcap_testdata::msg::ComplexMsgDependsOnIdl::_a_type arg)
  {
    msg_.a = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_storage_mcap_testdata::msg::ComplexMsgDependsOnIdl msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_storage_mcap_testdata::msg::ComplexMsgDependsOnIdl>()
{
  return rosbag2_storage_mcap_testdata::msg::builder::Init_ComplexMsgDependsOnIdl_a();
}

}  // namespace rosbag2_storage_mcap_testdata

#endif  // ROSBAG2_STORAGE_MCAP_TESTDATA__MSG__DETAIL__COMPLEX_MSG_DEPENDS_ON_IDL__BUILDER_HPP_
