#ifndef FILE02_ZOMBIES_H
#define FILE02_ZOMBIES_H
#include "../sources/outools.h"
#include "../sources/structs.h"


void LiberarZombies(Zombies_GroupsPtr *zombies_groups_list)
{
    while (*zombies_groups_list != nullptr)
    {
        Zombies_GroupsPtr temp_group = *zombies_groups_list;
        *zombies_groups_list = (*zombies_groups_list)->next;

        // Liberar memoria de los zombies
        delete[] temp_group->zombies;

        delete temp_group;
    }
}


#endif