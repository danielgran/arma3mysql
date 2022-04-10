cmake_minimum_required(VERSION 3.16)
project(arma3mysql VERSION 1.0)
set(CMAKE_CXX_STANDARD 20)


if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()

include_directories(src lib)
add_subdirectory(src)