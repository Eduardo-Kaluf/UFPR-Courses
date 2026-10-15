#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#define SIZE 10000000

double f(int i) { return sqrt((double)i) * sin((double)i); }

int main(void) {
    int n = SIZE;
    double *a = malloc(n * sizeof(double));
    double *b = malloc(n * sizeof(double));

    #pragma omp parallel
    {
        #pragma omp for
        for (int i = 0; i < n; i++)
            a[i] = f(i);

        #pragma omp for
        for (int i = 0; i < n; i++)
            b[i] = 2 * a[n - 1 - i];
    }

    int errors = 0;
    for (int i = 0; i < n; i++)
        if (b[i] != 2 * f(n - 1 - i)) errors++;
    printf("%d wrong elements of %d\n", errors, n);
    free(a); free(b);
    return 0;
}