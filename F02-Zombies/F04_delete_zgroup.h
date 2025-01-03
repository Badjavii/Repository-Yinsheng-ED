#ifndef F04_DELETE_ZGROUP_H
#define F04_DELETE_ZGROUP_H
#include "../Sources/outools.h"
#include "../Sources/struct.h"
#include "F03_manageZombies_zgroup/F03.2_delete_zombie.h"
#include "FSS_extra.h"

/**
 * @brief Elimina un grupo de zombies y todos los zombies asociados.
 *
 * @param zgroup_list Doble puntero a la lista de grupos de zombies.
 * @param group_number Número del grupo a eliminar.
 *
 * @details La función elimina el grupo de zombies especificado de la lista de grupos de zombies y también elimina todos los zombies asociados al grupo.
 */

void delete_Zgroup(Zgroup **zgroup_list, int group_number)
{
    // Verificar si la lista de grupos de zombies está vacía
    if (*zgroup_list == nullptr)
    {
        return;
    }

    Zgroup *current_group = *zgroup_list;
    Zgroup *prev_group = nullptr;

    // Buscar el grupo de zombies a eliminar
    while (current_group != nullptr)
    {
        if (current_group->number == group_number)
        {
            // Eliminar todos los zombies del grupo
            zombie *current_zombie = current_group->list_zombies;
            while (current_zombie != nullptr)
            {
                zombie *next_zombie = current_zombie->next;
                delete_Zombie(&(current_group->list_zombies), current_zombie->id);
                current_zombie = next_zombie;
            }

            // Desconectar el grupo de la lista de grupos
            if (prev_group == nullptr)
            {
                // El grupo a eliminar es el primero en la lista
                *zgroup_list = current_group->next;
            }
            else
            {
                prev_group->next = current_group->next;
            }

            // Si el grupo esta conectado con una estación, se desconectará
            if (current_group->target_station != nullptr)
            {
                current_group->target_station->amount_zombies = 0;
                current_group->target_station->target_group = nullptr;
                current_group->target_station = nullptr;
            }

            // Desconectar el nodo antes de eliminarlo
            current_group->next = nullptr;

            // Liberar la memoria del grupo eliminado
            delete current_group;
            return;
        }

        prev_group = current_group;
        current_group = current_group->next;
    }
    return;
};

#endif // F04_DELETE_ZGROUP_H