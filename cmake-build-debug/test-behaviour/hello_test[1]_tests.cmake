add_test( HelloTest.BasicAssertions /Users/danielgran/Projects/arma3mysql/cmake-build-debug/test-behaviour/hello_test [==[--gtest_filter=HelloTest.BasicAssertions]==] --gtest_also_run_disabled_tests)
set_tests_properties( HelloTest.BasicAssertions PROPERTIES WORKING_DIRECTORY /Users/danielgran/Projects/arma3mysql/cmake-build-debug/test-behaviour SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set( hello_test_TESTS HelloTest.BasicAssertions)
