cmake_minimum_required (VERSION 2.8)


aux_source_directory(./ TESTS)

include_directories(../include)

add_executable(test_all ${TESTS})
target_link_libraries(test_all gtest gtest_main data)

