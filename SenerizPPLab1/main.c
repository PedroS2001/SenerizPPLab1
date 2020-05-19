#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fecha.h"
#include "marca.h"
#include "tipo.h"
#include "notebook.h"
#include "servicio.h"
#include "trabajo.h"
#include "utn.h"

#define TAMNOTE 20
#define TTRABAJO 20
#define CANTHARD 15

char menu();


int main()
{
    eNotebook notebook[TAMNOTE];
    eMarca hMarcas[] = {{1000,"Compaq"},{1001,"Asus"},{1002,"Acer"},{1003,"HP"} };
    eTipo hTipos[] = {{5000,"Gamer"},{5001,"Disenio"},{5002,"Ultrabook"},{5003,"Normalita"} };
    eServicio hServicios[] = {{20000,"Bateria",250},{20001,"Antivirus",300},{20002,"Actualizacion",400},{20003,"Fuente",600}};
    eTrabajo trabajo[TTRABAJO];

    eNotebook auxNotebook;
    eTrabajo auxTrabajo;

    int flagAltas = 0;
    char rtamenu;
    int idNotebook = 1;
    int idTrabajo = 1;

    inicializarTrabajos(trabajo,TTRABAJO);
    inicializarNotebooks(notebook,TAMNOTE);

    hardcodearNotebooks(notebook,CANTHARD);
    flagAltas = 1;
    idNotebook += CANTHARD;


    do
    {
        rtamenu = menu();
        switch(rtamenu)
        {
        case 'a':
            if(idNotebook <= TAMNOTE)
            {
                system("cls");
                printf("***ALTA NOTEBOOK***\n\n");
                printf("ID %d\n",idNotebook);
                if(utn_getNombre(auxNotebook.modelo,20,"Ingrese modelo de la notebook: ","Error",2) == -1)
                {
                    printf("ALTA INTERRUMPIDA\n");
                    printf("\nError al ingresar el modelo\n\n");
                    break;
                }

                listarMarcas(hMarcas,4);
                if(utn_getNumero(&auxNotebook.idMarca,"Ingrese el id de la marca de la notebook: ","Error\n",1000,1003,2) == -1)
                {
                    printf("ALTA INTERRUMPIDA\n");
                    printf("\nError al ingresar la marca\n\n");
                    break;
                }

                listarTipos(hTipos,4);
                if(utn_getNumero(&auxNotebook.idTipo,"Ingrese el id del tipo de la notebook: ","Error\n",5000,5003,2) == -1)
                {
                    printf("ALTA INTERRUMPIDA\n");
                    printf("\nError al ingresar el tipo\n\n");
                    break;
                }

                if(utn_getNumeroFlotante(&auxNotebook.precio,"Ingrese precio de la notebook: ","Error\n",1,99999.9,2 ) == -1)
                {
                    printf("ALTA INTERRUMPIDA\n");
                    printf("\nError al ingresar el precio\n\n");
                    break;
                }
                altaNotebook(notebook, auxNotebook, idNotebook);

                idNotebook++;
                flagAltas = 1;
                printf("\nSE DIO DE ALTA UNA NOTEBOOK\n\n");
            }
            else
            {
                printf("\nNO HAY LUGAR DISPONIBLE\n\n");
            }
            break;
        case 'b':
            if(flagAltas)
            {
                modificarNotebook(notebook,TAMNOTE,hTipos,hMarcas,idNotebook);
            }
            else
            {
                printf("Primero hay que dar una notebook de alta\n");
            }
            break;
        case 'c':
            if(flagAltas)
            {
                bajaNotebook(notebook,TAMNOTE,hMarcas,hTipos, idNotebook);
            }
            else
            {
                printf("Primero hay que dar una notebook de alta\n");
            }
            break;
        case 'd':
            printf("***NOTEBOOKS***\n");
            if(flagAltas)
            {
                ordenarNotebooksPorMarcaYPrecio(notebook,TAMNOTE,hMarcas);
                imprimirNotebooks(notebook, TAMNOTE, hMarcas, hTipos);
                ordenarXID(notebook,TAMNOTE,hMarcas);
            }
            else
            {
                printf("Primero hay que dar una notebook de alta\n");
            }
            break;
        case 'e':
            printf("***MARCAS***\n");
            listarMarcas(hMarcas,4);
            break;
        case 'f':
            printf("***TIPOS***\n");
            listarTipos(hTipos,4);
            break;
        case 'g':
            printf("***SERVICIOS***\n");
            listarServicios(hServicios,4);
            break;
        case 'h':

            system("cls");
            printf("***ALTA TRABAJO***\n");
            printf("%d\n\n",idTrabajo);
            imprimirNotebooks(notebook,TAMNOTE,hMarcas,hTipos);
            if(utn_getNumero(&auxTrabajo.idNotebook,"Ingrese el id de la notebook ", "Error\n", 1,idNotebook-1,2) == -1)
            {
                printf("ERROR AL CARGAR EL ID\n");
                break;
            }

            listarServicios(hServicios,4);
            if(utn_getNumero(&auxTrabajo.idServicio, "Ingrese el id del servicio ", "Error\n",20000,20003,2) == -1)
            {
                printf("ERROR AL CARGAR EL SERVICIO\n");
                break;

            }

            if(utn_getNumero(&auxTrabajo.fecha.dia,"Ingrese el dia: ", "Dia invalido\n",1,31,2) == -1)
            {
                printf("ERROR AL CARGAR EL DIA\n");
                break;

            }

            if(utn_getNumero(&auxTrabajo.fecha.mes,"Ingrese el mes: ", "Mes invalido\n",1,12,2)== -1)
            {
                printf("ERROR AL CARGAR EL MES\n");
                break;

            }

            if(utn_getNumero(&auxTrabajo.fecha.anio,"Ingrese el anio: ", "Anio invalido. Los registros van desde 2010 a 2020\n",2010,2020,2)== -1)
            {
                printf("ERROR AL CARGAR EL ANIO\n");
                break;

            }

            altaTrabajo(trabajo,auxTrabajo,idTrabajo);
            idTrabajo++;

            break;
        case 'i':
            if(idTrabajo > 1)
            {
                system("cls");
                printf("***TRABAJOS***\n\n");
                imprimirNotebooks(notebook,TAMNOTE,hMarcas,hTipos);
                listarTrabajos(trabajo,TTRABAJO,hServicios,4);
            }
            else
            {
                printf("\nPRIMERO DEBE DAR DE ALTA ALGUN TRABAJO\n\n");
            }
            break;
        case 'j':
            printf("Saliendo\n");
            break;
        }
        system("pause");
        system("cls");
    }
    while(rtamenu != 'j');



    return 0;
}

char menu()
{
    char respuesta;

    printf("****MENU****\n\n");
    printf("a)ALTA NOTEBOOK\n");
    printf("b)MODIFICAR NOTEBOOK\n");
    printf("c)BAJA NOTEBOOK\n");
    printf("d)LISTAR NOTEBOOKS POR MARCA Y PRECIO\n");
    printf("e)LISTAR MARCAS\n");
    printf("f)LISTAR TIPOS\n");
    printf("g)LISTAR SERVICIOS\n");
    printf("h)ALTA TRABAJO\n");
    printf("I)LISTAR TRABAJOS\n");
    printf("j)SALIR\n");
    utn_getCaracter(&respuesta,"Que desea hacer? ","Error. Asegurese que la letra este en minusculas\n",'a','j',2);

    return respuesta;
}
