cmake_minimum_required(VERSION 3.2.0)
project(foo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -pthread")

set(SOURCES
    main.cpp
    Api.cpp
)

link_directories("${CMAKE_CURRENT_BINARY_DIR}/deps/lib")

add_executable(tryShutdown "${SOURCES}")
target_include_directories(tryShutdown PRIVATE "${CMAKE_CURRENT_BINARY_DIR}/deps/include")
target_link_libraries(tryShutdown pistache)
