set(LIB_SOURCES
    OperationStorage.cpp
    StateManager.cpp
)
target_sources(view PRIVATE ${LIB_SOURCES})
add_subdirectory(Operation)
