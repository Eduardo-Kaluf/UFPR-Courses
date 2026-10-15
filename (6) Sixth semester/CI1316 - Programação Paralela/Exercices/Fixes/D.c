#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#define SIZE 20000000

double work(int i) { return sin(i * 0.001) * sin(i * 0.001); }

int main(void) {
    int n = SIZE;

    double ref = 0.0;
    for (int i = 0; i < n; i++) ref += work(i);

    int nthreads = omp_get_num_threads();
    double *partial = calloc(nthreads, sizeof(double));

    double t0 = omp_get_wtime();
    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        for (int i = id; i < n; i += omp_get_num_threads())
            partial[id] += work(i);
    }
    double t1 = omp_get_wtime();

    double total = 0.0;
    for (int t = 0; t < nthreads; t++) total += partial[t];
    printf("time %.4f s  total=%.6f  reference=%.6f\n", t1 - t0, total, ref);
    free(partial);
    return 0;
}