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

#define TAM 10

char menu();



int main()
{
    eNotebook notebook[TAM];
    eMarca hMarcas[4] = {{1,"Compaq"},{2,"Asus"},{3,"Acer"},{4,"HP"} };
    eTipo hTipos[4] = {{1,"Gamer"},{2,"Disenio"},{3,"Ultrabook"},{4,"Normalita"} };
    eServicio hServicios[4] = {{20000,"Bateria",250},{20001,"Antivirus",300},{20002,"Actualizacion",400},{20003,"Fuente",600}};
    eTrabajo trabajo[TAM];


    inicializarTrabajos(trabajo,TAM);

    int altas = 0;
    char rtamenu;
    int idNotebook = 1;
    int idTrabajo = 1;


    inicializarNotebooks(notebook,TAM);
    do
    {
        rtamenu = menu();
        switch(rtamenu)
        {
        case 'a':
            printf("a\n");
            altaNotebook(notebook,TAM,idNotebook,hMarcas,hTipos);
            idNotebook++;
            altas = 1;
            break;
        case 'b':
            printf("b\n");
            if(altas)
            {
                modificarNotebook(notebook,TAM,hTipos);
            }
            else
            {
                printf("Primero hay que dar un empleado de alta\n");
            }
            break;
        case 'c':
            printf("c\n");
            if(altas)
            {
                bajaNotebook(notebook,TAM);
            }
            else
            {
                printf("Primero hay que dar un empleado de alta\n");
            }
            break;
        case 'd':
            printf("***NOTEBOOKS***\n");
            if(altas)
            {
                imprimirNotebooks(notebook, TAM);
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
            printf("h\n");
            altaTrabajo(trabajo,idTrabajo,notebook,TAM,hServicios);
            idTrabajo++;
            break;
        case 'i':
            printf("i\n");
            listarTrabajos(trabajo,TAM);
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

