// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rosbag2_storage_mcap_testdata:msg\ComplexIdl.idl
// generated code does not contain a copyright notice

#ifndef ROSBAG2_STORAGE_MCAP_TESTDATA__MSG__DETAIL__COMPLEX_IDL__STRUCT_HPP_
#define ROSBAG2_STORAGE_MCAP_TESTDATA__MSG__DETAIL__COMPLEX_IDL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'a'
#include "rosbag2_storage_mcap_testdata/msg/detail/basic_idl__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__rosbag2_storage_mcap_testdata__msg__ComplexIdl __attribute__((deprecated))
#else
# define DEPRECATED__rosbag2_storage_mcap_testdata__msg__ComplexIdl __declspec(deprecated)
#endif

namespace rosbag2_storage_mcap_testdata
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ComplexIdl_
{
  using Type = ComplexIdl_<ContainerAllocator>;

  explicit ComplexIdl_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : a(_init)
  {
    (void)_init;
  }

  explicit ComplexIdl_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : a(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _a_type =
    rosbag2_storage_mcap_testdata::msg::BasicIdl_<ContainerAllocator>;
  _a_type a;

  // setters for named parameter idiom
  Type & set__a(
    const rosbag2_storage_mcap_testdata::msg::BasicIdl_<ContainerAllocator> & _arg)
  {
    this->a = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rosbag2_storage_mcap_testdata::msg::ComplexIdl_<ContainerAllocator> *;
  using ConstRawPtr =
    const rosbag2_storage_mcap_testdata::msg::ComplexIdl_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rosbag2_storage_mcap_testdata::msg::ComplexIdl_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rosbag2_storage_mcap_testdata::msg::ComplexIdl_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rosbag2_storage_mcap_testdata::msg::ComplexIdl_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rosbag2_storage_mcap_testdata::msg::ComplexIdl_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rosbag2_storage_mcap_testdata::msg::ComplexIdl_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rosbag2_storage_mcap_testdata::msg::ComplexIdl_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rosbag2_storage_mcap_testdata::msg::ComplexIdl_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rosbag2_storage_mcap_testdata::msg::ComplexIdl_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rosbag2_storage_mcap_testdata__msg__ComplexIdl
    std::shared_ptr<rosbag2_storage_mcap_testdata::msg::ComplexIdl_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rosbag2_storage_mcap_testdata__msg__ComplexIdl
    std::shared_ptr<rosbag2_storage_mcap_testdata::msg::ComplexIdl_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ComplexIdl_ & other) const
  {
    if (this->a != other.a) {
      return false;
    }
    return true;
  }
  bool operator!=(const ComplexIdl_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ComplexIdl_

// alias to use template instance with default allocator
using ComplexIdl =
  rosbag2_storage_mcap_testdata::msg::ComplexIdl_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rosbag2_storage_mcap_testdata

#endif  // ROSBAG2_STORAGE_MCAP_TESTDATA__MSG__DETAIL__COMPLEX_IDL__STRUCT_HPP_
