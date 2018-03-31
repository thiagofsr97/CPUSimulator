cmake_minimum_required(VERSION 3.8)
project(CPUSimulator)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Memory.cpp Memory.h Utils.h CPU.cpp CPU.h)
add_executable(CPUSimulator ${SOURCE_FILES})