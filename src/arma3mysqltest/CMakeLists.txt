include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

include_directories(hello_test PUBLIC library mysql ${PROJECT_SOURCE_DIR})
add_executable(
        hello_test
        hello_test.cc
        mysql/MySQLConnectionTest.cc
)

target_link_libraries(hello_test gtest_main)

include(GoogleTest)
gtest_discover_tests(hello_test)
