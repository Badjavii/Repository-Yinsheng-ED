#ifndef FILE02_2_ASIGNAR_GRUPO_H
#define FILE02_2_ASIGNAR_GRUPO_H
#include "../sources/structs.h"
#include "../sources/outools.h"
#include "../03-zombies/file05-sources.h"

void AsignarGrupoZombies(EstacionPtr estacion, Zombies_GroupsPtr *zombies_groups_list)
{
    if (isZombiesGroupsListEmpty(*zombies_groups_list))
    {
        coutf(RED, "No hay grupos de zombies disponibles. Cree un grupo de zombies antes de asignarlo a una estación.\n");
        return;
    }

    MostrarResumenGruposZombies(*(zombies_groups_list));
    int numero;
    coutf(BLUE, "Ingrese el número del grupo de zombies a asignar: ");
    cinv("int", numero);

    // Verificar si el grupo de zombies ya está asignado a otra estación
    EstacionPtr actual = estacion;
    while (actual != nullptr)
    {
        if (actual->grupo_zombies != nullptr && actual->grupo_zombies->number == numero)
        {
            coutf(RED, "El grupo de zombies ya está asignado a otra estación.\n");
            return;
        }
        actual = actual->siguiente;
    }

    // Asignar el grupo de zombies
    Zombies_GroupsPtr grupo = *zombies_groups_list;
    while (grupo != nullptr)
    {
        if (grupo->number == numero)
        {
            estacion->grupo_zombies = grupo;
            coutf(GREEN, "Grupo de zombies asignado exitosamente.\n");
            return;
        }
        grupo = grupo->next;
    }
    coutf(RED, "Grupo de zombies no encontrado.\n");
    return;
}

#endif // FILE02_2_ASIGNAR_GRUPO_H