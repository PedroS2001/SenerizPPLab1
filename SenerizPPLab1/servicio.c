#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicio.h"

void listarServicios(eServicio* servicio, int tam)
{
    printf(" ID       DESCRIPCION    PRECIO\n");
    for(int i=0; i<tam; i++)
    {
        printf("%d %15s    %.2f\n",servicio[i].id, servicio[i].descripcion, servicio[i].precio);
    }
}
