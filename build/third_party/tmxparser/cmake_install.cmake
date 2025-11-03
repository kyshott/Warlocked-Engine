# Install script for directory: C:/Users/Kyle/Documents/Warlocked-Engine/third_party/tmxparser

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/Warlocked")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/mingw64/bin/objdump.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/tmxparser" TYPE FILE FILES
    "C:/Users/Kyle/Documents/Warlocked-Engine/build/third_party/tmxparser/Tmx.h"
    "C:/Users/Kyle/Documents/Warlocked-Engine/third_party/tmxparser/src/TmxColor.h"
    "C:/Users/Kyle/Documents/Warlocked-Engine/third_party/tmxparser/src/TmxEllipse.h"
    "C:/Users/Kyle/Documents/Warlocked-Engine/third_party/tmxparser/src/TmxGroupLayer.h"
    "C:/Users/Kyle/Documents/Warlocked-Engine/third_party/tmxparser/src/TmxImage.h"
    "C:/Users/Kyle/Documents/Warlocked-Engine/third_party/tmxparser/src/TmxImageLayer.h"
    "C:/Users/Kyle/Documents/Warlocked-Engine/third_party/tmxparser/src/TmxLayer.h"
    "C:/Users/Kyle/Documents/Warlocked-Engine/third_party/tmxparser/src/TmxMap.h"
    "C:/Users/Kyle/Documents/Warlocked-Engine/third_party/tmxparser/src/TmxMapTile.h"
    "C:/Users/Kyle/Documents/Warlocked-Engine/third_party/tmxparser/src/TmxObject.h"
    "C:/Users/Kyle/Documents/Warlocked-Engine/third_party/tmxparser/src/TmxObjectGroup.h"
    "C:/Users/Kyle/Documents/Warlocked-Engine/third_party/tmxparser/src/TmxPoint.h"
    "C:/Users/Kyle/Documents/Warlocked-Engine/third_party/tmxparser/src/TmxPolygon.h"
    "C:/Users/Kyle/Documents/Warlocked-Engine/third_party/tmxparser/src/TmxPolyline.h"
    "C:/Users/Kyle/Documents/Warlocked-Engine/third_party/tmxparser/src/TmxProperty.h"
    "C:/Users/Kyle/Documents/Warlocked-Engine/third_party/tmxparser/src/TmxPropertySet.h"
    "C:/Users/Kyle/Documents/Warlocked-Engine/third_party/tmxparser/src/TmxTerrain.h"
    "C:/Users/Kyle/Documents/Warlocked-Engine/third_party/tmxparser/src/TmxTerrainArray.h"
    "C:/Users/Kyle/Documents/Warlocked-Engine/third_party/tmxparser/src/TmxText.h"
    "C:/Users/Kyle/Documents/Warlocked-Engine/third_party/tmxparser/src/TmxTile.h"
    "C:/Users/Kyle/Documents/Warlocked-Engine/third_party/tmxparser/src/TmxTileLayer.h"
    "C:/Users/Kyle/Documents/Warlocked-Engine/third_party/tmxparser/src/TmxTileOffset.h"
    "C:/Users/Kyle/Documents/Warlocked-Engine/third_party/tmxparser/src/TmxTileset.h"
    "C:/Users/Kyle/Documents/Warlocked-Engine/third_party/tmxparser/src/TmxUtil.h"
    "C:/Users/Kyle/Documents/Warlocked-Engine/third_party/tmxparser/src/base64/base64.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/Kyle/Documents/Warlocked-Engine/build/third_party/tmxparser/libtmxparser.dll.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "C:/Users/Kyle/Documents/Warlocked-Engine/build/third_party/tmxparser/libtmxparser.dll")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libtmxparser.dll" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libtmxparser.dll")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "C:/mingw64/bin/strip.exe" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libtmxparser.dll")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  include("C:/Users/Kyle/Documents/Warlocked-Engine/build/third_party/tmxparser/CMakeFiles/tmxparser.dir/install-cxx-module-bmi-noconfig.cmake" OPTIONAL)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/Kyle/Documents/Warlocked-Engine/build/third_party/tmxparser/libtmxparser.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  include("C:/Users/Kyle/Documents/Warlocked-Engine/build/third_party/tmxparser/CMakeFiles/tmxparser_static.dir/install-cxx-module-bmi-noconfig.cmake" OPTIONAL)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "C:/Users/Kyle/Documents/Warlocked-Engine/build/third_party/tmxparser/tmxparser.pc")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "C:/Users/Kyle/Documents/Warlocked-Engine/build/third_party/tmxparser/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
