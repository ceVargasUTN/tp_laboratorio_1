#include <stdio.h>
#include <stdlib.h>
#define CANTELEMENTS 5

void obtenerEdad(char mensaje[], int edad[])
{
    char opcion = 's';

    while(opcion)
    {

        printf(mensaje);
        fflush(stdin);
        scanf("%d", &edad );
        printf("Ingresar otra vez?: ");
        opcion = scanf("%c", &opcion);

    }




}
