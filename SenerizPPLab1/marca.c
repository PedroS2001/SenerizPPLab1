#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "marca.h"
void listarMarcas(eMarca* marca, int tam)
{
    int i;
    printf("ID   MARCA\n");
    for(i=0;i<tam;i++)
    {
        printf("%d   %s\n", marca[i].id, marca[i].descripcion);
    }
}

int cargarDescripcionMarca(char descripcion[], int id, eMarca marcas[], int tam)
{
    int retorno = -1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(marcas[i].id == id)
        {
            strcpy(descripcion,marcas[i].descripcion);
            retorno = 0;
        }
    }
    return retorno;
}
