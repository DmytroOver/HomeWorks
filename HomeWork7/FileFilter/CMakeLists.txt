cmake_minimum_required (VERSION 3.10)

project (FileFilter LANGUAGES CXX)

add_library (FileFilter STATIC
        FileFilter.cpp
        FileFilter.h
)

target_include_directories(FileFilter PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
