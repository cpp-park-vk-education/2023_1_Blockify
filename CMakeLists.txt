cmake_minimum_required(VERSION 3.0)

project(VoxelEngine VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
option(BUILD_TESTS "Conditional test build" ON)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(lib/googletest)
endif()

add_subdirectory(src)

