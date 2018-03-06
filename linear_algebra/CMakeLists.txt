
cmake_minimum_required (VERSION 2.6)

project (LinearAlgebra)
enable_testing()

enable_language(Fortran)
include(FortranCInterface)
FortranCInterface_HEADER(FC.h MACRO_NAMESPACE "FC_")
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_library(linalg linear_algebra.h
  vector.c vector_dot.c vector_add.c
  matrix.c matrix_vector_mul.c matrix_matrix_mul.c
  matrix_vector_mul_f.F)
target_compile_features(linalg PUBLIC c_std_99)
# pull in the math library (libm)
target_link_libraries(linalg PUBLIC m)

link_libraries(linalg)
add_executable(test_vector_dot test_vector_dot.c)
add_executable(test_vector_add test_vector_add.c)
add_executable(test_matrix_vector_mul test_matrix_vector_mul.c)
add_executable(test_matrix_matrix_mul test_matrix_matrix_mul.c)
add_executable(test_data_layout
  test_data_layout.c print_matrix_fortran.F)
add_executable(test_data_layout_fortran
  test_data_layout_fortran.F print_matrix_fortran.F)
add_executable(large_matrix_vector_mul large_matrix_vector_mul.c)
add_executable(test_average test_average.c)
add_executable(test_average_basic test_average_basic.c)

add_test(test_vector_dot test_vector_dot)
add_test(test_vector_add test_vector_add)
add_test(test_matrix_vector_mul test_matrix_vector_mul)
add_test(test_matrix_matrix_mul test_matrix_matrix_mul)

