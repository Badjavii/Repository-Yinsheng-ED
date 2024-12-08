#ifndef FILE01_ESCUADRONES_H
#define FILE01_ESCUADRONES_H
#include "../sources/outools.h"
#include "../sources/structs.h"

void LiberarEscuadrones(SquadsPtr *squad_list)
{
    while (*squad_list != nullptr)
    {
        SquadsPtr temp_squad = *squad_list;
        *squad_list = (*squad_list)->next;

        // Liberar memoria de los soldados
        Soldier *current_soldier = temp_squad->soldiers;
        while (current_soldier != nullptr)
        {
            Soldier *temp_soldier = current_soldier;
            current_soldier = current_soldier->next;
            delete temp_soldier;
        }

        delete temp_squad;
    }
};

#endif