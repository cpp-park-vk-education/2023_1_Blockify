cmake_minimum_required(VERSION 3.0)

project(VoxelEngine VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
option(BUILD_TESTS "Conditional test build" ON)

enable_testing()
add_subdirectory(src)

