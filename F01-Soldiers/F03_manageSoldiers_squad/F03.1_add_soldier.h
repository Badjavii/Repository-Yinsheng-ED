#ifndef F03_1_ADD_SOLDIER_H
#define F03_1_ADD_SOLDIER_H
#include "../../Sources/outools.h"
#include "../../Sources/struct.h"
#include "../FZZ_extra.h"

soldier *create_Soldier(string name, int health)
{
    soldier *newSoldier = new soldier;
    newSoldier->name = name;
    newSoldier->health = health;
    newSoldier->backpag = nullptr;
    newSoldier->opponent = nullptr;
    newSoldier->next = nullptr;
    return newSoldier;
};

void add_Soldier(soldier **soldier_list, soldier *newSoldier)
{
    soldier *current_soldier = *soldier_list;

    if (isSoldierListEmpty(current_soldier) == true)
    {
        *soldier_list = newSoldier;
        return;
    }

    while (current_soldier->next != nullptr)
        current_soldier = current_soldier->next;

    current_soldier->next = newSoldier;
    return;
};

#endif // F03_1_ADD_SOLDIER_H