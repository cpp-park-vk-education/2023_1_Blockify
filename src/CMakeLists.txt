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
