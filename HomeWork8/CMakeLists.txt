cmake_minimum_required(VERSION 3.8...3.31)
project(MyProject)

find_package(Boost REQUIRED)
add_executable(MyProject example.cpp)
target_link_libraries(MyProject Boost::headers)