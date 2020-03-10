#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
#include <math.h>

void main(){

    int vet[5] = {1, 2, 3, 4, 5};
    float sum = 0;
    float avg = 0;
    float vars = 0;
    double sigma = 0;

    #pragma omp parallel
    {
        #pragma omp reduction(+:sum)
        for(int i = 0; i < 5; i++){
            sum += vet[i];
        }

        #pragma omp single
        {
            avg = sum;
            avg = avg / 5;
            printf("Avg => %.2f \n", avg);
        }

        #pragma omp reduction(+:vars)
        {
            for(int i = 0; i < 5; i++){
                float temp = vet[i] - avg;
                vars += (temp * temp);
            }
        }
    }
    sigma = sqrt(vars/5);
    printf("STD => %.2f \n", sigma);

}