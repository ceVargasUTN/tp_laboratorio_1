#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#define MAX 100

int main(){

    int j;
    int edad[] = {22,11,33,55,66};


    ordenarVector(edad, 5);
    for(j = 0; j < 5; j++)
    {
        printf("%d\n", edad[j]);
    }
printf("Indice: %d", indicarMinimo(edad, 5));

    return 0;
}
