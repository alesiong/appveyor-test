cmake_minimum_required (VERSION 2.8)


aux_source_directory(./ TESTS)

add_executable(test_all ${TESTS})
target_link_libraries(test_all gtest gtest_main data)

if(MSVC)
  add_custom_command(
    TARGET test_all POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_CURRENT_BINARY_DIR}/../external/gtest/googletest/$<CONFIG>/gtest.dll
            ${CMAKE_CURRENT_BINARY_DIR}/gtest.dll)
endif()
