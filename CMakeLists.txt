cmake_minimum_required(VERSION 3.15)

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