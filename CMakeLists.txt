cmake_minimum_required (VERSION 2.8)

project (data)

if(MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W4 -wd4244 -wd4267 -wd4800 -wd4068 -MP")
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Zi -Od")
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Ox")
  add_definitions(-DUNICODE -D_UNICODE)
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wfloat-equal -std=c++11")
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
endif()

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
