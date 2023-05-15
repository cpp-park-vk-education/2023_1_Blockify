add_subdirectory(view)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

add_executable(VoxelEngine main.cpp)
target_link_libraries(VoxelEngine PRIVATE view Qt${QT_VERSION_MAJOR}::Widgets)
target_include_directories(VoxelEngine PUBLIC view)

aux_source_directory(Image ImageSource)
aux_source_directory(Scene SceneSource)
aux_source_directory(ObjectPlacer ObjectPlacerSource)

add_library(VoxelEngineFunctionLib ${ImageSource} ${SceneSource} ${ObjectPlacerSource})
target_include_directories(VoxelEngineFunctionLib PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(main main.cpp)
target_link_libraries(main PUBLIC VoxelEngineFunctionLib png)

if(BUILD_TESTS)
    find_package(GTest REQUIRED)
    add_subdirectory(tests)
endif()
