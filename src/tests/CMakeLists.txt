add_executable(SceneTests SceneTests.cpp)
target_include_directories(SceneTests PRIVATE ${PROJECT_SOURCE_DIR}/lib/googletest/googletest/include ${PROJECT_SOURCE_DIR}/lib/googletest/googlemock/include)
target_link_libraries(SceneTests VoxelEngineFunctionLib gtest gtest_main gmock gmock_main pthread)
add_test(SceneTestCase SceneTests)

add_executable(ObjectPlacerTests ObjectPlacerTests.cpp)
target_include_directories(SceneTests PRIVATE ${PROJECT_SOURCE_DIR}/lib/googletest/googletest/include ${PROJECT_SOURCE_DIR}/lib/googletest/googlemock/include)
target_link_libraries(ObjectPlacerTests VoxelEngineFunctionLib gtest gtest_main gmock gmock_main pthread)
add_test(ObjectPlacerTestCase ObjectPlacerTests)
