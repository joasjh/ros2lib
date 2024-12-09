# Genderated by GenCmakeLists.py

cmake_minimum_required(VERSION 3.5)
project(ros2libTester)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set var
set(ROS2LIB_PROJ_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/../ros2lib)
set(ROS2LIB_LIB_FILE_DIRS ${ROS2LIB_PROJ_DIRS}/build/Release)
set(ROS2LIB_INCLUDE_DIRS ${ROS2LIB_PROJ_DIRS}/include)
set(CUSTOM_PKG_NAME test_msgs)

# Add ROS Essential pkg
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
# Add Custom Msg pkg
find_package(${CUSTOM_PKG_NAME} REQUIRED)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

file(GLOB_RECURSE PROJECT_HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
file(GLOB_RECURSE PROJECT_SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

set(ProjectExecutable main)

add_executable(${ProjectExecutable}
  ${PROJECT_HEADER_FILES}
  ${PROJECT_SOURCE_FILES}
)

target_link_libraries(${ProjectExecutable} 
  ${ROS2LIB_LIB_FILE_DIRS}/ros2lib.lib
)

target_include_directories(${ProjectExecutable} PUBLIC
  ${ROS2LIB_INCLUDE_DIRS}
)

ament_target_dependencies(${ProjectExecutable}
  rclcpp
  ${CUSTOM_PKG_NAME} 
)

ament_package()