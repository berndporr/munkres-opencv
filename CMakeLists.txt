cmake_minimum_required(VERSION 3.1.0)
include(FetchContent)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
	set(CMAKE_BUILD_TYPE "RelWithDebInfo")
endif()

project(Munkres LANGUAGES CXX)
include(GNUInstallDirs)
set(CMAKE_CXX_STANDARD 11)

add_compile_options(-Wall)

find_package (OpenCV)

include_directories( src ${OpenCV_INCLUDE_DIRS} )

add_executable (munkres src/main.cpp src/munkres.cpp)
target_link_libraries(munkres ${OpenCV_LIBS})
