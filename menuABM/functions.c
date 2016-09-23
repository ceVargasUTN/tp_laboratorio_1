#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "prototypes.h"

/*Selecion  de la opcion */
 int getOpcion(int opc)
    {
        int op;
        printf( "     MENU PRINCIPAL\nIngrese la opcion que desee: \n1. Agregar una persona\n2. Borrar una persona\n3. Imprimir lista ordenada por nombre\n4. Imprimir gráfico de edades");
        scanf("%d", &op);
        return op;
    }




