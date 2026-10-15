/* p7.c - counting primes. Expected count: 1270607. */
#include <stdio.h>
#include <omp.h>

#define LIMIT 20000000

int is_prime(int k) {
    if (k < 2) return 0;
    for (int d = 2; (long)d * d <= k; d++)
        if (k % d == 0) return 0;
    return 1;
}

int main(void) {
    int count = 0;
    double t0 = omp_get_wtime();
    for (int k = 0; k < LIMIT; k++) count += is_prime(k);
    double t1 = omp_get_wtime();
    printf("primes below %d: %d   time %.3f s   threads %d\n",
           LIMIT, count, t1 - t0, omp_get_max_threads());
    return 0;
}