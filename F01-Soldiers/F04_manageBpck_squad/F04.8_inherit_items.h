#ifndef F04_8_INHERIT_ITEMS_H
#define F04_8_INHERIT_ITEMS_H
#include "../../Sources/outools.h"
#include "../../Sources/struct.h"
#include "../FZZ_extra.h"
#include "F04.1_add_bpck.h"
#include "F04.2_delete_bpck.h"
#include "F04.6_empty_items.h"

/**
 * @brief Hereda los ítems de una mochila a otra y elimina la mochila vaciada.
 *
 * @param squad Puntero al escuadrón.
 * @param name Nombre de la mochila a vaciar y eliminar.
 *
 * @details La función busca una mochila a la cual vaciar su lista de ítems y luego elimina la mochila vaciada.
 *          Si el soldado heredero no tiene mochila, se le crea una.
 *          La lógica es la siguiente:
 *          1. Se busca el soldado que tiene la mochila especificada utilizando la función searchSoldier.
 *          2. Se cuenta el número de soldados en el escuadrón utilizando la función countSoldier.
 *          3. Si hay más de un soldado en el escuadrón, se procede a buscar un soldado heredero.
 *             - Se busca un soldado siguiente o el primer soldado en la lista.
 *             - Se verifica si el soldado heredero tiene una mochila. Si no tiene, se crea una nueva mochila utilizando las funciones create_Bpck y add_Bpck.
 *          4. Si se encuentra un soldado heredero, se llama a la función empty_Items para transferir los ítems a la mochila heredera.
 *          5. Finalmente, se llama a la función delete_Bpck para eliminar la mochila vaciada del escuadrón.
 */

void inherit_Items(squad *object_squad, string name, bpck **backpack_list)
{
    // Buscar el soldado que tiene la mochila 'name'
    soldier *current_soldier = searchSoldier(object_squad->list_soldiers, name);

    // PRUEBA
    if ((current_soldier == nullptr) || (current_soldier->backpag == nullptr) || (current_soldier->backpag->list_items == nullptr))
    {
        return;
    }

    bpck *current_bpck = current_soldier->backpag;

    // Verificar si hay más de un soldado en el escuadrón
    if (countSoldier(object_squad->list_soldiers) > 1)
    {
        // Buscar un soldado previo o siguiente que tenga una mochila o crear una nueva
        soldier *inherit_to_soldier = nullptr;
        if (current_soldier->next != nullptr)
        {
            inherit_to_soldier = current_soldier->next;
        }
        else
        {
            inherit_to_soldier = object_squad->list_soldiers; // Primer soldado en la lista
        }

        // Verificar si el soldado heredero tiene mochila, sino crear una
        if (inherit_to_soldier->backpag == nullptr)
        {
            add_Bpck(inherit_to_soldier, backpack_list, create_Bpck(inherit_to_soldier->name));
        }

        // Vaciar los ítems de la mochila actual a la mochila heredera
        empty_Items(&(current_bpck->list_items), &(inherit_to_soldier->backpag->list_items));
        coutf(BLUE, "\nAhora los items de " + current_bpck->name + " se encuentran en la mochila de " + inherit_to_soldier->backpag->name + ".");
    }

    // Eliminar la mochila vaciada
    delete_Bpck(current_soldier, backpack_list);
    return;
};

#endif // F04_8_INHERIT_ITEMS_H