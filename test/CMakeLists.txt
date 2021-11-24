cmake_minimum_required(VERSION 3.1.0)

project(Munkres-opencv-test LANGUAGES CXX)
include(GNUInstallDirs)
set(CMAKE_CXX_STANDARD 11)

add_compile_options(-Wall)

enable_testing()

find_package (OpenCV)

include_directories( ../src ${OpenCV_INCLUDE_DIRS} )

add_executable (test_pass test_pass.cpp)
target_link_libraries(test_pass munkres-opencv ${OpenCV_LIBS})
add_test(TestPass test_pass)
