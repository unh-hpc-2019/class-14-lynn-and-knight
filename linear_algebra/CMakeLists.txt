
cmake_minimum_required (VERSION 2.6)

project (LinearAlgebra)

add_library(linalg linear_algebra.h
  vector_dot.c)

link_libraries(linalg)
add_executable(test_vector_dot test_vector_dot.c)



