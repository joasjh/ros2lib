#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rosbag2_storage_mcap::rosbag2_storage_mcap" for configuration "RelWithDebInfo"
set_property(TARGET rosbag2_storage_mcap::rosbag2_storage_mcap APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(rosbag2_storage_mcap::rosbag2_storage_mcap PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/rosbag2_storage_mcap.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/rosbag2_storage_mcap.dll"
  )

list(APPEND _cmake_import_check_targets rosbag2_storage_mcap::rosbag2_storage_mcap )
list(APPEND _cmake_import_check_files_for_rosbag2_storage_mcap::rosbag2_storage_mcap "${_IMPORT_PREFIX}/lib/rosbag2_storage_mcap.lib" "${_IMPORT_PREFIX}/bin/rosbag2_storage_mcap.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
