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
file(GLOB file_new_semester
        "include/orm/Wrapper.h"
        "src/orm/Wrapper.cpp"
        )
include_directories(${postgresql})


add_executable(new_semester ${file_new_semester} new_semester.cpp)
add_executable(orm ${file_proj} main.cpp)
target_link_libraries(orm pq)
target_link_libraries(new_semester pq)

project(api)

find_package(inja REQUIRED)
find_package(OpenSSL REQUIRED)

include_directories(
        include/api
        include/ORM
        /usr/local/include/inja
)


add_executable(api
        main.cpp
        src/ORM/Wrapper.cpp
        src/api/UserAPI.cpp
        )
target_link_libraries(api pq ${inja} OpenSSL::Crypto)