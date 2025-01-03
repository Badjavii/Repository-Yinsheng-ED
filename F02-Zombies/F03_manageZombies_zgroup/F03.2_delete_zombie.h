#ifndef F03_2_DELETE_ZOMBIE_H
#define F03_2_DELETE_ZOMBIE_H
#include "../../Sources/outools.h"
#include "../../Sources/struct.h"
#include "../FSS_extra.h"

/**
 * @brief Elimina un zombie de la lista de zombies.
 *
 * @param zombie_list Doble puntero a la lista de zombies.
 * @param zombie_id ID del zombie a eliminar.
 * @details La función elimina el zombie especificado de la lista de zombies y libera la memoria asociada.
 */

void delete_Zombie(zombie **zombie_list, int zombie_id)
{
    // Verificar si la lista de zombies está vacía
    if (*zombie_list == nullptr)
    {
        return;
    }

    zombie *current = *zombie_list;
    zombie *prev = nullptr;

    // Buscar el zombie a eliminar
    while (current != nullptr)
    {
        if (current->id == zombie_id)
        {
            // Desconectar el zombie de la lista de zombies
            if (prev == nullptr)
            {
                // El zombie a eliminar es el primero en la lista
                *zombie_list = current->next;
            }
            else
            {
                prev->next = current->next;
            }

            // Desconectar con su oponente
            current->opponent = nullptr;

            // Desconectar el nodo antes de eliminarlo
            current->next = nullptr;

            // Liberar la memoria del zombie eliminado
            delete current;
            return;
        }

        prev = current;
        current = current->next;
    }
    return;
};

#endif // F03_2_DELETE_ZOMBIE_H