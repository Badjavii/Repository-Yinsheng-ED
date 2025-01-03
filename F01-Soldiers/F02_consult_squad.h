#ifndef F02_CONSULT_SQUAD_H
#define F02_CONSULT_SQUAD_H
#include "../Sources/outools.h"
#include "../Sources/struct.h"
#include "FZZ_extra.h"

/**
 * @brief Consulta y muestra la información de los escuadrones en la lista.
 *
 * @param squad_list Puntero a la lista de escuadrones.
 *
 * @details La función recorre la lista de escuadrones y muestra la información detallada de cada escuadrón, incluyendo los soldados y sus mochilas.
 **/

void consult_Squads(squad *squad_list)
{
    if (isSquadListEmpty(squad_list))
    {
        coutf(RED, "\nNo hay escuadrones.");
        return;
    }

    squad *current_squad = squad_list;

    coutf(YELLOW, "\n\nCONSULTA DE ESCUADRONES\n");
    coutf(YELLOW, "========================================\n");

    while (current_squad != nullptr)
    {
        coutf(YELLOW, "\nEscuadrón No. " + to_string(current_squad->number) + ":\n");

        if (isSoldierListEmpty(current_squad->list_soldiers))
        {
            coutf(YELLOW, "  No hay soldados en este escuadrón.\n");
        }
        else
        {
            soldier *current_soldier = current_squad->list_soldiers;
            while (current_soldier != nullptr)
            {
                coutf(YELLOW, "  - Soldado: " + current_soldier->name + "\n");
                coutf(YELLOW, "    Vida: " + to_string(current_soldier->health) + "\n");

                if (current_soldier->backpag == nullptr)
                {
                    coutf(YELLOW, "    Mochila: No tiene mochila.\n");
                }
                else if (isItemListEmpty(current_soldier->backpag->list_items))
                {
                    coutf(YELLOW, "    Mochila: Está vacía.\n");
                }
                else
                {
                    coutf(YELLOW, "    Mochila:\n");
                    item *current_item = current_soldier->backpag->list_items;
                    while (current_item != nullptr)
                    {
                        coutf(YELLOW, "      - Ítem: " + current_item->name + "\n");
                        coutf(YELLOW, "        Tipo: " + current_item->type_item + "\n");
                        coutf(YELLOW, "        Efecto: " + to_string(current_item->effect_value) + "\n");
                        coutf(YELLOW, "        Usos: " + to_string(current_item->usages) + "\n");
                        current_item = current_item->next;
                    }
                }
                current_soldier = current_soldier->next;
            }
        }
        current_squad = current_squad->next;
        coutf(YELLOW, "----------------------------------------\n");
    }
    return;
};

#endif // F02_CONSULT_SQUAD_H
