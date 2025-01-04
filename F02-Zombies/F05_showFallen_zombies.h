#ifndef F05_SHOWFALLEN_ZOMBIES_H
#define F05_SHOWFALLEN_ZOMBIES_H
#include "../Sources/outools.h"
#include "../Sources/struct.h"
#include "FSS_extra.h"

/**
 * @brief Muestra la lista de zombies caídos.
 *
 * @param fallen_zombies_list Lista de zombies caídos.
 * @details La función recorre la lista de zombies caídos y muestra la información detallada de los zombies caídos.
 */

void showFallen_zombies(zombie *fallen_zombies_list)
{
    if (fallen_zombies_list == nullptr)
    {
        coutf(RED, "\n\nNo hay zombies caídos para mostrar.");
        return;
    }

    coutf(YELLOW, "\n\nLista de Zombies Caídos:\n");
    coutf(YELLOW, "=========================\n");

    zombie *current_zombie = fallen_zombies_list;
    while (current_zombie != nullptr)
    {
        int count = countTypesZombie(fallen_zombies_list, current_zombie->type);
        if (count > 3)
        {
            coutf(YELLOW, "  - " + to_string(count) + " zombies de tipo " + current_zombie->type +
                              " (daño " + to_string(current_zombie->damage) +
                              " y vida " + to_string(current_zombie->health) + ")\n");

            // Saltar los zombies del mismo tipo
            string type = current_zombie->type;
            while (current_zombie != nullptr && current_zombie->type == type)
            {
                current_zombie = current_zombie->next;
            }
        }
        else
        {
            coutf(YELLOW, "ID: " + to_string(current_zombie->id) + "\n");
            coutf(YELLOW, "Tipo: " + current_zombie->type + "\n");
            coutf(YELLOW, "-------------------------\n");

            current_zombie = current_zombie->next;
        }
    }

    return;
};

#endif // F05_SHOWFALLEN_ZOMBIES_H