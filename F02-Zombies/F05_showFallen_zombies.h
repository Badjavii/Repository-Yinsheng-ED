#ifndef F05_SHOWFALLEN_ZOMBIES_H
#define F05_SHOWFALLEN_ZOMBIES_H
#include "../Sources/outools.h"
#include "../Sources/struct.h"
#include "FSS_extra.h"

/**
 * @brief Muestra la lista de zombies caídos.
 *
 * @param fallen_zombies_list Lista de zombies caídos.
 *
 * @details La función recorre la lista de zombies caídos y muestra la información de cada zombie.
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
        coutf(YELLOW, "ID: " + to_string(current_zombie->id) + "\n");
        coutf(YELLOW, "Tipo: " + current_zombie->type + "\n");
        coutf(YELLOW, "-------------------------\n");
        current_zombie = current_zombie->next;
    }

    return;
};

#endif // F05_SHOWFALLEN_ZOMBIES_H