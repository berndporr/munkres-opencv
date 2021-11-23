cmake_minimum_required(VERSION 3.1.0)
include(FetchContent)

cmake_policy(SET CMP0048 NEW) # set VERSION in project()
cmake_policy(SET CMP0042 NEW) # enable MACOSX_RPATH by default

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
	set(CMAKE_BUILD_TYPE "RelWithDebInfo")
endif()

project(Munkres VERSION 1.0.0 LANGUAGES CXX)
include(GNUInstallDirs)
set(CMAKE_CXX_STANDARD 11)

add_compile_options(-Wall)

find_package (OpenCV)

include_directories( src ${OpenCV_INCLUDE_DIRS} )

add_library(munkres STATIC src/munkres.cpp)

target_include_directories(munkres
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
)

set_target_properties(munkres PROPERTIES
  POSITION_INDEPENDENT_CODE TRUE
  VERSION ${PROJECT_VERSION}
  PUBLIC_HEADER src/munkres.h
)

install(TARGETS munkres EXPORT munkres-targets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/src
  INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  )

install(EXPORT munkres-targets
  DESTINATION lib/cmake/munkres
  FILE munkres-config.cmake
)

add_executable (demo demo.cpp)
target_link_libraries(demo munkres ${OpenCV_LIBS})
