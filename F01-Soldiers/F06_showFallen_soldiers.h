#ifndef F06_SHOWFALLEN_SOLDIERS_H
#define F06_SHOWFALLEN_SOLDIERS_H
#include "../Sources/outools.h"
#include "../Sources/struct.h"
#include "FZZ_extra.h"

/**
 * @brief Muestra la lista de soldados caídos.
 *
 * @param fallen_soldiers_list Lista de soldados caídos.
 *
 * @details La función recorre la lista de soldados caídos y muestra la información de cada soldado.
 */

void showFallen_soldiers(soldier *fallen_soldiers_list)
{
    if (fallen_soldiers_list == nullptr)
    {
        coutf(RED, "\n\nNo hay soldados caídos para mostrar.");
        return;
    }

    coutf(YELLOW, "\n\nLista de Soldados Caídos:\n");
    coutf(YELLOW, "=========================\n");

    soldier *current_soldier = fallen_soldiers_list;

    while (current_soldier != nullptr)
    {
        coutf(YELLOW, "Nombre: " + current_soldier->name + "\n");
        coutf(YELLOW, "-------------------------\n");
        current_soldier = current_soldier->next;
    }

    return;
};

#endif // F06_SHOWFALLEN_SOLDIERS_H