cmake_minimum_required (VERSION 2.8)

project (data)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -std=c++11")

aux_source_directory(./src/ SRC)


include_directories(./src/include)
add_library(data STATIC ${SRC})


# TODO: Only enable testing when certain variable is set
enable_testing()

option(BUILD_GTEST "Builds the googletest subproject" ON)
option(BUILD_GMOCK "Builds the googlemock subproject" OFF)
if(MSVC)
  option(BUILD_SHARED_LIBS "Build shared libraries (DLLs)." ON)
endif()
add_subdirectory(./external/gtest/)

include_directories(./external/gtest/googletest/include)
add_subdirectory(./tests)
add_test (NAME TestAll COMMAND test_all)
