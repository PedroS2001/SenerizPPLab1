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

void inicializarNotebooks(eNotebook* notebook, int tam);
void imprimirNotebook(eNotebook notebook, eMarca* marca, eTipo* tipo);
void imprimirNotebooks(eNotebook* notebook, int tam,eMarca* marca, eTipo* tipo);
int altaNotebook(eNotebook* notebook,int tam, int idNotebook,eMarca* marca,eTipo* tipo);
void modificarNotebook(eNotebook* notebook, int tam, eTipo* tipo, eMarca* marca, int idNotebook);
void bajaNotebook(eNotebook* notebook, int tam, eMarca* marca, eTipo* tipo, int idNotebook);
