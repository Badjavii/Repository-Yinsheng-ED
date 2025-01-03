#ifndef F04_2_DELETE_BPCK_H
#define F04_2_DELETE_BPCK_H
#include "../../Sources/outools.h"
#include "../../Sources/struct.h"
#include "../FZZ_extra.h"
#include "F04.5_delete_item.h"

/**
 * @brief Elimina una mochila de la lista de mochilas y de la referencia del soldado.
 *
 * @param soldier Puntero al soldado al cual pertenece la mochila.
 * @param backpack_list Puntero doble a la cabeza de la lista de mochilas.
 *
 * @details Esta función recorre la lista de mochilas para encontrar la mochila que pertenece al soldado especificado. Una vez encontrada, elimina todos los ítems de la mochila usando la función `delete_Item` y luego elimina la mochila de la lista de mochilas, desconectando el puntero del soldado.
 *
 * @return La función no retorna ningún valor.
 */

void delete_Bpck(soldier *soldier, bpck **backpack_list)
{
    bpck *current = *backpack_list;
    bpck *prev = nullptr;

    while (current != nullptr)
    {
        if (current->name == soldier->backpag->name)
        {
            // Desconectar la mochila del soldado
            soldier->backpag = nullptr;

            // Eliminar todos los ítems de la mochila
            while (current->list_items != nullptr)
            {
                delete_Item(&current->list_items, current->list_items->name, current->list_items->usages, current->list_items->effect_value);
            }

            // Eliminar la mochila de la lista de mochilas
            if (prev == nullptr)
            { // La mochila a eliminar es la primera en la lista
                *backpack_list = current->next;
            }
            else
            {
                prev->next = current->next;
            }

            // Desconectar el nodo antes de eliminarlo
            current->next = nullptr;

            delete current; // Liberar la memoria de la mochila eliminada
            return;
        }
        prev = current;
        current = current->next;
    }
    return;
};

#endif // F04_2_DELETE_BPCK_H