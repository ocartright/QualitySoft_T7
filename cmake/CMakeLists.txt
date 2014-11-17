cmake_minimum_required ( VERSION 2.8 )
project ( QualitySoft )

set ( CMAKE_CXX_FLAGS_DEBUG on )

include_directories ( ${CMAKE_CURRENT_SOURCE_DIR}/../source ) #todo: add dependencies

add_definitions ( -std=c++11 )

file ( GLOB SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/../source/* )

add_executable ( application ${SOURCE} )

#todo: link dependencies
