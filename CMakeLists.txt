cmake_minimum_required(VERSION 3.3)
project(triss)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES core/main.cpp core/SystemParserInfo.cpp core/SystemParserInfo.h)
add_executable(triss ${SOURCE_FILES})