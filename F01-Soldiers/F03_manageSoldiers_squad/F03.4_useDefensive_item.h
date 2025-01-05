#ifndef F03_7_USEDEFENSIVE_ITEM_H
#define F03_7_USEDEFENSIVE_ITEM_H
#include "../../Sources/outools.h"
#include "../../Sources/struct.h"
#include "../FZZ_extra.h"
#include "F03.2_delete_soldier.h"
#include "../F04_manageBpck_squad/F04.5_delete_item.h"

/**
 * @brief Utiliza el ítem defensivo más efectivo para reducir el daño que está a punto de recibir un soldado.
 *
 * La función recorre la lista de ítems del soldado, encuentra el ítem defensivo más adecuado para
 * reducir el daño que está a punto de recibir, lo utiliza, y luego actualiza los usos del ítem.
 * Si los usos del ítem llegan a cero, se elimina de la lista usando la función delete_Item.
 *
 * @param item_list Puntero a la lista de ítems del soldado.
 * @param damage Cantidad de daño que el soldado va a recibir.
 *
 * @return int Nuevo valor de daño que va a recibir el soldado después de usar el ítem defensivo.
 *
 * La condición is_better_item se utiliza para determinar si el ítem actual es mejor que el mejor ítem encontrado hasta ahora.
 * La condición es verdadera si:
 * - best_item es nulo (es decir, no se ha encontrado ningún ítem defensivo aún).
 * - El effect_value del ítem actual es mayor o igual al daño que el soldado va a recibir y menor que el effect_value del mejor ítem encontrado hasta ahora.
 * - El effect_value del mejor ítem encontrado hasta ahora es menor que el daño que el soldado va a recibir y el effect_value del ítem actual es mayor que el effect_value del mejor ítem encontrado hasta ahora.
 *
 * La otra condición es solo para verificar que el item sea de tipe defensivo.
 */

int useDefensive_item(string soldier_name, item **item_list, int damage)
{
    item *current = *item_list;
    item *best_item = nullptr;

    // Encuentra el ítem defensivo más adecuado
    while (current != nullptr)
    {
        bool is_defensive = (current->type_item == "Defensa");
        bool is_better_item = (best_item == nullptr ||
                               (current->effect_value >= damage && current->effect_value < best_item->effect_value) ||
                               (best_item->effect_value < damage && current->effect_value > best_item->effect_value));

        if (is_defensive && is_better_item)
        {
            best_item = current;
        }
        current = current->next;
    }

    // Si se encontró un ítem defensivo, úsalo para reducir el daño
    if (best_item != nullptr)
    {
        int new_damage = damage - best_item->effect_value;
        if (new_damage < 0)
            new_damage = 0; // En caso de que el daño sea negativo

        coutf(BLUE, "\nSe hizo uso de item defensivo " + best_item->name + " para reducir el daño.\n");
        coutf(BLUE, "\nEl " + best_item->name + " tiene un valor de efecto de " + to_string(best_item->effect_value) + ".\n");
        coutf(BLUE, "\nEl uso de " + best_item->name + " redujó el daño que recibirá el soldado de " + to_string(damage) + " a " + to_string(new_damage) + ".\n");

        // Reduce el número de usos del ítem
        best_item->usages--;

        // Si los usos del ítem son 0, elimínalo
        if (best_item->usages == 0)
        {
            delete_Item(item_list, best_item->name, best_item->usages, best_item->effect_value);
        }
        return new_damage;
    }
    else
        coutf(RED, "\nNo hay ningun item de defensa en la mochila de " + soldier_name + ".\n");
    return damage;
};

#endif // F03_7_USEDEFENSIVE_ITEM_H