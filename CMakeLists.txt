cmake_minimum_required(VERSION 3.0.0)
project(prod VERSION 0.1.0)

add_subdirectory(glfw)
add_subdirectory(glew)
add_subdirectory(glm)
add_subdirectory(freeglut-3.4.0)
add_subdirectory(prod)

target_include_directories(prod PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/glew/include)
target_include_directories(prod PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/glfw/include)
target_include_directories(prod PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/freeglut-3.4.0/include)

include(CTest)
enable_testing()



set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
