cmake_minimum_required(VERSION 3.13)
project(IntelMKL_BLAS_Operations)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O0 -Wall")

find_package(GTest REQUIRED)
include_directories("${GTEST_INCLUDE_DIRS}")
include_directories(${BLA_INCLUDE_DIR})
include_directories("../../include")

add_definitions(-DHAVE_CONFIG_H)
add_definitions(-DSOURCE_CODE_LOCAION="${CMAKE_SOURCE_DIR}")

if ("$ENV{MKLROOT}" STREQUAL "")
  message(FATAL_ERROR "MKLROOT is not set. Please source the Intel MKL mklvars.sh file.")
endif()

option(MKL_USE_parallel "Use MKL parallel" True)
option(MKL_USE_sdl "Single Dynamic Library or static/dynamic" False)
set(MKL_USE_interface "lp64" CACHE STRING "for Intel(R)64 compatible arch: ilp64/lp64 or for ia32 arch: cdecl/stdcall")
                                                                                
if (BLA_VENDOR MATCHES "_seq")
  set(MKL_USE_parallel OFF)                                                   
else()
  set(MKL_USE_parallel ON)                                                    
endif()                                                                         
                                                                                
find_package(MKL REQUIRED)

if (MKL_FOUND)
  set(BLA_INCLUDE_DIR ${MKL_INCLUDE_DIR})
  set(BLAS_LIBRARIES ${MKL_LIBRARIES})
  set(BLA_DEFINITIONS USE_MKL)                                                
endif()

file(GLOB SOURCE_FILES "../../src/*.cpp")

message(STATUS "BLAS Libraries: ${BLAS_LIBRARIES}")
add_executable(main ${SOURCE_FILES} main.cpp)
target_link_libraries(main ${GTEST_LIBRARIES} pthread)

# target_link_libraries(main "-Wl,--start-group" ${MKL_LIBRARIES} "-Wl,--end-group" ${GTEST_LIBRARIES} pthread)


