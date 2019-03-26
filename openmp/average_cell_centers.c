#include "cells.h"
#include <stdio.h>

void
average_cell_centers(double* x, int n, double* y, int m)
{

#pragma omp parallel for
	for (int i=0;i<m;i++)
	{
		y[i] = 0.5*(x[i]+x[i+1]);
	}
}
