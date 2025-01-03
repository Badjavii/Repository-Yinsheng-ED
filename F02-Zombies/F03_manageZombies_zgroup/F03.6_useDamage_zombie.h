#ifndef F03_6_USE_DAMAGE_ZOMBIE_H
#define F03_6_USE_DAMAGE_ZOMBIE_H
#include "../../Sources/outools.h"
#include "../../Sources/struct.h"
#include "../../F01-Soldiers/F03_manageSoldiers_squad/F03.6_hurt_soldier.h"
#include "../FSS_extra.h"

/**
 * @brief Usa el daño de un zombie para atacar a un soldado.
 *
 * @param squad_list Doble puntero a la lista de escuadrones.
 * @param soldier_name Nombre del soldado a atacar.
 * @param zombie_id ID del zombie que atacará.
 * @param zgroup Puntero al grupo de zombies.
 * @param fallen_soldier_list Lista de soldados caídos.
 * @param backpack_list Doble puntero a la lista de mochilas.
 *
 * @details La función hace que un zombie ataque a un soldado utilizando su estadística de damage y aplica el daño utilizando la función hurt_Soldier.
 */

void useDamage_Zombie(squad **squad_list, const string &soldier_name, int zombie_id, Zgroup *zgroup, soldier **fallen_soldier_list, bpck **backpack_list)
{
    // Buscar el zombie en el grupo
    zombie *target_zombie = searchZombie(zgroup->list_zombies, zombie_id);

    if (target_zombie != nullptr)
    {
        int damage = target_zombie->damage;
        coutf(RED, "\nEl zombie con ID " + to_string(zombie_id) + " ataca al soldado " + soldier_name + " con " + to_string(damage) + " de daño.");

        // Aplicar el daño al soldado
        hurt_Soldier(squad_list, *squad_list, soldier_name, damage, fallen_soldier_list, backpack_list);
    }
    else
    {
        coutf(RED, "\nNo se encontró el zombie " + to_string(zombie_id) + " en el grupo.");
    }
    return;
}

#endif // F03_6_USE_DAMAGE_ZOMBIE_H