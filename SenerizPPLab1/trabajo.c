#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabajo.h"
#include "notebook.h"
#include "servicio.h"
#include "utn.h"

/** \brief da de alta un trabajo pidiendole al usuario que elija una notebook, un servicio e ingrese una fecha
 *
 * \param estructura de trabajos
 * \param id que va a tener el trabajo
 * \param estructura de notebooks
 * \param tamaño de la estructura de notebooks
 * \param estructura de servicios
 * \param estructura de marcas
 * \param estructura de tipos
 *
 * \return 0 si pudo cargar el trabajo y -1 si tuvo algun error
 */

int altaTrabajo(eTrabajo* trabajo, int id, eNotebook* notebook, int tamnot, eServicio* servicio, eMarca* marca, eTipo* tipo)
{
    int retorno = -1;
    eTrabajo auxiliar;
    auxiliar.id = id;

    printf("%d",id);
    imprimirNotebooks(notebook,tamnot,marca,tipo);
    utn_getNumero(&auxiliar.idNotebook,"Ingrese el id de la notebook ", "Error\n", 1,tamnot,2 );
    listarServicios(servicio,4);
    utn_getNumero(&auxiliar.idServicio, "Ingrese el id del servicio ", "Error\n",20000,20004,2 );
    utn_getNumero(&auxiliar.fecha.dia,"Ingrese el dia: ", "Dia invalido\n",1,31,2 );
    utn_getNumero(&auxiliar.fecha.mes,"Ingrese el mes: ", "Mes invalido\n",1,12,2 );
    utn_getNumero(&auxiliar.fecha.anio,"Ingrese el anio: ", "Anio invalido. Los registros van desde 2010 a 2020\n",2010,2020,2 );
    auxiliar.hayTrabajo = 0;

    trabajo[id] = auxiliar;
    retorno = 0;

    return retorno;
}

/** \brief imprime los trabajos dados de alta
 *
 * \param estructura de trabajos
 * \param tamaño de la estructura de trabajos
 * \param estructura de servicios
 * \param cantidad de servicios
 * \return
 *
 */

void listarTrabajos(eTrabajo* trabajo, int tam, eServicio servicios[], int tamser)
{
    int i;
    char nombreServicio[20];

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

/** \brief inicializa todos los trabajos como vacios
 *
 * \param estructura de trabajos
 * \param tamaño de la estructura
 *
 */

void inicializarTrabajos(eTrabajo* trabajo, int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        trabajo[i].hayTrabajo = 1;
    }
}

