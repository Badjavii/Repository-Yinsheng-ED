#ifndef FILE02_2_EDITAR_ZOMBIE_H
#define FILE02_2_EDITAR_ZOMBIE_H
#include "../sources/outools.h"
#include "../sources/structs.h"
#include "file05-sources.h"

void Menu_EditarZombie(Zombies *zombie, Zombies_GroupsPtr zombie_group_list, SquadsPtr squad_list)
{
    string zombie_types[] = {"Zombie Skater", "Zombie Gymbro", "Zombie Psicopata"};
    int zombie_health[] = {70, 200, 115};
    int zombie_damage[] = {15, 80, 40};

    int op = -1;
    while (op)
    {
        CLEAR_SCREEN;
        coutf(BLUE, "\t\tMENU DE EDICIÓN DEL ZOMBIE " + zombie->name + "\n\n");
        coutf(BLUE, "1. Editar nombre\n");
        coutf(BLUE, "2. Editar tipo\n\n");
        coutf(BLUE, "0. REGRESAR\n\n");

        // Mostrar resumen del zombie actual
        MostrarResumenZombie(zombie);

        cinv("int", op); // Usar cinv para obtener y validar la entrada del usuario

        switch (op)
        {
        case 1:
        {
            string nuevo_nombre;
            coutf(GREEN, "Indique el nuevo nombre del zombie: ");
            cinv("string", nuevo_nombre);

            // Validar que el nombre no esté en uso
            while (NombreEnUso(zombie_group_list, squad_list, nuevo_nombre))
            {
                coutf(RED, "El nombre ya está en uso. Indique otro nombre: ");
                cinv("string", nuevo_nombre);
            }

            zombie->name = nuevo_nombre;
            coutf(GREEN, "Nombre del zombie actualizado exitosamente.\n");
        }
        break;
        case 2:
        {
            coutf(GREEN, "Indique el nuevo tipo de zombie (1. Zombie Skater | 2. Zombie Gymbro | 3. Zombie Psicopata): ");
            int zombie_type;
            cinv("int", zombie_type);
            while (zombie_type < 1 || zombie_type > 3)
            {
                coutf(RED, "Opción inválida. Inténtalo de nuevo: ");
                cinv("int", zombie_type);
            }

            // Verificar si ya existe un Zombie Gymbro
            if (zombie_type == 2)
            {
                Zombies *current_zombie = zombie_group_list->zombies;
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
                        coutf(RED, "No se puede cambiar el tipo a Zombie Gymbro.\n");
                        break;
                    }
                }
            }

            zombie->type = zombie_types[zombie_type - 1];
            zombie->health = zombie_health[zombie_type - 1];
            zombie->damage = zombie_damage[zombie_type - 1];
            coutf(GREEN, "Tipo del zombie actualizado exitosamente.\n");
        }
        break;
        case 0:
            return;
        default:
            coutf(RED, "Opción inválida. Inténtalo de nuevo.\n");
            break;
        }
        PAUSE_TERMINAL;
    }
}

#endif