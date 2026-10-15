#include <stdio.h>
#include <omp.h>

int fib(int n) {
    int x, y;
    if (n < 2)
        return n;

    #pragma omp task shared(x)
    x = fib(n - 1);

    #pragma omp task shared(y)
    y = fib(n - 2);

    #pragma omp taskwait
    return x + y;
}

int main(void) {
    double t0 = omp_get_wtime();
    int f;
    #pragma omp parallel shared(f)
    #pragma omp single
    f = fib(30);

    printf("fib(30) = %d\n", f);
    printf("time %.4f s\n", omp_get_wtime() - t0);
    return 0;
}