#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define SIZE 10000000

int main(void) {
    int n = SIZE;
    int *a = malloc(n * sizeof(int));
    srand(42);
    for (int i = 0; i < n; i++) a[i] = rand() % 201 - 100;   /* -100..100 */

    /* sequential reference */
    int ref_count = 0, ref_last = -1;
    for (int i = 0; i < n; i++)
        if (a[i] > 0) { ref_count++; ref_last = i; }

    int count = 0, last = -1;
    #pragma omp parallel for private(count)
    for (int i = 0; i < n; i++)
        if (a[i] > 0) { count++; last = i; }

    printf("parallel:  count=%d last=%d\n", count, last);
    printf("reference: count=%d last=%d\n", ref_count, ref_last);
    free(a);
    return 0;
}