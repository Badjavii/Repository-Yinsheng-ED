#ifndef F03_5_HURT_ZOMBIE_H
#define F03_5_HURT_ZOMBIE_H
#include "../../Sources/outools.h"
#include "../../Sources/struct.h"
#include "F03.4_kill_zombie.h"
#include "../FSS_extra.h"

/**
 * @brief Reduce la vida de un zombie y verifica si debe ser eliminado.
 *
 * @param zgroup_list Doble puntero a la lista de grupos de zombies.
 * @param target_group Puntero al grupo de zombies.
 * @param zombie_id ID del zombie a dañar.
 * @param damage Cantidad de daño a infligir al zombie.
 * @param fallen_zombie_list Lista de zombies caídos.
 *
 * @details La función reduce la vida del zombie especificado en la cantidad indicada y verifica si debe ser eliminado.
 */

void hurt_Zombie(Zgroup **zgroup_list, Zgroup *target_group, int zombie_id, int damage, zombie **fallen_zombie_list)
{
    // Buscar el zombie
    zombie *target_zombie = searchZombie(target_group->list_zombies, zombie_id);

    // Reducir la vida del zombie
    if (target_zombie != nullptr)
    {
        target_zombie->health -= damage;

        coutf(RED, "\nSe le efectuó " + to_string(damage) + " de daño al zombie con ID " + to_string(zombie_id) + "!");

        // Verificar si la vida es mayor a 0
        if (target_zombie->health > 0)
        {
            coutf(BLUE, "\nLa vida del zombie con ID " + to_string(zombie_id) + " está a " + to_string(target_zombie->health) + " de salud.");
        }
        else // Verificar si la vida llega a 0 o menos
        {
            coutf(RED, "\nLa vida del zombie con ID " + to_string(zombie_id) + " está en 0 de salud. Va a ser eliminado.");
            // Matar al zombie
            kill_Zombie(zgroup_list, target_group, zombie_id, fallen_zombie_list);
        }
    }
    return;
};

#endif // F03_5_HURT_ZOMBIE_H