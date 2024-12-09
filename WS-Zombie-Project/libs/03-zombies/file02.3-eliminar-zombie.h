#ifndef FILE04_ELIMINAR_GRUPO_H
#define FILE04_ELIMINAR_GRUPO_H
#include "../sources/outools.h"
#include "../sources/structs.h"

void EliminarZombie(Zombies_GroupsPtr current_group)
{
    if (current_group->zombies == nullptr)
    {
        coutf(RED, "No hay zombies para eliminar en este grupo.\n");
        system("pause");
        return;
    }

    string zombie_name;
    coutf(GREEN, "Indique el nombre del zombie a eliminar: ");
    cinv("string", zombie_name);

    Zombies *current_zombie = current_group->zombies;
    Zombies *previous_zombie = nullptr;

    while (current_zombie != nullptr && current_zombie->name != zombie_name)
    {
        previous_zombie = current_zombie;
        current_zombie = current_zombie->next;
    }

    if (current_zombie == nullptr)
    {
        coutf(RED, "Zombie no encontrado.\n");
        system("pause");
        return;
    }

    if (previous_zombie == nullptr)
    {
        current_group->zombies = current_zombie->next;
    }
    else
    {
        previous_zombie->next = current_zombie->next;
    }

    delete current_zombie;
    coutf(GREEN, "Zombie eliminado exitosamente.\n");
    system("pause");
}

#endif