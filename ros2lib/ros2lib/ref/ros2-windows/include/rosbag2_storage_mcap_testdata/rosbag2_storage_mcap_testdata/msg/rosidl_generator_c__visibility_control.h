// generated from rosidl_generator_c/resource/rosidl_generator_c__visibility_control.h.in
// generated code does not contain a copyright notice

#ifndef ROSBAG2_STORAGE_MCAP_TESTDATA__MSG__ROSIDL_GENERATOR_C__VISIBILITY_CONTROL_H_
#define ROSBAG2_STORAGE_MCAP_TESTDATA__MSG__ROSIDL_GENERATOR_C__VISIBILITY_CONTROL_H_

#ifdef __cplusplus
extern "C"
{
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ROSIDL_GENERATOR_C_EXPORT_rosbag2_storage_mcap_testdata __attribute__ ((dllexport))
    #define ROSIDL_GENERATOR_C_IMPORT_rosbag2_storage_mcap_testdata __attribute__ ((dllimport))
  #else
    #define ROSIDL_GENERATOR_C_EXPORT_rosbag2_storage_mcap_testdata __declspec(dllexport)
    #define ROSIDL_GENERATOR_C_IMPORT_rosbag2_storage_mcap_testdata __declspec(dllimport)
  #endif
  #ifdef ROSIDL_GENERATOR_C_BUILDING_DLL_rosbag2_storage_mcap_testdata
    #define ROSIDL_GENERATOR_C_PUBLIC_rosbag2_storage_mcap_testdata ROSIDL_GENERATOR_C_EXPORT_rosbag2_storage_mcap_testdata
  #else
    #define ROSIDL_GENERATOR_C_PUBLIC_rosbag2_storage_mcap_testdata ROSIDL_GENERATOR_C_IMPORT_rosbag2_storage_mcap_testdata
  #endif
#else
  #define ROSIDL_GENERATOR_C_EXPORT_rosbag2_storage_mcap_testdata __attribute__ ((visibility("default")))
  #define ROSIDL_GENERATOR_C_IMPORT_rosbag2_storage_mcap_testdata
  #if __GNUC__ >= 4
    #define ROSIDL_GENERATOR_C_PUBLIC_rosbag2_storage_mcap_testdata __attribute__ ((visibility("default")))
  #else
    #define ROSIDL_GENERATOR_C_PUBLIC_rosbag2_storage_mcap_testdata
  #endif
#endif

#ifdef __cplusplus
}
#endif

#endif  // ROSBAG2_STORAGE_MCAP_TESTDATA__MSG__ROSIDL_GENERATOR_C__VISIBILITY_CONTROL_H_
