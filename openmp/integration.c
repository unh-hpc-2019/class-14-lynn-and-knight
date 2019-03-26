#include <stdio.h>
#include <math.h>
#include "cells.h"

double func (double x)
{
	return sqrt(1.-x*x);
}

double evalTrap (double x, double y)
{
	if (y>x){
		return (0.5*(y-x)*(func(y)+func(x)));
	}
	else {
		return (0.5*(x-y)*(func(y)+func(x)));
	}
}

int main()
{
	double t0 = Wtime();
	int intervals = 50;

	double x [intervals];

	for (int i=0; i<intervals; i++)
	{
		x[i] = i/((double) intervals);
	}

	double sum = 0.0;

#pragma omp parallel 
	{
		double local_sum = 0.;
#pragma omp for
		for (int i=0; i<intervals-1; i++)
		{
			local_sum += evalTrap(x[i],x[i+1]);
		}
#pragma omp atomic
		sum += local_sum;
	}
	double t1 = Wtime();
	printf("Sum of integral is %g.\n",sum);
	printf("Time to run integral.c is %g.\n",t1-t0);

	return 0;
}
