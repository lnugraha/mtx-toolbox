cmake_minimum_required(VERSION 3.13)
project(Boost_BLAS_Operations)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O0 -Wall")

find_package(Boost REQUIRED)
find_package(GTest REQUIRED)
include_directories("${GTEST_INCLUDE_DIRS}")
include_directories("${Boost_INCLUDE_DIRS}")
include_directories("../../include")

add_definitions(-DHAVE_CONFIG_H)
add_definitions(-DSOURCE_CODE_LOCAION="${CMAKE_SOURCE_DIR}")

file(GLOB SOURCE_FILES "../../src/*.cpp")
add_executable(main ${SOURCE_FILES} main.cpp)
target_link_libraries(main ${Boost_LIBRARIES} ${GTEST_LIBRARIES} pthread)

