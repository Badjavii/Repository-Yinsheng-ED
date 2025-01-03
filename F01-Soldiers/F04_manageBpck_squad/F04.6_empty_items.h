#ifndef F04_6_EMPTY_ITEMS_H
#define F04_6_EMPTY_ITEMS_H
#include "../../Sources/outools.h"
#include "../../Sources/struct.h"
#include "../FZZ_extra.h"

/**
 * @brief Conecta la lista de ítems de final_list con la lista de ítems de initial_list.
 *
 * @param initial_list Lista de ítems que se conectará a la lista de final_list.
 * @param final_list Lista de ítems que se recorrerá hasta el último ítem.
 *
 * @details La función recorre la lista de ítems de final_list hasta llegar al último ítem y conecta su next con la cabeza de la lista de ítems de initial_list. Luego, desconecta initial_list de su lista de ítems.
 */

void empty_Items(item **initial_list, item **final_list)
{
    // Si final_list está vacía, simplemente conectamos la cabeza de initial_list a final_list
    if (*final_list == nullptr)
    {
        *final_list = *initial_list;
    }
    else
    {
        // Recorrer final_list hasta llegar al último ítem
        item *current_item = *final_list;
        while (current_item->next != nullptr)
        {
            current_item = current_item->next;
        }

        // Conectar el último ítem de final_list con la cabeza de initial_list
        current_item->next = *initial_list;
    }

    // Desconectar la cabeza de initial_list de su lista de ítems
    *initial_list = nullptr;
    return;
};

#endif // F04_6_EMPTY_ITEMS_H