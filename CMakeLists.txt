cmake_minimum_required(VERSION 3.3)
project(triss)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES core/main.cpp core/Source/parser/AbstractSystemParser.cpp core/Headers/parcer/AbstractSystemParser.h core/Source/parser/MemInfoParser.cpp core/Headers/parcer/MemInfoParser.h core/Source/parser/CpuInfoParser.cpp core/Headers/parcer/CpuInfoParser.h core/Source/parser/ParseExecutor.cpp core/Headers/parcer/ParseExecutor.h core/Source/parser/UserInfoParser.cpp core/Headers/parcer/UserInfoParser.h)
add_executable(triss ${SOURCE_FILES})