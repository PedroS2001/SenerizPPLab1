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
