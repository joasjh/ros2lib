#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "ignition-math6::ignition-math6" for configuration "RelWithDebInfo"
set_property(TARGET ignition-math6::ignition-math6 APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(ignition-math6::ignition-math6 PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/ignition-math6.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/ignition-math6.dll"
  )

list(APPEND _cmake_import_check_targets ignition-math6::ignition-math6 )
list(APPEND _cmake_import_check_files_for_ignition-math6::ignition-math6 "${_IMPORT_PREFIX}/lib/ignition-math6.lib" "${_IMPORT_PREFIX}/bin/ignition-math6.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
