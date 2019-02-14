
cmake_minimum_required (VERSION 2.6)

project (Factorial)
enable_testing()

add_library(stuff factorial.c)

add_executable(test_factorial test_factorial.c)
target_link_libraries(test_factorial stuff)
add_test(FactorialTest test_factorial)
