cmake_minimum_required(VERSION 3.14)
project(arma3mysql_test)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

include_directories(arma3mysql PUBLIC library)
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        hello_test
        hello_test.cc
        library/testlib.cpp
)
target_link_libraries(
        hello_test
        gtest_main
        dl
)

include(GoogleTest)
gtest_discover_tests(hello_test)