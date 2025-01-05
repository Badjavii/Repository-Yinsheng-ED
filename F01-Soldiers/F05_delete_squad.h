#ifndef F05_DELETE_SQUAD_H
#define F05_DELETE_SQUAD_H
#include "../Sources/outools.h"
#include "../Sources/struct.h"
#include "FZZ_extra.h"

/**
 * @brief Elimina un escuadrón y todos los soldados asociados.
 *
 * @param squad_list Doble puntero a la lista de escuadrones.
 * @param number_squad Numero del escuadrón a eliminar.
 * @param backpack_list Doble puntero a la lista de mochilas.
 * @details La función elimina el escuadrón especificado de la lista de escuadrones y también elimina todos los soldados asociados al escuadrón.
 */

void delete_Squad(squad **squad_list, int number_squad, bpck **backpack_list)
{
    // Verificar si la lista de escuadrones está vacía
    if (isSquadListEmpty(*squad_list) == true)
    {
        return;
    }

    squad *current_squad = *squad_list;
    squad *prev_squad = nullptr;

    // Buscar el escuadrón a eliminar
    while (current_squad != nullptr)
    {
        if (current_squad->number == number_squad)
        {
            // Eliminar todos los soldados del escuadrón
            soldier *current_soldier = current_squad->list_soldiers;
            while (current_soldier != nullptr)
            {
                soldier *next_soldier = current_soldier->next;
                delete_Soldier(&(current_squad->list_soldiers), current_soldier->name, backpack_list);
                current_soldier = next_soldier;
            }

            // Desconectar el escuadrón de la lista de escuadrones
            if (prev_squad == nullptr)
            {
                // El escuadrón a eliminar es el primero en la lista
                *squad_list = current_squad->next;
            }
            else
            {
                prev_squad->next = current_squad->next;
            }

            // Desconectar el nodo antes de eliminarlo
            current_squad->next = nullptr;

            // Desconectar el nodo de la estación
            current_squad->target_station->target_squad = nullptr;
            current_squad->target_station = nullptr;

            // Liberar la memoria del escuadrón eliminado
            delete current_squad;
            return;
        }

        prev_squad = current_squad;
        current_squad = current_squad->next;
    }
    return;
};

#endif // F05_DELETE_SQUAD_H