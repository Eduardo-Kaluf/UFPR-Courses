#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

#define SIZE 10000000

static void merge(int *a, int *t, int lo, int mid, int hi) {
    int i = lo, j = mid, k = lo;
    while (i < mid && j < hi) t[k++] = a[i] <= a[j] ? a[i++] : a[j++];
    while (i < mid) t[k++] = a[i++];
    while (j < hi)  t[k++] = a[j++];
    memcpy(a + lo, t + lo, (hi - lo) * sizeof(int));
}

static void msort(int *a, int *t, int lo, int hi, int cutoff) {
    if (hi - lo < 2)
        return;
    int mid = (lo + hi) / 2;

    #pragma omp task if(hi - lo > cutoff)
    msort(a, t, lo, mid, cutoff);
    msort(a, t, mid, hi, cutoff);

    #pragma omp taskwait
    merge(a, t, lo, mid, hi);
}

int main(int argc, char **argv) {
    int cutoff = argc > 1 ? atoi(argv[1]) : 10000;
    int n = SIZE;
    int *a = malloc(n * sizeof(int)), *t = malloc(n * sizeof(int));
    srand(3);
    for (int i = 0; i < n; i++) a[i] = rand();

    double t0 = omp_get_wtime();
    #pragma omp parallel
    #pragma omp single
    msort(a, t, 0, n, cutoff);
    double t1 = omp_get_wtime();

    int sorted = 1;
    for (int i = 1; i < n; i++) if (a[i - 1] > a[i]) { sorted = 0; break; }
    printf("cutoff %d: %.4f s  %s\n", cutoff, t1 - t0, sorted ? "sorted" : "NOT SORTED");
    free(a); free(t);
    return 0;
}