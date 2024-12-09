#ifndef FILE05_SOURCES_H
#define FILE05_SOURCES_H
#include "../sources/outools.h"
#include "../sources/structs.h"

void ConsultarGruposZombies(Zombies_GroupsPtr *zombie_group_list)
{
    if (*zombie_group_list == nullptr)
    {
        coutf(RED, "No hay grupos zombies para consultar.\n");
        system("pause");
        return;
    }

    Zombies_GroupsPtr current_group = *zombie_group_list;
    while (current_group != nullptr)
    {
        coutf(GREEN, "Grupo zombie número: " + to_string(current_group->number) + "\n");

        if (current_group->zombies == nullptr)
        {
            coutf(YELLOW, "  No hay zombies en este grupo.\n");
        }
        else
        {
            Zombies *current_zombie = current_group->zombies;
            while (current_zombie != nullptr)
            {
                coutf(BLUE, "  Zombie: " + current_zombie->name + ", Tipo: " + current_zombie->type + ", Daño: " + to_string(current_zombie->damage) + ", Salud: " + to_string(current_zombie->health) + "\n");
                current_zombie = current_zombie->next;
            }
        }

        current_group = current_group->next;
    }

    return;
}

bool isZombiesGroupsListEmpty(Zombies_GroupsPtr head)
{
    return head == nullptr;
}

bool NombreEnUso(Zombies_GroupsPtr zombie_group_list, SquadsPtr squad_list, const string &nombre)
{
    // Verificar nombres de zombies
    Zombies_GroupsPtr current_group = zombie_group_list;
    while (current_group != nullptr)
    {
        Zombies *current_zombie = current_group->zombies;
        while (current_zombie != nullptr)
        {
            if (current_zombie->name == nombre)
            {
                return true;
            }
            current_zombie = current_zombie->next;
        }
        current_group = current_group->next;
    }

    // Verificar nombres de soldados
    SquadsPtr current_squad = squad_list;
    while (current_squad != nullptr)
    {
        Soldier *current_soldier = current_squad->soldiers;
        while (current_soldier != nullptr)
        {
            if (current_soldier->name == nombre)
            {
                return true;
            }
            current_soldier = current_soldier->next;
        }
        current_squad = current_squad->next;
    }

    return false;
}

void MostrarResumenZombie(Zombies *zombie)
{
    coutf(BLUE, "--------------------------------------------------------------------------------\n");
    coutf(BLUE, "                   Resumen del Zombie '" + zombie->name + "'\n");
    coutf(BLUE, "--------------------------------------------------------------------------------\n");
    coutf(BLUE, "Nombre        Tipo                       Vida            Daño\n");
    coutf(BLUE, "-----------        -----------------------     ---------------    -----------\n");
    coutf(BLUE, zombie->name + "             " + zombie->type + "           " + to_string(zombie->health) + "             " + to_string(zombie->damage) + "\n");
    coutf(BLUE, "--------------------------------------------------------------------------------\n");
    return;
}

void MostrarResumenGrupoZombie(Zombies_GroupsPtr current_group)
{
    coutf(BLUE, "-------------------------------------------------------------------------\n");
    coutf(BLUE, "             Resumen de Grupos Zombies\n");
    coutf(BLUE, "-------------------------------------------------------------------------\n");
    coutf(BLUE, "Tipo                 Nombre            Daño          Vida\n");
    coutf(BLUE, "------------          --------------        -----------------  ------------\n");

    Zombies *current_zombie = current_group->zombies;
    while (current_zombie != nullptr)
    {
        coutf(BLUE, current_zombie->type + "          " + current_zombie->name + "            " + to_string(current_zombie->damage) + "          " + to_string(current_zombie->health) + "\n");
        current_zombie = current_zombie->next;
    }

    coutf(BLUE, "-------------------------------------------------------------------------\n");
    return;
}

void MostrarResumenGruposZombies(Zombies_GroupsPtr zombie_group_list)
{
    coutf(BLUE, "--------------------------------------------------------------------------------\n");
    coutf(BLUE, "       Resumen de todos los grupos zombies\n");
    coutf(BLUE, "--------------------------------------------------------------------------------\n");
    coutf(BLUE, "Numero         Cantidad de Zombies\n");
    coutf(BLUE, "--------    ---------------------------\n");

    Zombies_GroupsPtr current_group = zombie_group_list;
    while (current_group != nullptr)
    {
        int num_zombies = 0;
        Zombies *current_zombie = current_group->zombies;
        while (current_zombie != nullptr)
        {
            num_zombies++;
            current_zombie = current_zombie->next;
        }

        coutf(BLUE, to_string(current_group->number) + "                " + to_string(num_zombies) + " Zombies\n");
        current_group = current_group->next;
    }

    coutf(BLUE, "--------------------------------------------------------------------------------\n");
    return;
}

#endif