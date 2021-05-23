cmake_minimum_required(VERSION 3.19)
project(server)

find_package(OpenSSL REQUIRED)

set(CMAKE_CXX_STANDARD 20)

include_directories("include/server/")
include_directories("src/server/")
include_directories("include/api/")
include_directories("src/api/")
include_directories("include/orm/")
include_directories("src/orm/")

file(GLOB file_proj
        "include/server/*.h"
        "include/api/*.h"
        "include/orm/*.h"
        "src/server/*.cpp"
        "src/api/*.cpp"
        "src/orm/*.cpp"
)
include_directories(${postgresql})


add_executable(server ${file_proj} main.cpp)

target_link_libraries(server pthread boost_system curl OpenSSL::Crypto pq)