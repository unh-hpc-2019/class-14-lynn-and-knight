
#include "linear_algebra.h"

#include <math.h>
#include <stdio.h>

// ----------------------------------------------------------------------
// calculate vector average (nc -> cc)

void
vector_average(float *cc, float *nc, int n)
{
#pragma omp parallel for
  for (int i = 0; i < n; i++) {
    cc[i] = .5 * (nc[i] + nc[i+1]);
  }
}

// ----------------------------------------------------------------------
// main

int
main(int argc, char **argv)
{
  int N = 1000000;
  float x_nc[N+1];
  
  float dx = 2. * M_PI / N;
  for (int i = 0; i <= N; i++) {
    float x = i * dx;
    x_nc[i] = sin(x) + 1./3. * sin(3.*x);
  }

  /* FILE *file = fopen("x_nc.asc", "w"); */
  /* for (int i = 0; i <= N; i++) { */
  /*   float x = i * dx; */
  /*   fprintf(file, "%g %g\n", x, x_nc[i]); */
  /* } */
  /* fclose(file); */

  float x_cc[N];
  vector_average(x_cc, x_nc, N);
  double t_beg = Wtime();
  for (int n = 0; n < 1000; n++) {
    vector_average(x_cc, x_nc, N);
  }
  double t_end = Wtime();
  printf("1000x vector_average took %g s\n", t_end - t_beg);

  /* file = fopen("x_cc.asc", "w"); */
  /* for (int i = 0; i < N; i++) { */
  /*   float x = (i + .5) * dx; */
  /*   fprintf(file, "%g %g\n", x, x_cc[i]); */
  /* } */
  /* fclose(file); */

  return 0;
}
