#ifndef F06_SHOWLIVING_ZOMBIES_H
#define F06_SHOWLIVING_ZOMBIES_H
#include "../Sources/outools.h"
#include "../Sources/struct.h"
#include "FSS_extra.h"

/**
 * @brief Muestra los zombies vivos por grupo.
 *
 * @param zgroup_list Lista de grupos de zombies.
 * @details La función recorre cada grupo de zombies y muestra la información detallada de los zombies vivos en cada grupo.
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

        int num_zombies = countZombie(zgroup_list->list_zombies);
        if (num_zombies == 0)
        {
            coutf(GREEN, "No hay zombies vivos en este grupo.\n");
        }
        else if (num_zombies > 3)
        {
            // Mostrar resumen de los zombies
            zombie *current_zombie = zgroup_list->list_zombies;
            while (current_zombie != nullptr)
            {
                int count = countTypesZombie(zgroup_list->list_zombies, current_zombie->type);
                string type = current_zombie->type;
                int damage = current_zombie->damage;
                int health = current_zombie->health;

                coutf(GREEN, "  - " + to_string(count) + " zombies de tipo " + type +
                                 " (daño " + to_string(damage) +
                                 " y vida " + to_string(health) + ")\n");

                // Saltar los zombies del mismo tipo
                while (current_zombie != nullptr && current_zombie->type == type)
                {
                    current_zombie = current_zombie->next;
                }
            }
        }
        else
        {
            // Mostrar detalles de cada zombie
            zombie *current_zombie = zgroup_list->list_zombies;
            while (current_zombie != nullptr)
            {
                coutf(GREEN, "  - ID: " + to_string(current_zombie->id) + "\n");
                coutf(GREEN, "    Tipo: " + current_zombie->type + "\n");

                current_zombie = current_zombie->next;
            }
        }

        coutf(GREEN, "-----------------------------\n");
        zgroup_list = zgroup_list->next;
    }
    return;
};

#endif // F06_SHOWLIVING_ZOMBIES_H