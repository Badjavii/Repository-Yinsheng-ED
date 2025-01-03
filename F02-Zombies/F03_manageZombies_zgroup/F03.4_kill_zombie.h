#ifndef F03_4_KILL_ZOMBIE_H
#define F03_4_KILL_ZOMBIE_H
#include "../../Sources/outools.h"
#include "../../Sources/struct.h"
#include "F03.2_delete_zombie.h"
#include "F03.7_addFallen_zombie.h"
#include "../F04_delete_zgroup.h"
#include "../FSS_extra.h"

/**
 * @brief Mata a un zombie añadiéndolo a la lista de zombies caídos y luego eliminándolo.
 *
 * @param zgroup_list Doble puntero a la lista de grupos de zombies.
 * @param target_group Puntero al grupo de zombies.
 * @param zombie_id ID del zombie a eliminar.
 * @param fallen_zombie_list Lista de zombies caídos.
 *
 * @details La función añade una copia del zombie a la lista de zombies caídos y luego elimina el zombie.
 *          Si ya no hay zombies en el grupo, se elimina el grupo de zombies.
 */

void kill_Zombie(Zgroup **zgroup_list, Zgroup *target_group, int zombie_id, zombie **fallen_zombie_list)
{
    // Añadir una copia del zombie a la lista de zombies caídos
    zombie *target_zombie = searchZombie(target_group->list_zombies, zombie_id);
    if (target_zombie != nullptr)
    {
        addFallen_zombie(fallen_zombie_list, zombie_id, target_zombie->type);

        // Eliminar el zombie
        delete_Zombie(&(target_group->list_zombies), zombie_id);

        coutf(BLUE, "\n\nEl zombie con ID " + to_string(zombie_id) + " ha sido eliminado.");

        // Si ya no hay zombies en el grupo, eliminar el grupo de zombies
        if (isZombieListEmpty(target_group->list_zombies) == true)
        {
            delete_Zgroup(zgroup_list, target_group->number);
            coutf(BLUE, "\n\nTodo el grupo de zombies " + to_string(target_group->number) + " ha sido eliminado.");
        }
    }
    return;
}

#endif // F03_4_KILL_ZOMBIE_H