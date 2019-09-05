#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <omp.h>
#include <math.h>
//Programming Simplified is licensed under a Creative Commons 
//Attribution-NonCommercial-NoDerivs 3.0 Unported License.

double factorial(int n){
  int c=1;
  double fact = 1.0;
  for (c = 1; c <= n; c++){
      fact = fact * c;
    }
  return fact;
}

int main()
{

  long n=7;
  double result =0.0;
  int x=2;
  int c=0;
  double start_time, run_time;
  /*start timer */
  start_time = omp_get_wtime();

   /* Use double of system processors (threads) */
  omp_set_num_threads(8);
  start_time = omp_get_wtime();
  #pragma omp parallel
  {
      #pragma omp single
      printf(" num_threads = %d",omp_get_num_threads());
      #pragma omp for reduction(+:result) 
      for (c = 0; c <= n; c++){
        double ex = pow(x,c);
        double fact = factorial(c);
        double div = ex/fact;
        result = result + div;
      }

  }
  run_time = omp_get_wtime() - start_time;

  printf("\n Result is %f\n finished in %f seconds \n",result,run_time);

}