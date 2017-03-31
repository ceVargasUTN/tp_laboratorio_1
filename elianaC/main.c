#include <stdio.h>
#include <stdlib.h>
#define CANTELEMENTS 5

int main()
{
    int edad[CANTELEMENTS] ;
    int i;

    obtenerEdad("Ingresar edad: ", edad);

    for(i = 0 ; i < CANTELEMENTS ; i++)
    {
        printf("%d\n", edad[i]);
    }



    return 0;
}
