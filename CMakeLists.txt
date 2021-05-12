cmake_minimum_required(VERSION 3.15)
project(orm)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_COMPILER "g++")
include_directories(src/orm/)
include_directories(include/orm/)
file(GLOB file_proj
        "include/orm/*.h"
        "include/orm/*.hpp"
        "src/orm/*.cpp"
        )
include_directories(${postgresql})


add_executable(orm ${file_proj} main.cpp)
target_link_libraries(orm pq)
