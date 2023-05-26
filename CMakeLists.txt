cmake_minimum_required(VERSION 3.0.0)
project(prod VERSION 0.1.0)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(glfw3 3.3 REQUIRED)

add_executable(prod prod/main.cpp prod/cube.cpp prod/cube.hpp)

# Еще требуется установка glm
target_include_directories(prod PUBLIC ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS})
target_link_libraries(prod glfw ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})


