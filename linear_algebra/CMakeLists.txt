
cmake_minimum_required (VERSION 2.6)

project (LinearAlgebra)
enable_testing()
enable_language(Fortran)

add_library(linalg linear_algebra.h
  vector.c vector_dot.c vector_add.c
  matrix.c matrix_vector_mul.c matrix_matrix_mul.c)
target_compile_features(linalg PUBLIC c_std_99)

link_libraries(linalg)
add_executable(test_vector_dot test_vector_dot.c)
add_executable(test_vector_add test_vector_add.c)
add_executable(test_matrix_vector_mul test_matrix_vector_mul.c)
add_executable(test_matrix_matrix_mul test_matrix_matrix_mul.c)
add_executable(test_data_layout test_data_layout.c)
add_executable(test_data_layout_fortran
  test_data_layout_fortran.F print_matrix_fortran.F)

add_test(test_vector_dot test_vector_dot)
add_test(test_vector_add test_vector_add)
add_test(test_matrix_vector_mul test_matrix_vector_mul)
add_test(test_matrix_matrix_mul test_matrix_matrix_mul)

