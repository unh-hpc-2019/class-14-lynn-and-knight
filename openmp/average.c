#include <stdio.h>

#include "cells.h"

int main(){

	double t0 = Wtime();
	double x = 1;
	double array[10];
	int arrayLen = 10;
	for (int i=0;i<10;i++){
		array[i]=i+1;
	}


	double cellCenters [arrayLen-1];
	average_cell_centers(array, arrayLen,cellCenters, arrayLen-1);

	for (int i=0;i<arrayLen-1;i++){
		printf("%g\n",cellCenters[i]);
	}
	double t1 = Wtime();
	printf("Total time to run average.c was %g.\n", t1-t0);

	return 0;

}

