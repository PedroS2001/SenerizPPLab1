#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"

void imprimirTipos(eTipo* tipo, int tam)
{
    int i;
    printf("ID   TIPO\n");
    for(i=0;i<tam;i++)
    {
        printf("%d   %s\n",tipo[i].id, tipo[i].descripcion);
    }
}

int cargarDescripcionTipo(char descripcion[], int id, eTipo tipos[], int tam)
{
    int retorno = -1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(tipos[i].id == id)
        {
            strcpy(descripcion,tipos[i].descripcion);
            retorno = 0;
        }
    }
    return retorno;
}
