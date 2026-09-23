#include <stdio.h>
#include <omp.h>
#include <time.h>

static long num_steps = 100000000;

double step;

#define NUM_T 100
double sumns[NUM_T];

int main() {
    double x, pi, sum = 0.0;

    step = 1.0 / (double) num_steps;

    double separation = num_steps / NUM_T;


    #pragma omp parallel num_threads(NUM_T)
    {
        int id = omp_get_thread_num();

        double start  = id * separation;
        double finish = (id + 1) * separation;

        for (int i = start; i < finish; i++) {
            x = (i + 0.5) * step;

            sumns[id] = sumns[id] + 4.0 / (1.0 + x * x);
        }
    }

    for (int i = 0; i < NUM_T; i++)
        sum += sumns[i];

    pi = step * sum;

    printf("%f\n", pi);
}
