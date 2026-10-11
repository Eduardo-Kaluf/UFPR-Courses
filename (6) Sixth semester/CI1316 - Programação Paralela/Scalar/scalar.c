/*
 * 
Compile, por exemplo, com GCC:
gcc -O3 -fopenmp-simd -march=native simd.c -o simd


Para verificar a vetorização com GCC, use:
gcc -O3 -fopenmp-simd -march=native \
    -fopt-info-vec-optimized \
    -fopt-info-vec-missed \
    simd.c -o simd
 * 
 * 
 * 
 * */



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#define N (1 << 25)

void process_scalar(const float *x, const float *y,
                    float *z, int n,
                    float alpha, float beta)
{
    for (int i = 0; i < n; i++) {
        float v = alpha * x[i] + beta * y[i];

        if (v > 0.0f)
            z[i] = v * v;
        else
            z[i] = 0.0f;
    }
}

/* TODO: os alunos devem implementar a versão SIMD */
void process_simd( const float  *__restrict x, const float  * __restrict y,
                  float *__restrict z, int n,
                  float alpha, float beta)
{
    float v1, v2, v3;
    #pragma omp for simd aligned(x, y, z:32)
    for (int i = 0; i < n; i++) {
        v1 = alpha * x[i];
        v2 = beta * y[i];
        v3 = v1 + v2;

        z[i] = (v3 * v3);

        if (v3 <= 0.0f)
            z[i] = 0.0f;
    }

}

int main(void)
{
    const int n = N;
    const float alpha = 1.42f;
    const float beta = -0.42f;

    float *x  = malloc((size_t)n * sizeof(float));
    float *y  = malloc((size_t)n * sizeof(float));
    float *z1 = malloc((size_t)n * sizeof(float));
    float *z2 = malloc((size_t)n * sizeof(float));

    if (!x || !y || !z1 || !z2) {
        fprintf(stderr, "Erro na alocacao de memoria\n");
        free(x);
        free(y);
        free(z1);
        free(z2);
        return EXIT_FAILURE;
    }

    /* Inicializacao dos dados */
    for (int i = 0; i < n; i++) {
        x[i] = (float)(i % 1000 - 500) / 100.0f;
        y[i] = (float)(i % 700 - 350) / 100.0f;
    }

    /* Versao escalar */
    double t0 = omp_get_wtime();
    process_scalar(x, y, z1, n, alpha, beta);
    double t1 = omp_get_wtime();

    /* Versao a ser vetorizada */
    double t2 = omp_get_wtime();    
    process_simd(x, y, z2, n, alpha, beta);
    double t3 = omp_get_wtime();

    /* Verificacao dos resultados */
    int errors = 0;

    for (int i = 0; i < n; i++) {
        if (fabsf(z1[i] - z2[i]) > 1e-5f) {
            errors++;
            if (errors <= 5)
                printf("Diferenca em %d: %f != %f\n",
                       i, z1[i], z2[i]);
        }
    }

    double scalar_time = t1 - t0;
    double simd_time = t3 - t2;

    printf("Elementos: %d\n", n);
    printf("Tempo escalar: %.6f s\n", scalar_time);
    printf("Tempo SIMD:    %.6f s\n", simd_time);

    if (simd_time > 0.0)
        printf("Speedup:       %.2fx\n",
               scalar_time / simd_time);

    printf("Verificacao: %s (%d erros)\n",
           errors == 0 ? "OK" : "FALHOU", errors);

    free(x);
    free(y);
    free(z1);
    free(z2);

    return errors == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}

