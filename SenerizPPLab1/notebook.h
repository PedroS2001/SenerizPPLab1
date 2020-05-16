#ifndef NOTEBOOK_H_INCLUDED
#define NOTEBOOK_H_INCLUDED
#include "marca.h"
#include "tipo.h"


typedef struct
{
    int id;
    char modelo[20];
    int idMarca;
    int idTipo;
    float precio;
    int isEmpty;
}eNotebook;

#endif // NOTEBOOK_H_INCLUDED

int altaNotebook(eNotebook* notebook,int tam, int idNotebook,eMarca* marca,eTipo* tipo);
//void imprimirNotebook(eNotebook notebook);
void imprimirNotebook(eNotebook notebook, eMarca marca, eTipo tipo);
//void imprimirNotebooks(eNotebook* notebook, int tam);
void imprimirNotebooks(eNotebook* notebook, int tam,eMarca* marca, eTipo* tipo);
void inicializarNotebooks(eNotebook* notebook, int tam);
//void bajaNotebook(eNotebook* notebook, int tam);//ARREGLAR
//void modificarNotebook(eNotebook* notebook, int tam, eTipo* tipo);
void modificarNotebook(eNotebook* notebook, int tam, eTipo* tipo, eMarca* marca);
void bajaNotebook(eNotebook* notebook, int tam, eMarca* marca, eTipo* tipo);
