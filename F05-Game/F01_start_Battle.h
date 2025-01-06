#ifndef F01_START_BATTLE_H
#define F01_START_BATTLE_H
#include "../Sources/outools.h"
#include "../Sources/struct.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "../F01-Soldiers/F03_manageSoldiers_squad/F03.5_useSurvival_item.h"
#include "../F01-Soldiers/F03_manageSoldiers_squad/F03.7_useAttack_item.h"
#include "../F02-Zombies/F03_manageZombies_zgroup/F03.6_useDamage_zombie.h"

void reassignOpponents(soldier *soldiers, zombie *zombies)
{
    soldier *current_soldier = soldiers;
    zombie *current_zombie = zombies;

    while (current_soldier != nullptr)
    {
        if (current_zombie == nullptr)
        {
            // Reiniciar la lista de zombies si se ha llegado al final
            current_zombie = zombies;
        }

        // Asignar el zombie al soldado
        current_soldier->opponent = current_zombie;
        current_soldier = current_soldier->next;
        if (current_zombie != nullptr)
        {
            current_zombie = current_zombie->next;
        }
    }

    current_zombie = zombies;
    current_soldier = soldiers;

    while (current_zombie != nullptr)
    {
        if (current_soldier == nullptr)
        {
            // Reiniciar la lista de soldados si se ha llegado al final
            current_soldier = soldiers;
        }

        // Asignar el soldado al zombie
        current_zombie->opponent = current_soldier;
        current_zombie = current_zombie->next;
        if (current_soldier != nullptr)
        {
            current_soldier = current_soldier->next;
        }
    }
    return;
}

void battle(squad *target_squad, Zgroup *opponent_group, squad **squad_list, Zgroup **zgroup_list, soldier **fallen_soldier_list, zombie **fallen_zombies_list, bpck **backpack_list)
{
    srand(time(0)); // Inicializar la semilla para la selección aleatoria

    reassignOpponents(target_squad->list_soldiers, opponent_group->list_zombies);

    // Realizar dos ráfagas de ataque de los soldados
    for (int i = 0; i < 2; ++i)
    {
        soldier *current_soldier = target_squad->list_soldiers;
        while (current_soldier != nullptr)
        {
            if (current_soldier->opponent != nullptr)
            {
                useAttack_item(&(current_soldier->backpag->list_items), current_soldier->name, current_soldier->opponent->id, opponent_group, zgroup_list, fallen_zombies_list);
            }
            current_soldier = current_soldier->next;
        }
        reassignOpponents(target_squad->list_soldiers, opponent_group->list_zombies);
    }

    // Primer ataque de los zombies
    zombie *current_zombie = opponent_group->list_zombies;
    while (current_zombie != nullptr)
    {
        if (current_zombie->opponent != nullptr)
        {
            useDamage_Zombie(squad_list, current_zombie->opponent->name, current_zombie->id, opponent_group, fallen_soldier_list, backpack_list);
        }
        current_zombie = current_zombie->next;
    }
    reassignOpponents(target_squad->list_soldiers, opponent_group->list_zombies);

    // Batalla continua en turnos alternos hasta que uno de los grupos sea derrotado
    while (target_squad->list_soldiers != nullptr && opponent_group->list_zombies != nullptr)
    {
        // Turno de los soldados
        soldier *current_soldier = target_squad->list_soldiers;
        while (current_soldier != nullptr)
        {
            if (opponent_group->list_zombies == nullptr)
                break; // Verificar si todos los soldados han sido derrotados antes de cada ataque

            if (current_soldier->opponent != nullptr)
            {
                useAttack_item(&(current_soldier->backpag->list_items), current_soldier->name, current_soldier->opponent->id, opponent_group, zgroup_list, fallen_zombies_list);
            }
            current_soldier = current_soldier->next;
        }
        reassignOpponents(target_squad->list_soldiers, opponent_group->list_zombies);

        // Verificar si todos los zombies han sido derrotados
        if (opponent_group->list_zombies == nullptr)
            break;

        // Turno de los zombies
        current_zombie = opponent_group->list_zombies;
        while (current_zombie != nullptr)
        {
            if (target_squad->list_soldiers == nullptr)
                break; // Verificar si todos los soldados han sido derrotados antes de cada ataque

            if (current_zombie->opponent != nullptr)
            {
                useDamage_Zombie(squad_list, current_zombie->opponent->name, current_zombie->id, opponent_group, fallen_soldier_list, backpack_list);
            }
            current_zombie = current_zombie->next;
        }
        reassignOpponents(target_squad->list_soldiers, opponent_group->list_zombies);

        // Verificar si todos los soldados han sido derrotados
        if (target_squad->list_soldiers == nullptr)
            break;
    }

    // Determinar si el escuadrón es ganador y aplicar ítems de supervivencia
    if (opponent_group->list_zombies == nullptr) // Todos los zombies han sido derrotados
    {
        soldier *current_soldier = target_squad->list_soldiers;
        while (current_soldier != nullptr)
        {
            useSurvival_item(&(target_squad->list_soldiers), current_soldier->name);
            current_soldier = current_soldier->next;
        }
        coutf(BLUE, "\nEl escuadrón ha ganado la batalla.\n");
    }
    else
    {
        coutf(BLUE, "\nLa batalla ha terminado pero el escuadrón no ha derrotado a todos los zombies.\n");
    }
    return;
}

#endif // F01_START_BATTLE_H