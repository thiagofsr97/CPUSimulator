cmake_minimum_required(VERSION 3.10)
project(CPUSimulator)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)
include_directories(Cache)

add_executable(CPUSimulator
        Cache/Cache.cpp
        Cache/Cache.h
        Cache/CacheData.cpp
        Cache/CacheData.h
        CPU.cpp
        CPU.h
        main.cpp
        Memory.cpp
        Memory.h
        Utils.h)
