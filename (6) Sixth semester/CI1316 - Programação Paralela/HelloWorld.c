#include <stdio.h>
#include <omp.h>

int main() {
    int id = omp_get_thread_num();


    #pragma omp parallel num_threads(50)
    {
        printf(" hello(%d) ", id);
        printf(" world(%d) \n", id);
    }

    printf("\nEnd\n");

    return 0;
}
