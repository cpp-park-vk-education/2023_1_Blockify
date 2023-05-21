cmake_minimum_required(VERSION 3.0.0) 

add_executable(prod main.cpp cube.cpp cube.hpp)

target_link_libraries(prod freeglut_static libglew_static glfw glm)   