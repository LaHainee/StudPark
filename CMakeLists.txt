cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)
project(studpark CXX)

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS -stdlib=libc++)
add_compile_options(-O3 -march=native -mtune=native -Wno-deprecated-declarations)

find_package(Threads REQUIRED)
find_package(inja REQUIRED)
find_package(OpenSSL REQUIRED)

include_directories(vendor/inja/include/inja)

include_directories(
    include/templates
    include/mailing
    ${PostgreSQL_INCLUDE_DIRS}
    include/orm
    include/server
    include/api
    /root/boost_1_76_0
    /usr/local/include/inja
    /opt/homebrew/include
    /opt/homebrew/lib
)

link_directories(
    /root/boost_1_76_0/stage/lib
)

include_directories(${postgresql})

add_executable(studpark
    main.cpp
    src/api/FilesAPI.cpp
    src/api/GroupAPI.cpp
    src/api/PostAPI.cpp
    src/api/UserAPI.cpp
    src/api/Utils.cpp
    src/orm/Comment.cpp
    src/orm/Contact.cpp
    src/orm/Deadline.cpp
    src/orm/File.cpp
    src/orm/Group.cpp
    src/orm/Post.cpp
    src/orm/SendMail.cpp
    src/orm/Session.cpp
    src/orm/Share.cpp
    src/orm/Student.cpp
    src/orm/Subject.cpp
    src/orm/Wrapper.cpp
    src/server/Connection.cpp
    src/server/ConnectionManager.cpp
    src/server/Request.cpp
    src/server/Response.cpp
    src/server/server.cpp
    src/server/Transportation.cpp
    src/templates/template_engine.cpp
)

add_executable(sender
    src/mailing/sender_daemon.cpp
    src/mailing/sender.cpp
    src/orm/SendMail.cpp
    src/orm/Wrapper.cpp
)

add_executable(tests_sender
        test/mailing/test_sender.cpp
)

add_executable(tests_template_engine
        test/templates/test_template_engine.cpp
)

target_link_libraries(studpark
    PostgreSQL::PostgreSQL
    pthread
    boost_system
    boost_locale
    OpenSSL::Crypto
    curl
)

target_link_libraries(sender
    PostgreSQL::PostgreSQL
    curl
    pthread
)

add_subdirectory(vendor/googletest)
add_subdirectory(vendor/inja)

enable_testing()

add_test(tests_sender "./tests_s")
add_test(tests_template_engine "./tests_te")
