// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rosbag2_storage_mcap_testdata:srv\BasicSrv.idl
// generated code does not contain a copyright notice

#ifndef ROSBAG2_STORAGE_MCAP_TESTDATA__SRV__DETAIL__BASIC_SRV__STRUCT_HPP_
#define ROSBAG2_STORAGE_MCAP_TESTDATA__SRV__DETAIL__BASIC_SRV__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rosbag2_storage_mcap_testdata__srv__BasicSrv_Request __attribute__((deprecated))
#else
# define DEPRECATED__rosbag2_storage_mcap_testdata__srv__BasicSrv_Request __declspec(deprecated)
#endif

namespace rosbag2_storage_mcap_testdata
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct BasicSrv_Request_
{
  using Type = BasicSrv_Request_<ContainerAllocator>;

  explicit BasicSrv_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->req = "";
    }
  }

  explicit BasicSrv_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : req(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->req = "";
    }
  }

  // field types and members
  using _req_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _req_type req;

  // setters for named parameter idiom
  Type & set__req(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->req = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rosbag2_storage_mcap_testdata::srv::BasicSrv_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const rosbag2_storage_mcap_testdata::srv::BasicSrv_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rosbag2_storage_mcap_testdata::srv::BasicSrv_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rosbag2_storage_mcap_testdata::srv::BasicSrv_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rosbag2_storage_mcap_testdata::srv::BasicSrv_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rosbag2_storage_mcap_testdata::srv::BasicSrv_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rosbag2_storage_mcap_testdata::srv::BasicSrv_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rosbag2_storage_mcap_testdata::srv::BasicSrv_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rosbag2_storage_mcap_testdata::srv::BasicSrv_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rosbag2_storage_mcap_testdata::srv::BasicSrv_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rosbag2_storage_mcap_testdata__srv__BasicSrv_Request
    std::shared_ptr<rosbag2_storage_mcap_testdata::srv::BasicSrv_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rosbag2_storage_mcap_testdata__srv__BasicSrv_Request
    std::shared_ptr<rosbag2_storage_mcap_testdata::srv::BasicSrv_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BasicSrv_Request_ & other) const
  {
    if (this->req != other.req) {
      return false;
    }
    return true;
  }
  bool operator!=(const BasicSrv_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BasicSrv_Request_

// alias to use template instance with default allocator
using BasicSrv_Request =
  rosbag2_storage_mcap_testdata::srv::BasicSrv_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace rosbag2_storage_mcap_testdata


#ifndef _WIN32
# define DEPRECATED__rosbag2_storage_mcap_testdata__srv__BasicSrv_Response __attribute__((deprecated))
#else
# define DEPRECATED__rosbag2_storage_mcap_testdata__srv__BasicSrv_Response __declspec(deprecated)
#endif

namespace rosbag2_storage_mcap_testdata
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct BasicSrv_Response_
{
  using Type = BasicSrv_Response_<ContainerAllocator>;

  explicit BasicSrv_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->resp = "";
    }
  }

  explicit BasicSrv_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : resp(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->resp = "";
    }
  }

  // field types and members
  using _resp_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _resp_type resp;

  // setters for named parameter idiom
  Type & set__resp(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->resp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rosbag2_storage_mcap_testdata::srv::BasicSrv_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const rosbag2_storage_mcap_testdata::srv::BasicSrv_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rosbag2_storage_mcap_testdata::srv::BasicSrv_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rosbag2_storage_mcap_testdata::srv::BasicSrv_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rosbag2_storage_mcap_testdata::srv::BasicSrv_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rosbag2_storage_mcap_testdata::srv::BasicSrv_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rosbag2_storage_mcap_testdata::srv::BasicSrv_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rosbag2_storage_mcap_testdata::srv::BasicSrv_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rosbag2_storage_mcap_testdata::srv::BasicSrv_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rosbag2_storage_mcap_testdata::srv::BasicSrv_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rosbag2_storage_mcap_testdata__srv__BasicSrv_Response
    std::shared_ptr<rosbag2_storage_mcap_testdata::srv::BasicSrv_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rosbag2_storage_mcap_testdata__srv__BasicSrv_Response
    std::shared_ptr<rosbag2_storage_mcap_testdata::srv::BasicSrv_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BasicSrv_Response_ & other) const
  {
    if (this->resp != other.resp) {
      return false;
    }
    return true;
  }
  bool operator!=(const BasicSrv_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BasicSrv_Response_

// alias to use template instance with default allocator
using BasicSrv_Response =
  rosbag2_storage_mcap_testdata::srv::BasicSrv_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace rosbag2_storage_mcap_testdata

namespace rosbag2_storage_mcap_testdata
{

namespace srv
{

struct BasicSrv
{
  using Request = rosbag2_storage_mcap_testdata::srv::BasicSrv_Request;
  using Response = rosbag2_storage_mcap_testdata::srv::BasicSrv_Response;
};

}  // namespace srv

}  // namespace rosbag2_storage_mcap_testdata

#endif  // ROSBAG2_STORAGE_MCAP_TESTDATA__SRV__DETAIL__BASIC_SRV__STRUCT_HPP_
