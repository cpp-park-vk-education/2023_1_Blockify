add_subdirectory(view)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

add_executable(VoxelEngine main.cpp)
target_link_libraries(VoxelEngine PRIVATE view Qt${QT_VERSION_MAJOR}::Widgets)
target_include_directories(VoxelEngine PUBLIC view)
