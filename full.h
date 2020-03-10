#include <stdio.h>
#include <stdlib.h>

void full(int vet[]) {
    srand((unsigned) 100);

    for(int i = 0; i < 50; i++){
        vet[i] = rand() % 50;
    }
}