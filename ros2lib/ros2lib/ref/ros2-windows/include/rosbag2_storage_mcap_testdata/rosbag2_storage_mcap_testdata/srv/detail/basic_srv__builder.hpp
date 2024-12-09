// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rosbag2_storage_mcap_testdata:srv\BasicSrv.idl
// generated code does not contain a copyright notice

#ifndef ROSBAG2_STORAGE_MCAP_TESTDATA__SRV__DETAIL__BASIC_SRV__BUILDER_HPP_
#define ROSBAG2_STORAGE_MCAP_TESTDATA__SRV__DETAIL__BASIC_SRV__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rosbag2_storage_mcap_testdata/srv/detail/basic_srv__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rosbag2_storage_mcap_testdata
{

namespace srv
{

namespace builder
{

class Init_BasicSrv_Request_req
{
public:
  Init_BasicSrv_Request_req()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rosbag2_storage_mcap_testdata::srv::BasicSrv_Request req(::rosbag2_storage_mcap_testdata::srv::BasicSrv_Request::_req_type arg)
  {
    msg_.req = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_storage_mcap_testdata::srv::BasicSrv_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_storage_mcap_testdata::srv::BasicSrv_Request>()
{
  return rosbag2_storage_mcap_testdata::srv::builder::Init_BasicSrv_Request_req();
}

}  // namespace rosbag2_storage_mcap_testdata


namespace rosbag2_storage_mcap_testdata
{

namespace srv
{

namespace builder
{

class Init_BasicSrv_Response_resp
{
public:
  Init_BasicSrv_Response_resp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rosbag2_storage_mcap_testdata::srv::BasicSrv_Response resp(::rosbag2_storage_mcap_testdata::srv::BasicSrv_Response::_resp_type arg)
  {
    msg_.resp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rosbag2_storage_mcap_testdata::srv::BasicSrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rosbag2_storage_mcap_testdata::srv::BasicSrv_Response>()
{
  return rosbag2_storage_mcap_testdata::srv::builder::Init_BasicSrv_Response_resp();
}

}  // namespace rosbag2_storage_mcap_testdata

#endif  // ROSBAG2_STORAGE_MCAP_TESTDATA__SRV__DETAIL__BASIC_SRV__BUILDER_HPP_
