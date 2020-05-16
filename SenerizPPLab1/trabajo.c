#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabajo.h"
#include "notebook.h"
#include "servicio.h"
#include "utn.h"

int altaTrabajo(eTrabajo* trabajo, int id, eNotebook* notebook, int tamnot, eServicio* servicio, eMarca* marca, eTipo* tipo)
{
    eTrabajo auxiliar;
    auxiliar.id = id;

    printf("%d",id);
    imprimirNotebooks(notebook,tamnot,marca,tipo);
    utn_getNumero(&auxiliar.idNotebook,"Ingrese el id de la notebook ", "Error\n", 1,tamnot,2 );
    listarServicios(servicio,4);
    utn_getNumero(&auxiliar.idServicio, "Ingrese el id del servicio ", "Error\n",20000,20004,2 );
    utn_getNumero(&auxiliar.fecha.dia,"Ingrese el dia: ", "Dia invalido\n",1,31,2 );
    utn_getNumero(&auxiliar.fecha.mes,"Ingrese el mes: ", "mes invalido\n",1,12,2 );
    utn_getNumero(&auxiliar.fecha.anio,"Ingrese el anio: ", "anio invalido. Los registros van desde 2010 a 2020\n",2010,2020,2 );
    auxiliar.hayTrabajo = 0;

    trabajo[id] = auxiliar;


    return 0;
}


void listarTrabajos(eTrabajo* trabajo, int tam, eServicio servicios[], int tamser)
{
    int i;
    char nombreServicio[20];

    system("cls");
    printf("IDNOTEBOOK        SERVICIO           FECHA\n");


    for(i=0; i<tam; i++)
    {
        if(trabajo[i].hayTrabajo == 0)
        {
            cargarDescripcionServicio(nombreServicio,trabajo[i].idServicio,servicios,tamser);
            printf("  %d         %15s        %02d/%02d/%04d\n",trabajo[i].idNotebook,nombreServicio,trabajo[i].fecha.dia,trabajo[i].fecha.mes,trabajo[i].fecha.anio);
        }
    }
}

void inicializarTrabajos(eTrabajo* trabajo, int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        trabajo[i].hayTrabajo = 1;
    }
    printf("tab Inic");
}



int cargarDescripcionServicio(char descripcion[], int id, eServicio servicios[], int tam)
{
    int retorno = -1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(servicios[i].id == id)
        {
            strcpy(descripcion,servicios[i].descripcion);
            retorno = 0;
        }
    }
    return retorno;
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
