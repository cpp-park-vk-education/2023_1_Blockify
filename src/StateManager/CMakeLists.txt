set(HEADERS
${VoxelEngine_SOURCE_DIR}/include
${VoxelEngine_SOURCE_DIR}/include/StateManager
${VoxelEngine_SOURCE_DIR}/include/StateManager/Operation
${VoxelEngine_SOURCE_DIR}/include/ObjectTable
${VoxelEngine_SOURCE_DIR}/include/ObjectDrawer)

add_library(statemanager STATIC OperationStorage.cpp StateManager.cpp)
target_include_directories(statemanager PUBLIC ${HEADERS})
