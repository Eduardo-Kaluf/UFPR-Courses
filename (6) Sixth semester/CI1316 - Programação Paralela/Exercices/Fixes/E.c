#include <stdio.h>
#include <omp.h>

int fib(int n) {
    int x, y;
    if (n < 2) return n;
    #pragma omp task
    x = fib(n - 1);
    #pragma omp task
    y = fib(n - 2);
    return x + y;
}

int main(void) {
    double t0 = omp_get_wtime();
    #pragma omp parallel
    printf("fib(30) = %d\n", fib(30));
    printf("time %.4f s\n", omp_get_wtime() - t0);
    return 0;
}