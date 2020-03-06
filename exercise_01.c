#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
#include <math.h>
/*
    Dados dois vetores, calcular a soma deles
 */
void main() 
{
    int array_a[5] = {1,2,3,4,5};
    int array_b[5] = {1,2,3,4,5};
    int array_sum[5] = {0,0,0,0,0};
    
    #pragma omp parallel
    {
        #pragma omp for
        for (int i = 0; i < 5; i++)
        {
            array_sum[i] = array_a[i] + array_b[i];
            printf("Thread %d executando -> %d\n", omp_get_thread_num(), array_sum[i]);
        }
    }
}
