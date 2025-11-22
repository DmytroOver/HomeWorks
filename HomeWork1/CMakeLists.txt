cmake_minimum_required(VERSION 3.10)

project(HomeWork1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Debug)
endif()

add_executable(HomeWork1 HomeWork1.cpp)