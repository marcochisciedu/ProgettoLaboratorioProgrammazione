project(Google_tests)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES TestCorrectTime.cpp)
add_executable(Google_Tests_run ${TEST_SOURCE_FILES})
target_link_libraries(Google_Tests_run gtest gtest_main core)