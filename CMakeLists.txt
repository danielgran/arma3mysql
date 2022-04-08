cmake_minimum_required(VERSION 3.21)
project(arma3mysql)
set(CMAKE_CXX_STANDARD 23)

add_subdirectory(arma3mysql)
add_subdirectory(test-behaviour)

if (APPLE)
    add_definitions(-D__APPLE__)
    message(wir sind auf einem)
    add_compile_definitions(__APPLE__=TRUE)
endif()

if(UNIX AND NOT APPLE)
    add_definitions(-D__LINUX__)
    add_compile_definitions(__LINUX__=TRUE)
endif()