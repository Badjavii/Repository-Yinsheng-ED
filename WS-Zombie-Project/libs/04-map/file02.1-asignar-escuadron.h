#ifndef FILE02_1_ASIGNAR_ESCUADRON_H
#define FILE02_1_ASIGNAR_ESCUADRON_H
#include "../sources/structs.h"
#include "../sources/outools.h"
#include "../02-squads-soldiers/file11-sources.h"

void AsignarEscuadronAntizombies(EstacionPtr estacion, SquadsPtr *squad_list)
{
    if (isSquadsListEmpty(*squad_list))
    {
        coutf(RED, "No hay escuadrones antizombies disponibles. Cree un escuadrón antes de asignarlo a una estación.\n");
        return;
    }

    MostrarTotalEscuadrones(*squad_list);

    int numero;
    coutf(BLUE, "Ingrese el número del escuadrón antizombies a asignar: ");
    cinv("int", numero);

    // Verificar si el escuadrón ya está asignado a otra estación
    EstacionPtr actual = estacion;
    while (actual != nullptr)
    {
        if (actual->escuadron_antizombies != nullptr && actual->escuadron_antizombies->number == numero)
        {
            coutf(RED, "El escuadrón antizombies ya está asignado a otra estación.\n");
            return;
        }
        actual = actual->siguiente;
    }

    // Asignar el escuadrón antizombies
    SquadsPtr escuadron = *squad_list;
    while (escuadron != nullptr)
    {
        if (escuadron->number == numero)
        {
            estacion->escuadron_antizombies = escuadron;
            coutf(GREEN, "Escuadrón antizombies asignado exitosamente.\n");
            return;
        }
        escuadron = escuadron->next;
    }
    coutf(RED, "Escuadrón antizombies no encontrado.\n");
    return;
}

#endif // FILE02_1_ASIGNAR_ESCUADRON_H