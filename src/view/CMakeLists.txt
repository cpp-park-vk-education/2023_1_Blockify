set(PROJECT_SOURCES
${VoxelEngine_SOURCE_DIR}/include/mainwindow.h
mainwindow.cpp
mainwindow.ui
ObjectFactory.cpp
)
set(HEADERS
${VoxelEngine_SOURCE_DIR}/include
${VoxelEngine_SOURCE_DIR}/include/StateManager
${VoxelEngine_SOURCE_DIR}/include/StateManager/Operation
${VoxelEngine_SOURCE_DIR}/include/ObjectTable
${VoxelEngine_SOURCE_DIR}/include/ObjectDrawer)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

add_library(view STATIC ${PROJECT_SOURCES})
target_link_libraries(view PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_include_directories(view PUBLIC ${HEADERS})

add_subdirectory(StateManager)
