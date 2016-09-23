#include <stdio.h>
#include <stdlib.h>
#include "prototypes.h"
#define cantPersona 3
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
    int auxFlagPersona;
    int opcion;
    int lugarLibre;
    int pos;

    inicializarArrayPersonas(arrayPersonas, cantPersona, ocupado);//el array inicia con valores en 0 "vacio"
   opcion = getOpcion(opcion);

    switch (opcion)
    {
        case 1:
            lugarLibre = buscarPrimerOcurrencia(arrayPersonas, cantPersona, ocupado);
            if (lugarLibre == -1)
            {
                printf("Se excedio la cantidad de ingresos...");
                if (obtenerNombreValidado("Nombre: ", auxNombre)==0)
                {
                    printf("El nombre solo debe contener letras!");
                    break;
                }
                else{
                    strcpy(arrayPersonas[lugarLibre].nombre, auxNombre);

                }
                break;
            }
            printf( "ALTA \n");
            break;

    }

    return 0;
}

void inicializarArrayPersonas(ePersona ArrayPersonas[], int cantElementos, int valor)
{
    int i;
    for (i = 0 ; i< cantElementos ; i ++)
    {
        ArrayPersonas[i].flag_estado = valor;

    }
}

int buscarPrimerOcurrencia(ePersona persona[], int cantElementos, int valor)
{
    int i;
    for (i = 0 ; i< cantElementos ; i ++)
    {
        if (arrayPersonas[i].flag_estado == valor)
        {
            return i;
        }

    }

    return -1;
}
/**
*\brief pide el  ingreso de un nombre al usuario y  lo devuelve
*\param el mensaje es lo  que recibe como parametro
*\param el array de ingreso es donde se guardara el ingreso por teclado
*\return no devuelve nada
**/
void obtenerNombre(char mensaje[], char ingresoNombre[])//char nombre en realidad puede ser cualquier string .--> string es en si, una palabra
{
    printf(mensaje);
    gets(ingresoNombre);
}
/**
*\brief Validar si EL VALOR es solo  letras
*\param recibe un array con cadena
*\return devuelve 1 si  contiene solo  letras, o 0 si hay otro caracter ademas de letras
**/
int validarSoloLetras(char soloString[])
{
    int i= 0;
    while (soloString != '\0')
    {
        if ((soloString[i]!= ' ') && (soloString [i] < 'a' || soloString > 'z') && (soloString[i]< 'A' || soloString[i]> 'Z'))
            return 0;
        i++;
    }
    return 1;
}
/**
*\brief pide al usuario un nombre
*\param el mensaje es le de peticion de ingreso
*\param ingresoNombre es donde se guardara el texto ingresado por teclado
*\return
**/
int obtenerNombreValidado(char mensaje[], char ingresoNombre)
{
    char auxNombre[256];
    obtenerNombre(mensaje, auxNombre);
    if(validarSoloLetras(auxNombre))
    {
        strcpy(ingresoNombre, auxNombre);
        return 1;
    }
     return 0;
}



/*void altaPersona(ePersona persona, int flagE, int pos)
{

    if ( flagE == 0)
    {
        printf("Nuevo nombre: ");
        gets(persona.nombre);
        flagE = alta;

    }

}



*/
