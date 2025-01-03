#ifndef F06_SHOWLIVING_ZOMBIES_H
#define F06_SHOWLIVING_ZOMBIES_H
#include "../Sources/outools.h"
#include "../Sources/struct.h"
#include "FSS_extra.h"

/**
 * @brief Muestra los nombres de los zombies que están vivos en cada grupo de zombies.
 *
 * @param zgroup_list Lista de grupos de zombies.
 * @details La función recorre cada grupo de zombies y muestra los nombres de los zombies que están vivos.
 */

void showLiving_Zombies(Zgroup *zgroup_list)
{
    if (zgroup_list == nullptr)
    {
        coutf(RED, "\n\nNo hay grupos de zombies para mostrar.\n");
        return;
    }

    coutf(GREEN, "\n\nZOMBIES VIVOS POR GRUPO\n");
    coutf(GREEN, "=============================\n");

    while (zgroup_list != nullptr)
    {
        coutf(GREEN, "Grupo de Zombies: " + to_string(zgroup_list->number) + "\n");

        if (zgroup_list->target_station != nullptr)
        {
            coutf(GREEN, "Estación: " + zgroup_list->target_station->name + ".\n");
        }

        coutf(GREEN, "Zombies Vivos:\n");

        zombie *current_zombie = zgroup_list->list_zombies;

        while (current_zombie != nullptr)
        {
            coutf(GREEN, "  - ID: " + to_string(current_zombie->id) + "\n");
            coutf(GREEN, "    Tipo: " + current_zombie->type + "\n");

            current_zombie = current_zombie->next;
        }

        coutf(GREEN, "-----------------------------\n");
        zgroup_list = zgroup_list->next;
    }
    return;
};

#endif // F06_SHOWLIVING_ZOMBIES_H