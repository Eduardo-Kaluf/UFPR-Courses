#include <stdio.h>
#include <math.h>
#include <omp.h>

#define N 500
double A[N][N], B[N][N], C[N][N], Cref[N][N];

int main(void) {
    double sum;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) { A[i][j] = (i + j) % 7; B[i][j] = (i * j) % 5; }

    /* sequential reference */
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            sum = 0.0;
            for (int k = 0; k < N; k++) sum += A[i][k] * B[k][j];
            Cref[i][j] = sum;
        }

    double t0 = omp_get_wtime();
    #pragma omp parallel for private(sum)
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            sum = 0.0;
            for (int k = 0; k < N; k++)
                sum += A[i][k] * B[k][j];
            C[i][j] = sum;
        }
    double t1 = omp_get_wtime();

    int errors = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (fabs(C[i][j] - Cref[i][j]) > 1e-9) errors++;
    printf("time %.4f s, %d wrong elements of %d\n", t1 - t0, errors, N * N);
    return 0;
}