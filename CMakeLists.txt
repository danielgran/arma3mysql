cmake_minimum_required(VERSION 3.21)
project(arma3mysql)

set(CMAKE_CXX_STANDARD 23)

include_directories(/usr/local/mysql-connector-c++-8.0.28/include)
link_directories(/usr/local/mysql-connector-c++-8.0.28/lib64)
#add_executable(arma3mysql library.cpp)

add_library(arma3mysql SHARED library.cpp)

target_link_libraries(arma3mysql mysqlcppconn)
target_link_libraries(arma3mysql ssl.1.1)


include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(
        hello_test
        hello_test.cc
)
target_link_libraries(
        hello_test
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(hello_test)