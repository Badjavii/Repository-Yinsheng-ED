#ifndef F03_5_HURT_SOLDIER_H
#define F03_5_HURT_SOLDIER_H
#include "../../Sources/outools.h"
#include "../../Sources/struct.h"
#include "../FZZ_extra.h"
#include "F03.3_kill_soldier.h"
#include "F03.4_useDefensive_item.h"
#include "F03.5_useSurvival_item.h"

/**
 * @brief Reduce la vida de un soldado y verifica si debe ser eliminado.
 *
 * @param squad Puntero al escuadrón.
 * @param soldierName Nombre del soldado.
 * @param damage Cantidad de vida a reducir.
 * @param backpack_list Doble puntero a la lista de mochilas.
 *
 * @details La función reduce la vida del soldado especificado en la cantidad indicada. Si la vida del soldado llega a 0 o menos, se aplica la función kill_Soldier para eliminar al soldado.
 */

void hurt_Soldier(squad **squad_list, squad *target_squad, string name, int damage, soldier **fallen_soldier_list, bpck **backpack_list)
{
    // Buscar el soldado
    soldier *target_soldier = searchSoldier(target_squad->list_soldiers, name);

    // Reducir la vida del soldado
    if (target_soldier != nullptr)
    {

        int old_health = target_soldier->health;

        // Si tiene mochila
        if (target_soldier->backpag != nullptr)
        {
            // Reducir el daño recibido utilizando un ítem defensivo en caso de que haya
            damage = useDefensive_item(name, &(target_soldier->backpag->list_items), damage);
        }

        target_soldier->health -= damage;

        coutf(RED, "\nSe le efectuó " + to_string(damage) + " de daño al soldado " + name + "!\n");

        // Verificar si la vida es mayor a 0
        if (target_soldier->health > 0)
        {
            coutf(BLUE, "\nLa vida de " + name + " estaba a " + to_string(old_health) + ", ahora esta a " + to_string(target_soldier->health) + " de salud.\n");
        }
        else // Verificar si la vida llega a 0 o menos
        {
            coutf(RED, "\nLa vida de " + name + " estaba a " + to_string(old_health) + ", ahora esta a en 0 de salud. Va a morir.\n");
            // Matar al soldado
            kill_Soldier(squad_list, target_squad, name, fallen_soldier_list, backpack_list);
        }
    }
    return;
};

#endif // F03_5_HURT_SOLDIER_H