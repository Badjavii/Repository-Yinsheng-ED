#ifndef FILE02_1_AGREGAR_ZOMBIE_H
#define FILE02_1_AGREGAR_ZOMBIE_H
#include "../sources/outools.h"
#include "../sources/structs.h"
#include "file05-sources.h"

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
    return;
}

#endif