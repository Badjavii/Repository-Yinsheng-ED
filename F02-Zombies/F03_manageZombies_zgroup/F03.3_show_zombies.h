#ifndef F03_3_SHOW_ZOMBIES_H
#define F03_3_SHOW_ZOMBIES_H
#include "../../Sources/outools.h"
#include "../../Sources/struct.h"
#include "../FSS_extra.h"

/**
 * @brief Muestra todos los zombies con sus detalles.
 *
 * @param zombie_list Lista de zombies.
 * @details La función recorre la lista de zombies y muestra la información de cada zombie.
 */

void show_zombies(zombie *zombie_list)
{
    if (zombie_list == nullptr)
    {
        coutf(RED, "\n\nNo hay zombies para mostrar.\n");
        return;
    }

    coutf(RED, "\n\nDETALLE DE ZOMBIES\n");
    coutf(RED, "=============================\n");

    while (zombie_list != nullptr)
    {
        coutf(RED, "ID: " + to_string(zombie_list->id) + "\n");
        coutf(RED, "Tipo: " + zombie_list->type + "\n");
        coutf(RED, "Salud: " + to_string(zombie_list->health) + "\n");
        coutf(RED, "Daño: " + to_string(zombie_list->damage) + "\n");

        coutf(RED, "-----------------------------\n");
        zombie_list = zombie_list->next;
    }

    return;
};

#endif // F03_3_SHOW_ZOMBIES_H