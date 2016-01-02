cmake_minimum_required(VERSION 3.3)
project(triss)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Source/parser/AbstractSystemParser.cpp Headers/parcer/AbstractSystemParser.h Source/parser/MemInfoParser.cpp Headers/parcer/MemInfoParser.h Source/parser/CpuInfoParser.cpp Headers/parcer/CpuInfoParser.h Source/parser/ParseExecutor.cpp Headers/parcer/ParseExecutor.h Source/parser/UserInfoParser.cpp Headers/parcer/UserInfoParser.h Source/parser/PIDParser.cpp Headers/parcer/PIDParser.h)
add_executable(triss ${SOURCE_FILES})