#ifndef F04_3_CONSULT_BPCK_H
#define F04_3_CONSULT_BPCK_H
#include "../../Sources/outools.h"
#include "../../Sources/struct.h"
#include "../FZZ_extra.h"

/**
 * @brief Consulta y muestra las mochilas de los soldados en un escuadrón.
 *
 * @param backpack_list Puntero a la lista de mochilas.
 * @param soldier_list Puntero a la lista de soldados.
 *
 * @details Esta función recorre la lista de mochilas y muestra la información de las mochilas que pertenecen a los soldados del escuadrón. La información incluye los ítems dentro de cada mochila.
 *
 * @return La función no retorna ningún valor.
 **/

void consult_Bpck(bpck *backpack_list, soldier *soldier_list)
{
    if (isBpckListEmpty(backpack_list))
    {
        coutf(RED, "\nNo hay mochilas.");
        return;
    }

    coutf(BLUE, "\n\nCONSULTA DE MOCHILAS\n");
    coutf(BLUE, "========================================\n");

    // Iterar sobre la lista de soldados para mostrar solo las mochilas correspondientes
    soldier *current_soldier = soldier_list;

    while (current_soldier != nullptr)
    {
        bpck *current_bpck = backpack_list;

        while (current_bpck != nullptr)
        {
            // Mostrar solo las mochilas que pertenecen a los soldados del escuadrón
            if (current_bpck->name == current_soldier->name)
            {
                coutf(BLUE, "\nMochila de " + current_bpck->name + " contiene:\n");
                if (isItemListEmpty(current_bpck->list_items))
                {
                    coutf(BLUE, "  Está vacía.\n");
                }
                else
                {
                    item *current_item = current_bpck->list_items;
                    int i = 1;
                    while (current_item != nullptr)
                    {
                        coutf(BLUE, "  - Ítem #" + to_string(i++) + ": " + current_item->name + " (" + current_item->type_item + ")\n");
                        coutf(BLUE, "    Efecto: " + to_string(current_item->effect_value) + "\n");
                        coutf(BLUE, "    Usos: " + to_string(current_item->usages) + "\n");
                        current_item = current_item->next;
                    }
                }
                coutf(BLUE, "----------------------------------------\n");
            }
            current_bpck = current_bpck->next;
        }
        current_soldier = current_soldier->next;
    }
    return;
};

#endif // F04_3_CONSULT_BPCK_H