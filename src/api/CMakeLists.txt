cmake_minimum_required(VERSION 3.16)
project(hw2 CXX)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER "g++-10")

# add_compile_options(-Wall -Wpedantic -Werror -Wno-vla --coverage)

enable_testing()

include(ExternalProject)
ExternalProject_Add(
        gtest
        URL https://github.com/google/googletest/archive/release-1.10.0.zip
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
        INSTALL_COMMAND ""
)
ExternalProject_Get_Property(gtest source_dir binary_dir)
add_library(libgtest IMPORTED STATIC GLOBAL)
add_dependencies(libgtest gtest)
set_target_properties(libgtest PROPERTIES
        "IMPORTED_LOCATION" "${binary_dir}/lib/libgtest.a"
        "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
)
add_library(libgmock IMPORTED STATIC GLOBAL)
add_dependencies(libgmock gtest)
set_target_properties(libgmock PROPERTIES
        "IMPORTED_LOCATION" "${binary_dir}/lib/libgmock.a"
        "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
)
include_directories(
        "${source_dir}/googletest/include"
        "${source_dir}/googlemock/include"
        "${PROJECT_SOURCE_DIR}/include/api"
)
add_test(NAME test_api
        COMMAND test_api
)

add_executable(test_admin ../../test/api/AdminAPI.cpp)
add_executable(test_calendar ../../test/api/CalendarAPI.cpp)
add_executable(test_files ../../test/api/FilesAPI.cpp)
add_executable(test_group ../../test/api/GroupAPI.cpp)
add_executable(test_logger ../../test/api/Logger.cpp)
add_executable(test_post ../../test/api/PostAPI.cpp)
add_executable(test_user ../../test/api/UserAPI.cpp)

set(LIBS libgtest libgmock pthread)

target_link_libraries(test_admin ${LIBS})
target_link_libraries(test_calendar ${LIBS})
target_link_libraries(test_files ${LIBS})
target_link_libraries(test_group ${LIBS})
target_link_libraries(test_logger ${LIBS})
target_link_libraries(test_post ${LIBS})
target_link_libraries(test_user ${LIBS})
target_link_libraries(test_admin ${LIBS})

# target_link_libraries(hw2 Single::single -fprofile-arcs dl pthread)
