#include <omp.h>
#include <stdio.h>

static long num_steps = 1000000000; 

double step;

#define NUM_THREADS 8

void main () {
    int i;
    double pi, x, total_sum = 0.0;
    
    step = 1.0 / (double) num_steps;
    
    #pragma omp parallel for schedule(static) reduction(+:sum) private(x)
    for (i = 0; i < num_steps; i++) {
        x = (i + 0.5) * step;

        sum += 4.0 / (1.0 + x * x);
    }

    pi = total_sum * step;

    printf("%f\n", pi);
}