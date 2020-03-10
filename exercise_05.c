#include <stdlib.h>
#include <stdio.h>
#include "omp.h"
#include <math.h>

void main()
{
    int last, dividend, divider, x;

    last = 100;
    printf("Os numeros primos entre 1 e o %d sao: 1 ", last);

    #pragma omp parallel for
    for (dividend = 3; dividend <= last; dividend +=2) {
      x = 0;
      for(divider = 3; divider <= last; divider +=2) {
        if(dividend % divider == 0) {
          x = x + 1;                        
        }
      }
      if(x == 1) printf("%d ", dividend);             
      }
    printf("\n");                                     
}
