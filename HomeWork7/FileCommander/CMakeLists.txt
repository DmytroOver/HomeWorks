cmake_minimum_required (VERSION 3.10)

project (FileCommander LANGUAGES CXX)

add_executable (FileCommander
        main.cpp
)

target_link_libraries(FileCommander
        PRIVATE FileFilter
)
