#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
#include "full.h"

void main(){
    int vet[50];
    int lower = 999;
    int biggest = 0;
    int value = 0;

    full(vet);

    #pragma omp parallel
    {
        #pragma omp for
        for(int i = 0; i < 50; i++){
            value = vet[i];
            if(value > biggest) {
                biggest = value;
            } else if (value < lower) {
                lower = value;
            }
        }
    }
    printf("Low: %d, Big: %d \n", lower, biggest);
}