cmake_minimum_required(VERSION 3.13)
project(BOOST_UNIT_TEST)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

find_package(Boost COMPONENTS filesystem system unit_test_framework REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(BOOST_TEST main.cpp)
target_link_libraries(BOOST_TEST ${Boost_LIBRARIES} 
  ${Boost_FILESYSTEM_LIBRARY}
  ${Boost_SYSTEM_LIBRARY} 
  ${Boost_UINT_TEST_FRAMEWORK_LIBRARY}) 

