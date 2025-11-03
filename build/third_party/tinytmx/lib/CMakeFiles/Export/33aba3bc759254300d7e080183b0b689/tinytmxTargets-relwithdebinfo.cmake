#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "tinytmx::tinyxml2" for configuration "RelWithDebInfo"
set_property(TARGET tinytmx::tinyxml2 APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(tinytmx::tinyxml2 PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELWITHDEBINFO "CXX"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libtinyxml2.a"
  )

list(APPEND _cmake_import_check_targets tinytmx::tinyxml2 )
list(APPEND _cmake_import_check_files_for_tinytmx::tinyxml2 "${_IMPORT_PREFIX}/lib/libtinyxml2.a" )

# Import target "tinytmx::tinytmx" for configuration "RelWithDebInfo"
set_property(TARGET tinytmx::tinytmx APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(tinytmx::tinytmx PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELWITHDEBINFO "CXX"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libtinytmx.a"
  )

list(APPEND _cmake_import_check_targets tinytmx::tinytmx )
list(APPEND _cmake_import_check_files_for_tinytmx::tinytmx "${_IMPORT_PREFIX}/lib/libtinytmx.a" )

# Import target "tinytmx::libzstd_static" for configuration "RelWithDebInfo"
set_property(TARGET tinytmx::libzstd_static APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(tinytmx::libzstd_static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELWITHDEBINFO "C"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libzstd.a"
  )

list(APPEND _cmake_import_check_targets tinytmx::libzstd_static )
list(APPEND _cmake_import_check_files_for_tinytmx::libzstd_static "${_IMPORT_PREFIX}/lib/libzstd.a" )

# Import target "tinytmx::zlibstatic" for configuration "RelWithDebInfo"
set_property(TARGET tinytmx::zlibstatic APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(tinytmx::zlibstatic PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELWITHDEBINFO "C"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libzlibstatic.a"
  )

list(APPEND _cmake_import_check_targets tinytmx::zlibstatic )
list(APPEND _cmake_import_check_files_for_tinytmx::zlibstatic "${_IMPORT_PREFIX}/lib/libzlibstatic.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
