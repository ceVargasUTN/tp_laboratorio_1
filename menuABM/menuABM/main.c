#include <stdio.h>
#include <stdlib.h>
#include "prototypes.h"
#define cantPersona 5
#define alta 1
#define vacio 0
#define baja -2
#define ocupado -1

int main()
{
    ePersona arrayPersonas[cantPersona];
    ePersona auxPersonas;
    char auxNombre[50];
    char auxDni[8];
    int auxEdad;
    //int auxFlagPersona;
    int opcion = 9;
    int lugarLibre;
    int pos;
    int i;


    inicializarArrayPersonas(arrayPersonas, cantPersona, vacio);//el array inicia con valores en 0 "vacio"
    inicializarDatos(arrayPersonas, cantPersona);//llamo a la funcion para harcodear y comenzar a probar.

    while (opcion != 0)
    {

        opcion = getOpcion(opcion);
        system("cls");
        switch (opcion)
        {
            case 1:
                lugarLibre = buscarPrimerOcurrencia(arrayPersonas, cantPersona, vacio);
                if (lugarLibre == -1)
                {
                    printf("Se excedio la cantidad de ingresos...");
                    break;
                }
                printf( "ALTA \n");
                if (!obtenerNombreValidado("Nombre: ", auxNombre))
                    {
                        printf("El nombre solo debe contener letras!");
                        break;
                    }
                strcpy(arrayPersonas[lugarLibre].nombre, auxNombre);
                //printf(arrayPersonas[lugarLibre].nombre);
                break;
            case 2:

                printf("BORRAR\n");
                printf("Que posicion borrar?: ");
                scanf("%d", &pos);
                arrayPersonas[pos].flag_estado=baja;
                printf("\n Borrado exitoso!");
                break;
            case 3:
                printf("ORDENAR LISTA POR NOMBRE\n");
                ordenarPorNombre(arrayPersonas, cantPersona);

            //Case 4 hara la impresion del ordenamiento por default
            case 4:
                for (i = 0; i < cantPersona; i++)
                {
                    if(arrayPersonas[i].flag_estado != baja)
                    {
                        printf(arrayPersonas[i].nombre);
                        printf("%d \n", arrayPersonas[i].edad);
                        printf("%s \n",arrayPersonas[i].dni);
                    }
                }
            break;
            case 5:
                for (i = 0; i < cantPersona; i++)
                {
                    printf("NOMBRE : %s \n", arrayPersonas[i].nombre);
                    printf("EDAD:%d \n", arrayPersonas[i].edad);
                    printf("DNI: %s \n",arrayPersonas[i].dni);
                    printf("ESTADO %d \n", arrayPersonas[i].flag_estado);
                }
                break;

        }


    }
    return 0;

}




