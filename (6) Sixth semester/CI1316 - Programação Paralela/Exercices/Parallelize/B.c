#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define SIZE 100000000
#define MAXT 64

int count_a(const int *v, int n) {             /* (a) adjacent counters */
    int cnt[MAXT] = {0}, nt = 1;
    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        #pragma omp single
        nt = omp_get_num_threads();
        #pragma omp for
        for (int i = 0; i < n; i++)
            if ((v[i] & 1) == 0) cnt[id]++;
    }
    int total = 0;
    for (int t = 0; t < nt; t++) total += cnt[t];
    return total;
}

int count_b(const int *v, int n) {             /* (b) TODO: padded cnt[MAXT][16] */
    int total = 0;
    for (int i = 0; i < n; i++) if ((v[i] & 1) == 0) total++;
    return total;
}

int count_c(const int *v, int n) {             /* (c) TODO: local counter + one atomic */
    int total = 0;
    for (int i = 0; i < n; i++) if ((v[i] & 1) == 0) total++;
    return total;
}

int main(void) {
    int n = SIZE;
    int *v = malloc((size_t)n * sizeof(int));
    for (int i = 0; i < n; i++) v[i] = i;

    double t0 = omp_get_wtime(); int ra = count_a(v, n);
    double t1 = omp_get_wtime(); int rb = count_b(v, n);
    double t2 = omp_get_wtime(); int rc = count_c(v, n);
    double t3 = omp_get_wtime();

    printf("(a) adjacent: %d  %.4f s\n", ra, t1 - t0);
    printf("(b) padded:   %d  %.4f s\n", rb, t2 - t1);
    printf("(c) local:    %d  %.4f s\n", rc, t3 - t2);
    free(v);
    return 0;
}