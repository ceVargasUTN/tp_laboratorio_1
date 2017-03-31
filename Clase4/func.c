#include <stdio.h>
#include <stdlib.h>
#include "func.h"
float promedio(int edad[], int cantidad){

    float retornoPromedio;
    int i, suma=0;

    for(i=0;i<cantidad;i++){
        suma=suma+edad[i];
    }
    retornoPromedio=(float)suma/cantidad;

    return retornoPromedio;
}

void ordenarVector(int vec[], int cantElementos )
{
    int i;
    int j;
    int aux;

    for( i = 0; i < cantElementos-1; i++)
    {
        for( j = i+1; j < cantElementos; j++)
        {
            if(vec[i] > vec[j])
            {
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }

    }
}

int indicarIndiceMinimo(int array[], int cantElementos)
{
    int indice = 1;
    int minimo =  array[0];
    int indiceMinimo =  0;
    for(; indice < cantElementos; indice++)
    {
        if(array[indice]< minimo)
        {
            minimo = array[indice];
            indiceMinimo =  indice;
        }
    }
    return indiceMinimo;
}

float nadiaSort(int array[], int cantElementos, int arrayOrdenado[])
{
    int i;
    int indiceMinimo;
    int sizeInicial= cantElementos;
    for(i = 0; i<cantElementos; i++)
    {
        indiceMinimo = indicarIndiceMinimo(array, cantElementos);
        arrayOrdenado[i] = indiceMinimo(array);
        cantElementos = compactar(array,  cantElementos, indiceMinimo);
    }
}
