#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "prototypes.h"

/*Selecion  de la opcion */
 int getOpcion(int opc)
    {
        int op;
        printf( "     MENU PRINCIPAL\nIngrese la opcion que desee: \n1. Agregar una persona\n2. Borrar una persona\n3. Imprimir lista ordenada por nombre\n4. Imprimir gráfico de edades\n5. Mostrar lista");
        scanf("%d", &op);
        return op;
    }

void inicializarArrayPersonas(ePersona ArrayPersonas[], int cantElementos, int valor)
{
    int i;
    for (i = 0 ; i< cantElementos ; i ++)
    {
        ArrayPersonas[i].flag_estado = valor;

    }
}

int buscarPrimerOcurrencia(ePersona arrayPersonas[], int cantElementos, int valor)
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
    fflush(stdin);
    scanf("%s", ingresoNombre);
    //gets(ingresoNombre[]);
}
/**
*\brief Validar si EL VALOR es solo  letras
*\param recibe un array con cadena
*\return devuelve 1 si  contiene solo  letras, o 0 si hay otro caracter ademas de letras
**/
int validarSoloLetras(char soloString[])
{
    int i= 0;
    while (soloString[i] != '\0')
    {
        if ((soloString[i]!= ' ') && (soloString[i] < 'a' || soloString[i] > 'z') && (soloString[i]< 'A' || soloString[i]> 'Z'))
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
int obtenerNombreValidado(char mensaje[], char ingresoNombre[])
{
    char auxNombre[500];
    obtenerNombre(mensaje, auxNombre);
    if(validarSoloLetras(auxNombre))
    {
        strcpy(ingresoNombre, auxNombre);
        return 1;
    }
    return 0;
}
void inicializarDatos(ePersona arrayPersonas[], int auxCantPersona )
{
  char auxIdn[5][9]={"12345678","78945612","65498732","14785236","95123647"};
    char auxName[5][50]={"Eliana ","Gabriela ","Marcos ","Elena ","Milagros "};
    int auxEst[5]={1,1,1,1,1};
    int auxEdad[5]={15,56,15,23,15};
    int i=0;
    for(i==0;i<auxCantPersona;i++)
    {
        strcpy(arrayPersonas[i].dni,auxIdn[i]);
        strcpy(arrayPersonas[i].nombre,auxName[i]);
        arrayPersonas[i].flag_estado=auxEst[i];
        arrayPersonas[i].edad=auxEdad[i];
    }
}



void ordenarPorNombre(ePersona arrayPer[],int cantAuxPersona)
{
    int i=0;
    int j=0;
    ePersona auxPersonas;

    for(i=0;i<cantAuxPersona-1;i++)
    {
        if(arrayPer[i].flag_estado==1)
        {
            for(j=i+1;j<cantAuxPersona;j++)
            {
                if(arrayPer[j].flag_estado==1)
                {
                    if (strcmp(arrayPer[i].nombre,arrayPer[j].nombre)>0)
                    {
                        auxPersonas=arrayPer[i];
                        arrayPer[i]=arrayPer[j];
                        arrayPer[j]=auxPersonas;
                    }
                }
            }
        }
    }

 }

