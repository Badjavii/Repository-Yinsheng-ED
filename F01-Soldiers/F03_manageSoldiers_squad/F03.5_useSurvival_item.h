#ifndef F03_6_USESURVIVAL_ITEM_H
#define F03_6_USESURVIVAL_ITEM_H

/**
 * @brief Usa ítems de supervivencia para curar a un soldado hasta que su vida llegue a 100 o hasta que no queden más ítems de supervivencia.
 *
 * @param soldier_list Lista de soldados.
 * @param soldier_name Nombre del soldado a curar.
 * @details La función busca los ítems de supervivencia más adecuados para curar la vida del soldado especificado. La vida del soldado se curará hasta llegar a 100 o hasta que no queden más ítems de supervivencia.
 */

void useSurvival_item(soldier **soldier_list, string soldier_name)
{
    // Buscar el soldado
    soldier *target_soldier = searchSoldier(*soldier_list, soldier_name);

    if (target_soldier != nullptr)
    {
        item *current_item = target_soldier->backpag->list_items;
        while (current_item != nullptr && target_soldier->health < 100)
        {
            item *best_item = nullptr;
            item *prev_item = nullptr;
            item *best_prev_item = nullptr;

            // Encontrar el ítem de supervivencia más adecuado
            while (current_item != nullptr)
            {
                bool is_survival = (current_item->type_item == "Supervivencia");
                bool is_better_item = (best_item == nullptr ||
                                       (current_item->effect_value >= (100 - target_soldier->health) && current_item->effect_value < best_item->effect_value) ||
                                       (best_item->effect_value < (100 - target_soldier->health) && current_item->effect_value > best_item->effect_value));

                if (is_survival && is_better_item)
                {
                    best_item = current_item;
                    best_prev_item = prev_item;
                }
                prev_item = current_item;
                current_item = current_item->next;
            }

            // Usar el ítem de supervivencia más adecuado
            if (best_item != nullptr)
            {
                int heal_amount = best_item->effect_value;
                target_soldier->health += heal_amount;
                if (target_soldier->health > 100)
                {
                    target_soldier->health = 100;
                }

                coutf(BLUE, "\nSe usó el ítem de supervivencia " + best_item->name + " para curar al soldado " + soldier_name + ".");
                coutf(BLUE, "\nEl " + best_item->name + " tiene un valor de efecto de " + to_string(best_item->effect_value) + ".");
                coutf(BLUE, "\nLa salud del soldado " + soldier_name + " ahora es " + to_string(target_soldier->health) + ".");

                // Reducir el número de usos del ítem
                best_item->usages--;

                // Si los usos del ítem son 0, eliminarlo
                if (best_item->usages == 0)
                {
                    delete_Item(&(target_soldier->backpag->list_items), best_item->name, best_item->usages, best_item->effect_value);
                }
                current_item = target_soldier->backpag->list_items; // Reiniciar la búsqueda de ítems
            }
            else
                coutf(RED, "\nNo hay ningun item de supervivencia en la mochila de " + soldier_name + ".");
        }
    }
    return;
};

#endif // F03_6_USESURVIVAL_ITEM_H