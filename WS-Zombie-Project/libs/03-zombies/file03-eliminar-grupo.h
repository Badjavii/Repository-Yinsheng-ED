#ifndef FILE03_ELIMINAR_GRUPO_H
#define FILE03_ELIMINAR_GRUPO_H
#include "../sources/outools.h"
#include "../sources/structs.h"

void EliminarGrupoZombie(Zombies_GroupsPtr *zombie_group_list)
{
    if (*zombie_group_list == nullptr)
    {
        coutf(RED, "No hay grupos zombies para eliminar.\n");
        system("pause");
        return;
    }

    int group_number;
    coutf(GREEN, "Indique el número del grupo zombie a eliminar: ");
    cinv("int", group_number);

    Zombies_GroupsPtr current_group = *zombie_group_list;
    Zombies_GroupsPtr previous_group = nullptr;

    while (current_group != nullptr && current_group->number != group_number)
    {
        previous_group = current_group;
        current_group = current_group->next;
    }

    if (current_group == nullptr)
    {
        coutf(RED, "Grupo zombie no encontrado.\n");
        system("pause");
        return;
    }

    if (previous_group == nullptr)
    {
        *zombie_group_list = current_group->next;
    }
    else
    {
        previous_group->next = current_group->next;
    }

    delete current_group;
    coutf(GREEN, "Grupo zombie eliminado exitosamente.\n");
    return;
}

#endif