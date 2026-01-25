# CMakeList.txt : CMake project for HomeWork7, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.10)

project ("HomeWork7")

# Add source to this project's executable.
add_executable (HomeWork7 "main.cpp" "main.h"
        "FileFilter.cpp"
        "FileFilter.h"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET HomeWork7 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
