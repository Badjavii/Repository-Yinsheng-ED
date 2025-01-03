#ifndef F03_2_DELETE_SOLDIER_H
#define F03_2_DELETE_SOLDIER_H
#include "../../Sources/outools.h"
#include "../../Sources/struct.h"
#include "../FZZ_extra.h"
#include "../F04_manageBpck_squad/F04.2_delete_bpck.h"

/**
 * @brief Elimina un soldado de la lista de soldados y su mochila de la lista de mochilas.
 *
 * @param soldier_list Doble puntero a la lista de soldados.
 * @param soldier_name Nombre del soldado a eliminar.
 * @param backpack_list Doble puntero a la lista de mochilas.
 */

void delete_Soldier(soldier **soldier_list, const string &soldier_name, bpck **backpack_list)
{
    // Verificar si la lista de soldados está vacía
    if (*soldier_list == nullptr)
    {
        return;
    }

    soldier *current = *soldier_list;
    soldier *prev = nullptr;

    // Buscar el soldado a eliminar
    while (current != nullptr)
    {
        if (current->name == soldier_name)
        {
            // Eliminar la mochila del soldado
            if (current->backpag != nullptr)
            {
                delete_Bpck(current, backpack_list);
            }

            // Desconectar el soldado de la lista de soldados
            if (prev == nullptr)
            {
                // El soldado a eliminar es el primero en la lista
                *soldier_list = current->next;
            }
            else
            {
                prev->next = current->next;
            }

            // Desconectar con su oponente
            current->opponent = nullptr;

            // Desconectar el nodo antes de eliminarlo
            current->next = nullptr;

            // Liberar la memoria del soldado eliminado
            delete current;
            return;
        }

        prev = current;
        current = current->next;
    }
    return;
};

#endif // F03_2_DELETE_SOLDIER_H