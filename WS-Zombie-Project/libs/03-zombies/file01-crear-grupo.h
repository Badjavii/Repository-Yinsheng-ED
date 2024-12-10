#ifndef FILE01_CREAR_GRUPO_H
#define FILE01_CREAR_GRUPO_H
#include "../sources/outools.h"
#include "../sources/structs.h"

void CrearGrupoZombie(Zombies_GroupsPtr *zombie_group_list)
{
    Zombies_Groups *new_group = new Zombies_Groups;
    coutf(GREEN, "Indique el número del nuevo grupo zombie: ");
    cinv("int", new_group->number);
    new_group->zombies = nullptr; // Inicializar la lista de zombies del grupo
    new_group->next = *zombie_group_list;
    *zombie_group_list = new_group;

    coutf(GREEN, "Grupo zombie creado exitosamente.\n");
    return;
}

#endif