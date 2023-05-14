add_subdirectory(StateManager)


add_executable(VoxelEngine main.cpp)
target_link_libraries(VoxelEngine statemanager)
