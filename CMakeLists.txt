cmake_minimum_required(VERSION 3.12)
project(sender C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror --coverage")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wpedantic")
set(CMAKE_CXX_FLAGS "--coverage")

find_package(Threads REQUIRED)
include_directories(include/templates)
include_directories(include/mailing)
include_directories(vendor/inja/include/inja)

add_executable(
        sender
        include/mailing/sender.h
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
target_link_libraries(template_engine inja)
target_link_libraries(tests_template_engine inja)

add_subdirectory(vendor/googletest)
add_subdirectory(vendor/inja)

enable_testing()

add_test(tests_sender "./tests_s")
add_test(tests_template_engine "./tests_te")
