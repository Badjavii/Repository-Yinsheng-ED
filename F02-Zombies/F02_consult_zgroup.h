#ifndef F02_CONSULT_ZGROUP_H
#define F02_CONSULT_ZGROUP_H
#include "../Sources/outools.h"
#include "../Sources/struct.h"
#include "FSS_extra.h"

/**
 * @brief Consulta los grupos de zombies y muestra la información detallada.
 *
 * @param zgroup_list Lista de grupos de zombies.
 *
 * @details La función recorre cada grupo de zombies y muestra la información detallada de cada grupo y de los zombies en cada grupo.
 */

void consult_Zgroup(Zgroup *zgroup_list)
{
    if (zgroup_list == nullptr)
    {
        coutf(RED, "\nNo hay grupos de zombies.");
        return;
    }

    Zgroup *current_group = zgroup_list;

    coutf(YELLOW, "\n\nCONSULTA DE GRUPOS DE ZOMBIES\n");
    coutf(YELLOW, "========================================\n");

    while (current_group != nullptr)
    {
        coutf(YELLOW, "\nGrupo de Zombies No. " + to_string(current_group->number) + ":\n");

        if (current_group->list_zombies == nullptr)
        {
            coutf(YELLOW, "  No hay zombies en este grupo.\n");
        }
        else
        {
            zombie *current_zombie = current_group->list_zombies;
            while (current_zombie != nullptr)
            {
                coutf(YELLOW, "  - Zombie ID: " + to_string(current_zombie->id) + "\n");
                coutf(YELLOW, "    Tipo: " + current_zombie->type + "\n");
                coutf(YELLOW, "    Salud: " + to_string(current_zombie->health) + "\n");
                coutf(YELLOW, "    Daño: " + to_string(current_zombie->damage) + "\n");

                current_zombie = current_zombie->next;
            }
        }

        current_group = current_group->next;
        coutf(YELLOW, "----------------------------------------\n");
    }

    return;
};

#endif // F02_CONSULT_ZGROUP_H