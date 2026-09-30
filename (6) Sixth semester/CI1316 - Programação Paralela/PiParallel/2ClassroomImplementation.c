#include <omp.h>
#include <stdio.h>

static long num_steps = 10000000; 

double step;

#define NUM_THREADS 4

void main () {
    int i, nthreads;
    double pi;
    double total_sum[NUM_THREADS];
    
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

        // Solving false sharing by making the sum only after the loop finishes
        total_sum[id] = sum;
    }

    for(i = 0, pi = 0.0; i < nthreads; i++)
        pi += total_sum[i] * step;

    printf("%f\n", pi);
}