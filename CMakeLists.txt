cmake_minimum_required(VERSION 3.25)

set(This Example)

project(${This} C CXX)

set(CMAKE_C_STANDARD_99)
set(CMAKE_CXX_STANDARD_14)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)

set(Headers
    Example.hpp
)

set(Sources
    Example.cpp
)

add_library(${This} STATIC ${Headers} ${Sources})

add_subdirectory(UnitTestModule)
