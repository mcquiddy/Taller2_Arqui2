#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <omp.h>

//z= ax +y
//a,y,z: vector
//a: escalar
int main ()
{
   

    double start_time, run_time;

    int n = 1000;
    //vectores
    float x[n];
    float y[n];
    float z[n];
    //escalar    
    float a = 2.0; 
    int nprocs;
    //llenado de vextores
    for(int i = 0; i < n; i++) {
        x[i] = i;
        y[i] = n - i;
    }
	
    

    /*start timer */
    start_time = omp_get_wtime();


 /* Use double of system processors (threads) */
    nprocs=2*omp_get_num_procs();
    omp_set_num_threads(nprocs);
    start_time = omp_get_wtime();
    #pragma omp parallel
    {
        #pragma omp single
        printf(" num_threads = %d",omp_get_num_threads());

        for (int i=0;i<= n; i++){
            z[i] = a*x[i] + y[i];
            }
    }



    run_time = omp_get_wtime() - start_time;
    printf("\n X[1000] = %f, Y[1000] = %f, Z[1000] = %f finished in %f seconds \n",x[1000],y[1000],z[1000],run_time);

}