#ifndef F02_CONSULT_ZGROUP_H
#define F02_CONSULT_ZGROUP_H
#include "../Sources/outools.h"
#include "../Sources/struct.h"
#include "FSS_extra.h"

/**
 * @brief Consulta los grupos de zombies y muestra la información detallada.
 *
 * @param zgroup_list Lista de grupos de zombies.
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

        int num_zombies = countZombie(current_group->list_zombies);
        if (num_zombies == 0)
        {
            coutf(YELLOW, "  No hay zombies en este grupo.\n");
        }
        else
        {
            zombie *current_zombie = current_group->list_zombies;

            while (current_zombie != nullptr)
            {
                string type = current_zombie->type;
                int damage = current_zombie->damage;
                int health = current_zombie->health;
                int count = countTypesZombie(current_group->list_zombies, type);

                coutf(YELLOW, "  - Tipo " + type + " (vida " + to_string(health) + " y daño " + to_string(damage) + ") : " + to_string(count) + ". IDs:\n");

                int ids_printed = 0;
                zombie *z = current_group->list_zombies;
                while (z != nullptr)
                {
                    if (z->type == type)
                    {
                        if (ids_printed > 0 && ids_printed % 10 == 0)
                        {
                            coutf(YELLOW, "\n");
                        }
                        coutf(YELLOW, "#" + to_string(z->id));
                        if (ids_printed < count - 1)
                        {
                            coutf(YELLOW, " , ");
                        }
                        ids_printed++;
                    }
                    z = z->next;
                }
                coutf(YELLOW, "\n");

                // Saltar los zombies del mismo tipo
                while (current_zombie != nullptr && current_zombie->type == type)
                {
                    current_zombie = current_zombie->next;
                }
            }
        }

        current_group = current_group->next;
        coutf(YELLOW, "----------------------------------------\n");
    }

    return;
}

#endif // F02_CONSULT_ZGROUP_H