#include <math.h>
#ifndef CELLS_H
#define CELLS_H

#include <sys/time.h>
#include <stdlib.h>

static inline double Wtime(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec + tv.tv_usec / 1e6;
}

void average_cell_centers(double* x, int n, double* y, int m);

double func(double x);
double evalTrap (double x, double y);

#endif
