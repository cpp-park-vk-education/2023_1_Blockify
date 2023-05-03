aux_source_directory(Scene SceneSource)
aux_source_directory(ObjectPlacer ObjectPlacerSource)

add_library(VoxelEngineFunctionLib ${SceneSource} ${ObjectPlacerSource})
target_include_directories(VoxelEngineFunctionLib PUBLIC ${PROJECT_SOURCE_DIR}/include)

if(BUILD_TESTS)
#    find_package(GTest REQUIRED)
    add_subdirectory(tests)
endif()
