add_executable(VoxelEngine main.cpp)

if(BUILD_TESTS)
    find_package(GTest REQUIRED)
    add_subdirectory(tests)
endif()