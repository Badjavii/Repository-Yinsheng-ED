#ifndef F04_5_DELETE_ITEM_H
#define F04_5_DELETE_ITEM_H
#include "../../Sources/outools.h"
#include "../../Sources/struct.h"
#include "../FZZ_extra.h"

/**
 * @brief Elimina un ítem de una lista de ítems basado en nombre, tipo, usos y valor de efecto.
 *
 * @param item_list Puntero a la cabeza de la lista de ítems.
 * @param name Nombre del ítem a eliminar.
 * @param type Tipo del ítem a eliminar.
 * @param usages Usos del ítem a eliminar.
 * @param effect_value Valor de efecto del ítem a eliminar.
 *
 * @details Esta función recorre la lista de ítems y elimina el ítem que coincide con los parámetros especificados. Si el ítem es encontrado, se elimina de la lista y la memoria es liberada.
 *
 * @return La función no retorna ningún valor.
 */

void delete_Item(item **item_list, string name, int usages, int effect_value)
{
    item *current = *item_list;
    item *prev = nullptr;

    while (current != nullptr)
    {
        if ((current->name == name) && (current->usages == usages) && (current->effect_value == effect_value))
        {
            if (prev == nullptr)
            { // El ítem a eliminar es el primero en la lista
                *item_list = current->next;
            }
            else
            {
                prev->next = current->next;
            }

            // Desconectar el nodo antes de eliminarlo
            current->next = nullptr;

            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
    return;
};

#endif // F04_5_DELETE_ITEM_H