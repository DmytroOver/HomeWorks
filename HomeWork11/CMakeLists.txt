cmake_minimum_required(VERSION 3.16)

project(HomeWork11 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost REQUIRED COMPONENTS system)

add_executable(tcp_server server.cpp)
target_link_libraries(tcp_server PRIVATE Boost::system)

add_executable(tcp_client client.cpp)
target_link_libraries(tcp_client PRIVATE Boost::system)
