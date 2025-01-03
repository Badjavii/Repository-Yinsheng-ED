#ifndef F03_5_USEATTACK_ITEM_H
#define F03_5_USEATTACK_ITEM_H
#include "../../Sources/outools.h"
#include "../../Sources/struct.h"
#include "../../F02-Zombies/FSS_extra.h"
#include "../F04_manageBpck_squad/F04.5_delete_item.h"
#include "../../F02-Zombies/F03_manageZombies_zgroup/F03.5_hurt_zombie.h"
#include "../FZZ_extra.h"

/**
 * @brief Usa un ítem de ataque para hacer daño a un zombie.
 *
 * @param item_list Lista de ítems del soldado.
 * @param zombie_id ID del zombie a atacar.
 * @param zgroup Puntero al grupo de zombies.
 * @details La función busca el ítem de ataque más adecuado para hacer daño al zombie especificado y aplica el daño utilizando la función hurt_Zombie.
 */
void useAttack_item(item **item_list, string soldier_name, int zombie_id, Zgroup *zgroup, Zgroup **zgroup_list, zombie **fallen_zombies_list)
{
    // Buscar el zombie en el grupo
    zombie *target_zombie = searchZombie(zgroup->list_zombies, zombie_id);

    if (target_zombie != nullptr)
    {
        item *current_item = *item_list;
        item *best_item = nullptr;

        // Encontrar el ítem de ataque más adecuado
        while (current_item != nullptr)
        {
            bool is_attack = (current_item->type_item == "Ataque");
            bool is_better_item = (best_item == nullptr ||
                                   (current_item->effect_value >= target_zombie->health && current_item->effect_value < best_item->effect_value) ||
                                   (best_item->effect_value < target_zombie->health && current_item->effect_value > best_item->effect_value));

            if (is_attack && is_better_item)
            {
                best_item = current_item;
            }
            current_item = current_item->next;
        }

        // Usar el ítem de ataque más adecuado
        if (best_item != nullptr)
        {
            int damage = best_item->effect_value;
            coutf(BLUE, "\nSe usó el ítem de ataque " + best_item->name + " para hacer daño al zombie " + to_string(zombie_id) + ".");
            coutf(BLUE, "\nEl " + best_item->name + " tiene un valor de efecto de " + to_string(best_item->effect_value) + ".");

            // Reducir el número de usos del ítem
            best_item->usages--;

            // Si los usos del ítem son 0, eliminarlo
            if (best_item->usages == 0)
            {
                delete_Item(item_list, best_item->name, best_item->usages, best_item->effect_value);
            }

            // Aplicar el daño al zombie
            hurt_Zombie(zgroup_list, zgroup, target_zombie->id, damage, fallen_zombies_list);
        }
        else
        {
            coutf(RED, "\nNo hay ningún ítem de ataque en la mochila de " + soldier_name + ".");
        }
    }
    else
    {
        coutf(RED, "\nNo se encontró el zombie " + to_string(zombie_id) + " en el grupo.");
    }
}

#endif // F03_5_USEATTACK_ITEM_H