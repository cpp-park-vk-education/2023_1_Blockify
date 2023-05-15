set(PROJECT_SOURCES
${VoxelEngine_SOURCE_DIR}/include/view/mainwindow.h
mainwindow.cpp
mainwindow.ui
ObjectFactory.cpp
)
set(HEADERS
${VoxelEngine_SOURCE_DIR}/include
${VoxelEngine_SOURCE_DIR}/include/view
${VoxelEngine_SOURCE_DIR}/include/view/StateManager
${VoxelEngine_SOURCE_DIR}/include/view/StateManager/Operation
${VoxelEngine_SOURCE_DIR}/include/view/ObjectTable
${VoxelEngine_SOURCE_DIR}/include/view/ObjectDrawer)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

add_library(view STATIC ${PROJECT_SOURCES})
target_link_libraries(view PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_include_directories(view PUBLIC ${HEADERS})

add_subdirectory(StateManager)
add_subdirectory(ObjectTable)
add_subdirectory(ObjectDrawer)
