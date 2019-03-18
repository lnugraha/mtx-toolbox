cmake_minimum_required(VERSION 3.12)

# name of the cpp project
project(MATRIX)

# set cpp flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# include all necessary header files
include_directories(${Boost_INCLUDE_DIRS})
include_directories(include)

# source files
set(SOURCE_FILES main.cpp)
file(GLOB SOURCES "src/*.cpp")

find_package(Boost 1.67 REQUIRED)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# set output executable of our test program
add_executable(MATRIX ${SOURCE_FILES} ${SOURCES})

# link library files
target_link_libraries(DICOM ${Boost_LIBRARIES})
