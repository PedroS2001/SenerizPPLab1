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
#include "datawarehouse.h"

#define TAM 10

char menu();
int hardcodearNotebooks(eNotebook* notebook, int cant);

int main()
{
    eNotebook notebook[TAM];
    eMarca hMarcas[4] = {{1000,"Compaq"},{1001,"Asus"},{1002,"Acer"},{1003,"HP"} };
    eTipo hTipos[4] = {{5000,"Gamer"},{5001,"Disenio"},{5002,"Ultrabook"},{5003,"Normalita"} };
    eServicio hServicios[4] = {{20000,"Bateria",250},{20001,"Antivirus",300},{20002,"Actualizacion",400},{20003,"Fuente",600}};
    eTrabajo trabajo[TAM];


    int flagAltas = 0;
    char rtamenu;
    int idNotebook = 1;
    int idTrabajo = 1;

    inicializarTrabajos(trabajo,TAM);
    inicializarNotebooks(notebook,TAM);

    hardcodearNotebooks(notebook,7);
    flagAltas = 1;
    idNotebook += 7;


    do
    {
        rtamenu = menu();
        switch(rtamenu)
        {
        case 'a':
            altaNotebook(notebook,TAM,idNotebook,hMarcas,hTipos);
            idNotebook++;
            flagAltas = 1;
            break;
        case 'b':
            if(flagAltas)
            {
                modificarNotebook(notebook,TAM,hTipos,hMarcas,idNotebook);
            }
            else
            {
                printf("Primero hay que dar un empleado de alta\n");
            }
            break;
        case 'c':
            if(flagAltas)
            {
                bajaNotebook(notebook,TAM,hMarcas,hTipos, idNotebook);
            }
            else
            {
                printf("Primero hay que dar un empleado de alta\n");
            }
            break;
        case 'd':
            printf("***NOTEBOOKS***\n");
            if(flagAltas)
            {
                imprimirNotebooks(notebook, TAM, hMarcas, hTipos);
            }
            else
            {
                printf("Primero hay que dar un empleado de alta\n");
            }
            break;
        case 'e':
            printf("***MARCAS***\n");
            listarMarcas(hMarcas,4);
            break;
        case 'f':
            printf("***TIPOS***\n");
            imprimirTipos(hTipos,4);
            break;
        case 'g':
            printf("***SERVICIOS***\n");
            listarServicios(hServicios,4);
            break;
        case 'h':
            altaTrabajo(trabajo,idTrabajo,notebook,TAM,hServicios,hMarcas,hTipos);
            idTrabajo++;
            break;
        case 'i':
            listarTrabajos(trabajo,TAM,hServicios,4);
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
    printf("d)LISTAR NOTEBOOKS\n");
    printf("e)LISTAR MARCAS\n");
    printf("f)LISTAR TIPOS\n");
    printf("g)LISTAR SERVICIOS\n");
    printf("h)ALTA TRABAJO\n");
    printf("I)LISTAR TRABAJOS\n");
    printf("j)SALIR\n");
    utn_getCaracter(&respuesta,"Que desea hacer? ","Error. Asegurese que la letra este en minusculas\n",'a','j',2);

    return respuesta;
}

int hardcodearNotebooks(eNotebook* notebook, int cant)
{
    int i;
    for(i=0;i<cant;i++)
    {
        notebook[i].id = hardodeIds[i];
        strcpy(notebook[i].modelo, hardcodeModelos[i]);
        notebook[i].idMarca = hardcodeIdMarca[i];
        notebook[i].idTipo = hardcodeIdTipo[i];
        notebook[i].precio = hardcodePrecios[i];
        notebook[i].isEmpty = 0;
    }
    return 0;
}
