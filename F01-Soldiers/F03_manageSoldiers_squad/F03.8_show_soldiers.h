#ifndef F03_8_SHOW_SOLDIERS_H
#define F03_8_SHOW_SOLDIERS_H
#include "../../Sources/outools.h"
#include "../../Sources/struct.h"
#include "../FZZ_extra.h"

/**
 * @brief Muestra todos los soldados con sus ítems.
 *
 * @param soldier_list Lista de soldados.
 * @details La función recorre la lista de soldados y muestra la información de cada soldado, incluyendo los ítems en su mochila.
 */

void show_soldiers(soldier *soldier_list)
{

    if (isSoldierListEmpty(soldier_list) == true)
    {
        coutf(BLUE, "\n\nNo hay soldados para mostrar.\n");
        return;
    }

    coutf(BLUE, "\n\nDETALLE DE SOLDADOS\n");
    coutf(BLUE, "=============================\n");

    while (soldier_list != nullptr)
    {
        coutf(BLUE, "Soldado: " + soldier_list->name + "\n");
        coutf(BLUE, "Salud: " + to_string(soldier_list->health) + "\n");

        if (soldier_list->backpag == nullptr)
        {
            coutf(BLUE, "Mochila: No tiene mochila.\n");
        }
        else
        {
            coutf(BLUE, "Mochila: " + soldier_list->backpag->name + "\n");
            if (soldier_list->backpag->list_items == nullptr)
            {
                coutf(BLUE, "Items: La mochila está vacía.\n");
            }
            else
            {
                coutf(BLUE, "Items:\n");
                item *current_item = soldier_list->backpag->list_items;
                while (current_item != nullptr)
                {
                    coutf(BLUE, "  - Nombre: " + current_item->name + "\n");
                    coutf(BLUE, "    Tipo: " + current_item->type_item + "\n");
                    coutf(BLUE, "    Usos: " + to_string(current_item->usages) + "\n");
                    coutf(BLUE, "    Efecto: " + to_string(current_item->effect_value) + "\n");
                    current_item = current_item->next;
                }
            }
        }
        coutf(BLUE, "-----------------------------\n");
        soldier_list = soldier_list->next;
    }

    return;
};

#endif // F03_8_SHOW_SOLDIERS_H