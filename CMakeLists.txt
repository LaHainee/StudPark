cmake_minimum_required(VERSION 3.15)
project(orm)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS -stdlib=libc++)

find_package(Threads REQUIRED)
find_package(inja REQUIRED)
find_package(OpenSSL REQUIRED)

include_directories(src/orm/)
include_directories(include/orm/)
include_directories(include/templates)
include_directories(include/mailing)
include_directories(vendor/inja/include/inja)
include_directories(/opt/homebrew/include)
include_directories(/opt/homebrew/lib)

file(GLOB file_proj
        "include/orm/*.h"
        "include/orm/*.hpp"
        "src/orm/*.cpp"
        )

include_directories(${postgresql})

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

add_executable(
        sender
        include/mailing/sender.h
        src/mailing/sender_daemon.cpp
        src/mailing/sender.cpp
)

add_executable(
        template_engine
        include/templates/template_engine.h
        src/templates/template_engine.cpp
)

add_executable(
        tests_sender
        test/mailing/test_sender.cpp
)

add_executable(
        tests_template_engine
        test/templates/test_template_engine.cpp
)

target_link_libraries(tests_sender gtest Threads::Threads)
target_link_libraries(tests_template_engine gtest Threads::Threads)
target_link_libraries(template_engine inja PostgreSQL::PostgreSQL)
target_link_libraries(tests_template_engine inja)
target_link_libraries(sender PostgreSQL::PostgreSQL curl)


add_subdirectory(vendor/googletest)
add_subdirectory(vendor/inja)

enable_testing()

add_test(tests_sender "./tests_s")
add_test(tests_template_engine "./tests_te")

add_executable(orm ${file_proj})
target_link_libraries(orm pq ${inja} OpenSSL::Crypto)

