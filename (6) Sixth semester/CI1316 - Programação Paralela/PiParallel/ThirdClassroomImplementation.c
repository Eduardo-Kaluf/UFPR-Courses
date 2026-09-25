#include <omp.h>
#include <stdio.h>

static long num_steps = 1000000000; 

double step;

#define NUM_THREADS 8

void main () {
    int i, nthreads;
    double pi;
    double total_sum;
    
    step = 1.0 / (double) num_steps;
    
    #pragma omp parallel num_threads(NUM_THREADS)
    {
        int i, id, nthrds; 
        double x;
        double sum = 0.0;

        id = omp_get_thread_num();
        
        nthrds = omp_get_num_threads();
        
        if (id == 0) 
            nthreads = nthrds;
        
        for (i = id; i < num_steps; i = i + nthrds) {
            x = (i + 0.5) * step;

            sum += 4.0 / (1.0 + x * x);
        }

        // Solving false sharing by making the sum using a global var and a mutex
        #pragma omp critical
        total_sum += sum;
    }

    pi = total_sum * step;

    printf("%f\n", pi);
}