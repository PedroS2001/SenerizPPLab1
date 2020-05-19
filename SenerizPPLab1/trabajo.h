#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include "fecha.h"
#include "notebook.h"
#include "servicio.h"

typedef struct
{
    int id;
    int idNotebook;
    int idServicio;
    eFecha fecha;
    int hayTrabajo;
}eTrabajo;

#endif // TRABAJO_H_INCLUDED


void inicializarTrabajos(eTrabajo* trabajo, int tam);
void altaTrabajo(eTrabajo* trabajo, eTrabajo auxTrabajo, int id);
void listarTrabajos(eTrabajo* trabajo, int tam, eServicio servicios[], int tamser);


