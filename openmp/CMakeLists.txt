
cmake_minimum_required (VERSION 3.9)

project (Cells)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

find_package(OpenMP)
if(OpenMP_C_FOUND)
	link_libraries(OpenMP::OpenMP_C)
endif()
if(OpenMP_Fortran_FOUND)
	link_libraries(OpenMP::OpemMP_Fortran)
endif()

add_library(celllib cells.h average_cell_centers.c)
target_compile_features(celllib PUBLIC c_std_99)

link_libraries(celllib libm.a)
add_executable(average average.c)
add_executable(integration integration.c)
