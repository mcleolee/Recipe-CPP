cmake_minimum_required(VERSION 3.19)
project(Recipe)

set(CMAKE_CXX_STANDARD 11)

add_executable(Recipe main.cpp recipe.h recipe.cpp tcp.h tcp.cpp /
        server/tcp_server.cpp client/tcp_client.cpp)