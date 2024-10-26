#ifndef ZGRPSMANAGMENT_H
#define ZGRPSMANAGMENT_H
#include <iostream>
#include "../outools.h"
#include "../structs.h"
#include <vector>
using namespace std;

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
}

void CrearGrupoZombie(Zombies_GroupsPtr *zombie_group_list)
{
    Zombies_Groups *new_group = new Zombies_Groups;
    coutf(GREEN, "Indique el número del nuevo grupo zombie: ");
    cinv("int", new_group->number);
    new_group->zombies = nullptr; // Inicializar la lista de zombies del grupo
    new_group->next = *zombie_group_list;
    *zombie_group_list = new_group;

    coutf(GREEN, "Grupo zombie creado exitosamente.\n");
    system("pause");
}

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

    system("pause");
}

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
    system("pause");
}

void AgregarZombie(Zombies_GroupsPtr current_group, Zombies_GroupsPtr zombie_group_list, SquadsPtr squad_list)
{
    string zombie_types[] = {"Zombie Skater", "Zombie Gymbro", "Zombie Psicopata"};
    int zombie_health[] = {70, 200, 115};
    int zombie_damage[] = {15, 80, 40};

    string zombie_name;
    int zombie_type;

    coutf(GREEN, "Indique el nombre del nuevo zombie: ");
    cinv("string", zombie_name);

    // Validar que el nombre no esté en uso
    while (NombreEnUso(zombie_group_list, squad_list, zombie_name))
    {
        coutf(RED, "El nombre ya está en uso. Indique otro nombre: ");
        cinv("string", zombie_name);
    }

    coutf(GREEN, "Indique el tipo de zombie (1. Zombie Skater | 2. Zombie Gymbro | 3. Zombie Psicopata): ");
    cinv("int", zombie_type);

    while (zombie_type < 1 || zombie_type > 3)
    {
        coutf(RED, "Opción inválida. Inténtalo de nuevo: ");
        cinv("int", zombie_type);
    }

    // Verificar si ya existe un Zombie Gymbro
    if (zombie_type == 2)
    {
        Zombies *current_zombie = current_group->zombies;
        Zombies *gymbro_zombie = nullptr;

        while (current_zombie != nullptr)
        {
            if (current_zombie->type == "Zombie Gymbro")
            {
                gymbro_zombie = current_zombie;
                break;
            }
            current_zombie = current_zombie->next;
        }

        if (gymbro_zombie != nullptr)
        {
            int cambiar_gymbro;
            coutf(RED, "Ya existe un Zombie Gymbro, ¿deseas cambiar el tipo del Zombie Gymbro actual a Zombie Skater? (1. Si | 2. No): ");
            cinv("int", cambiar_gymbro);

            while (cambiar_gymbro < 1 || cambiar_gymbro > 2)
            {
                coutf(RED, "Opción inválida. Inténtalo de nuevo: ");
                cinv("int", cambiar_gymbro);
            }

            if (cambiar_gymbro == 1)
            {
                gymbro_zombie->type = "Zombie Skater";
                gymbro_zombie->health = 70;
                gymbro_zombie->damage = 15;
            }
            else
            {
                coutf(RED, "No se puede agregar otro Zombie Gymbro.\n");
                system("pause");
                return;
            }
        }
    }

    Zombies *new_zombie = new Zombies;
    new_zombie->name = zombie_name;
    new_zombie->type = zombie_types[zombie_type - 1];
    new_zombie->health = zombie_health[zombie_type - 1];
    new_zombie->damage = zombie_damage[zombie_type - 1];
    new_zombie->next = current_group->zombies;
    current_group->zombies = new_zombie;

    coutf(GREEN, "Zombie agregado exitosamente.\n");
    system("pause");
}

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

#endif // ZGRPSMANAGMENT_H