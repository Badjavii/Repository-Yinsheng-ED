#ifndef F07_SHOWLIVING_SOLDIERS_H
#define F07_SHOWLIVING_SOLDIERS_H
#include "../Sources/outools.h"
#include "../Sources/struct.h"
#include "FZZ_extra.h"

/**
 * @brief Muestra los nombres de los soldados que están vivos en cada escuadrón.
 *
 * @param squad_list Lista de escuadrones.
 * @details La función recorre cada escuadrón y muestra los nombres de los soldados que están vivos.
 */

void showLiving_soldiers(squad *squad_list)
{

    if (isSquadListEmpty(squad_list) == true)
    {
        coutf(RED, "\n\nNo hay escuadrones para mostrar.\n");
    }

    coutf(GREEN, "\n\nSOLDADOS VIVOS POR ESCUADRÓN\n");
    coutf(GREEN, "=============================\n");

    while (squad_list != nullptr)
    {
        coutf(GREEN, "Escuadrón: " + to_string(squad_list->number) + "\n");
        coutf(GREEN, "Soldados Vivos: " + to_string(countSoldier(squad_list->list_soldiers)) + ".\n");

        soldier *current_soldier = squad_list->list_soldiers;

        while (current_soldier != nullptr)
        {

            coutf(GREEN, "  - " + current_soldier->name + "\n");
            current_soldier = current_soldier->next;
        }

        coutf(GREEN, "-----------------------------\n");
        squad_list = squad_list->next;
    }
    return;
};

#endif // F07_SHOWLIVING_SOLDIERS_H