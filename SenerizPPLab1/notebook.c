#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "notebook.h"
#include "servicio.h"
#include "tipo.h"
#include "marca.h"
#include "trabajo.h"
#include "utn.h"

void imprimirNotebook(eNotebook notebook, eMarca* marca, eTipo* tipo)
{
    char descTipo[20];
    char descMarca[20];
    cargarDescripcionMarca(descMarca, notebook.idMarca,marca,4);
    cargarDescripcionTipo(descTipo, notebook.idTipo, tipo,4);

    if(notebook.isEmpty == 0)
    {
        printf("%d  %10s  %10s    %10s    %.2f\n", notebook.id, notebook.modelo, descMarca, descTipo, notebook.precio);
    }

}

void imprimirNotebooks(eNotebook* notebook, int tam, eMarca marca[], eTipo* tipo)
{
    int i;

    printf("ID      MODELO       MARCA        TIPO      PRECIO\n");
    for(i=0; i<tam; i++)
    {
        imprimirNotebook(notebook[i], marca, tipo);
    }
}

void inicializarNotebooks(eNotebook* notebook, int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        notebook[i].isEmpty = 1;
    }
}

int altaNotebook(eNotebook* notebook,int tam, int idNotebook, eMarca* marca, eTipo* tipo)
{
    int retorno = -1;
    eNotebook auxiliar;

    system("cls");
    printf("***ALTA NOTEBOOK***\n\n");
    printf("ID %d\n",idNotebook);
    auxiliar.id = idNotebook;
    utn_getNombre(auxiliar.modelo,20,"Ingrese modelo de la notebook: ","Error\n",2);
    listarMarcas(marca,4);
    utn_getNumero(&auxiliar.idMarca,"Ingrese el id de la marca de la notebook: ","Error\n",1000,1003,2);
    imprimirTipos(tipo,4);
    utn_getNumero(&auxiliar.idTipo,"Ingrese el id del tipo de la notebook: ","Error\n",5000,5003,2);
    utn_getNumeroFlotante(&auxiliar.precio,"Ingrese precio de la notebook: ","Error\n",1,99999.9,2 );


    notebook[idNotebook] = auxiliar;
    notebook[idNotebook].isEmpty = 0;
    retorno = 0;

    return retorno;
}

void bajaNotebook(eNotebook* notebook, int tam, eMarca* marca, eTipo* tipo, int idNotebook)
{
    int idABorrar;
    char confirma;
    system("cls");
    printf("***BAJA NOTEBOOK***\n\n");
    imprimirNotebooks(notebook,tam,marca,tipo);
    utn_getNumero(&idABorrar,"Ingrese el id de la notebook a dar de baja: ", "No existe notebook con ese id. Reingrese\n", 1, idNotebook-1, 2);

    imprimirNotebook(notebook[idABorrar-1],marca,tipo);

    printf("Esta seguro que quiere dar de baja esta notebook?<s o n> ");
    fflush(stdin);
    scanf("%c",&confirma);

    if(confirma == 's')
    {
        notebook[idABorrar-1].isEmpty = 1;
        printf("Notebook eliminada\n");
    }
    else
    {
        printf("Se ha cancelado la baja\n");
    }
}

void modificarNotebook(eNotebook* notebook, int tam, eTipo* tipo, eMarca* marca, int idNotebook)
{
    int id;
    int modifica;
    float nuevoPrecio;
    int nuevoTipo;
    system("cls");
    printf("***MODIFICAR NOTEBOOK***\n\n");

    imprimirNotebooks(notebook,tam,marca,tipo);

    if(utn_getNumero(&id,"Ingrese el id de la notebook a modificar: ", "No existe notebook con ese id. Reingrese\n", 1, idNotebook-1, 2) != -1)
    {
        if(notebook[id-1].isEmpty == 0)
        {
            imprimirNotebook(notebook[id-1],marca,tipo);
            printf("Que desea modificar de esta notebook? \n");
            utn_getNumero(&modifica,"1)Precio\n2)Tipo\n3)Cancelar ","Error\n",1,3,2 );
            if(modifica == 1)
            {
                utn_getNumeroFlotante(&nuevoPrecio,"Ingrese nuevo precio: ", "Error\n", 1, 99999.9,2);
                notebook[id-1].precio = nuevoPrecio;
                printf("\n");
            }
            else if(modifica==2)
            {
                imprimirTipos(tipo,4);
                utn_getNumero(&nuevoTipo,"Ingrese el id del nuevo tipo: ", "Error\n",5000,5003,2);
                notebook[id-1].idTipo = nuevoTipo;
                printf("\n");
            }
            else if(modifica==3)
            {
                printf("Se cancelo la modificacion\n");
            }
        }
        else
        {
            printf("Esa notebook fue eliminada \n");
        }
    }
}
