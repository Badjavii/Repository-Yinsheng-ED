#ifndef FILE02_EDITAR_GRUPO_H
#define FILE02_EDITAR_GRUPO_H
#include "../sources/outools.h"
#include "../sources/structs.h"
#include "file02.1-agregar-zombie.h"
#include "file02.2-editar-zombie.h"
#include "file02.3-eliminar-zombie.h"
#include "file05-sources.h"

void Menu_EditarGrupoZombie(Zombies_GroupsPtr zombie_group_list, SquadsPtr squad_list)
{
    if (zombie_group_list == nullptr)
    {
        coutf(RED, "No hay grupos zombies para editar.\n");
        return;
    }

    // Mostrar resumen de todos los grupos zombies
    MostrarResumenGruposZombies(zombie_group_list);

    int group_number;
    coutf(GREEN, "Indique el número del grupo zombie a editar: ");
    cinv("int", group_number);

    Zombies_GroupsPtr current_group = zombie_group_list;
    while (current_group != nullptr && current_group->number != group_number)
    {
        current_group = current_group->next;
    }

    if (current_group == nullptr)
    {
        coutf(RED, "Grupo zombie no encontrado.\n");
        PAUSE_TERMINAL;
        return;
    }

    int op = -1;
    while (op)
    {
        CLEAR_SCREEN;
        coutf(BLUE, "\t\tMENU DE EDICIÓN DEL GRUPO ZOMBIE " + to_string(current_group->number) + "\n\n");
        coutf(BLUE, "1. Agregar zombie al grupo\n");
        coutf(BLUE, "2. Editar un zombie\n");
        coutf(BLUE, "3. Eliminar zombie del grupo\n\n");
        coutf(BLUE, "0. REGRESAR\n\n");

        // Mostrar resumen del grupo zombie actual
        MostrarResumenGrupoZombie(current_group);

        cinv("int", op); // Usar cinv para obtener y validar la entrada del usuario

        switch (op)
        {
        case 1:
            AgregarZombie(current_group, zombie_group_list, squad_list);
            break;
        case 2:
        {
            string zombie_name;
            coutf(GREEN, "Indique el nombre del zombie a editar: ");
            cinv("string", zombie_name);

            Zombies *current_zombie = current_group->zombies;
            while (current_zombie != nullptr && current_zombie->name != zombie_name)
            {
                current_zombie = current_zombie->next;
            }

            if (current_zombie == nullptr)
            {
                coutf(RED, "Zombie no encontrado.\n");
                PAUSE_TERMINAL;
            }
            else
            {
                Menu_EditarZombie(current_zombie, zombie_group_list, squad_list);
            }
        }
        break;
        case 3:
            EliminarZombie(current_group);
            break;
        case 0:
            return;
        default:
            coutf(RED, "Opción inválida. Inténtalo de nuevo.\n");
            break;
        }
        PAUSE_TERMINAL;
    }
    return;
}

#endif