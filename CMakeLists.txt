#'using the findROOT from Karl Smith'
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project (My_project ) 
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -w")
add_definitions(-std=c++11)


# this section is for CERN's setup.-------------------------------------------
    #Add custom modules to module path
    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

    include(${CMAKE_MODULE_PATH}/ExportDYLD.cmake)

    CheckForExportDYLD()

    #Find the ROOT package and configure the flags and paths
    find_package ( ROOT REQUIRED )
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
    set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ROOT_CXX_FLAGS} -fPIC" )
    include_directories( ${ROOT_INCLUDE_DIR} )
    link_directories( ${ROOT_LIBRARY_DIR} )
#----------------------------------------------------------------------------



#---Create  a main program using the library
add_executable( main main.cpp)
target_link_libraries( main ${ROOT_LIBRARIES} )
