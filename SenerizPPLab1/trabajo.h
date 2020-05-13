#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include "fecha.h"

typedef struct
{
    int id;
    int idNotebook;
    int idServicio;
    eFecha fecha;
    int hayTrabajo;
}eTrabajo;


#endif // TRABAJO_H_INCLUDED
void listarTrabajos(eTrabajo* trabajo, int tam);
void inicializarTrabajos(eTrabajo* trabajo, int tam);
void altaTrabajo(eTrabajo* trabajo, int id, eNotebook* notebook, int tamnot, eServicio* servicio);
