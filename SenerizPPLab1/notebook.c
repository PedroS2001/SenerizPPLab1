#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "notebook.h"

void imprimirNotebook(eNotebook notebook)
{
    if(notebook.isEmpty == 0)
    {
        printf("%d  %10s           %d              %d        %.2f\n", notebook.id, notebook.modelo, notebook.idMarca, notebook.idTipo, notebook.precio);
    }

}

void imprimirNotebooks(eNotebook* notebook, int tam)
{
    int i;
    printf("ID      MODELO       IDMARCA        IDTIPO      PRECIO\n");
    for(i=0; i<tam; i++)
    {
        imprimirNotebook(notebook[i]);
    }
}

void inicializarNotebooks(eNotebook* notebook, int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        notebook[i].isEmpty = 1;
    }
    printf("Note Inic");
}

int altaNotebook(eNotebook* notebook,int tam, int idNotebook, eMarca* marca, eTipo* tipo)
{
    system("cls");
    int retorno = -1;
    eNotebook auxiliar;

    printf("***ALTA NOTEBOOK\n***");
    printf("ID %d\n",idNotebook);
    auxiliar.id = idNotebook;
    utn_getNombre(auxiliar.modelo,20,"Ingrese modelo de la notebook: ","Error\n",2);
    listarMarcas(marca,4);
    utn_getNumero(&auxiliar.idMarca,"Ingrese el id de la marca de la notebook","Error\n",1,4,2);
    imprimirTipos(tipo,4);
    utn_getNumero(&auxiliar.idTipo,"Ingrese el id del tipo de la notebook","Error\n",1,4,2);
    utn_getNumeroFlotante(&auxiliar.precio,"Ingrese precio de la notebook ","Error\n",1,99999.9,2 );


    notebook[idNotebook] = auxiliar;
    notebook[idNotebook].isEmpty = 0;
    retorno = 0;

    return retorno;
}

void bajaNotebook(eNotebook* notebook, int tam)
{
    int idABorrar;
    char confirma;
    imprimirNotebooks(notebook,tam);
    utn_getNumero(&idABorrar,"Ingrese el id de la notebook a dar de baja: ", "Error\n", 1, tam, 2);

    imprimirNotebook(notebook[idABorrar]);

    printf("Esta seguro que quiere dar de baja esta notebook?<s o n>");
    fflush(stdin);
    scanf("%c",&confirma);

    if(confirma == 's')
    {
        notebook[idABorrar].isEmpty == 1;
        printf("Notebook eliminada\n");
    }
    else
    {
        printf("Se ha cancelado la baja\n");
    }
}

void modificarNotebook(eNotebook* notebook, int tam, eTipo* tipo)
{
    int id;
    int modifica;
    float nuevoPrecio;
    int nuevoTipo;

    if(utn_getNumero(&id,"Ingrese el id de la notebook a modificar: ", "Error\n", 1, tam, 2) != -1)
    {
        imprimirNotebook(notebook[id]);
        printf("Que desea modificar de esta notebook?\n");
        utn_getNumero(&modifica,"1)Precio2)Tipo3)Cancelar ","Error\n",1,3,2 );
        if(modifica == 1)
        {
            utn_getNumeroFlotante(&nuevoPrecio,"Ingrese nuevo precio: ", "Error\n", 1, 9999.9,2);
            notebook[id].precio = nuevoPrecio;
            printf("\n");
        }
        else if(modifica==2)
        {
            imprimirTipos(tipo,4);
            utn_getNumero(&nuevoTipo,"Ingrese el id del nuevo tipo: ", "Error\n",1,4,2);
            notebook[id].idTipo = nuevoTipo;
            printf("\n");
        }
        else if(modifica==3)
        {
            printf("Se cancelo la modificacion\n");
        }
    }
}
