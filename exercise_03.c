#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
#include <math.h>
#include "full.h"

void main()
{
    int vet[50];
    double dob = 0.0;

    full(vet); // Insert random numbers in the array
    
    #pragma omp parallel
    {
        #pragma omp for reduction(+:dob)
        for (int i = 0; i < 3; i++)
        {
            dob += (1.0/vet[i]);
        }
    }
    double dobc = (3/dob);
    printf("%.2f\n", dobc);
}
