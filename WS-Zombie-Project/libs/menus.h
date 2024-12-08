#ifndef MENUS_H
#define MENUS_H
#include <iostream>
#include "libs/sources/outools.h"
#include "libs/sources/structs.h"
#include "libs/Managers/SquadManager.h"
#include "Managers/ZombieManager.h"
#include "Managers/MapManager.h"
using namespace std;

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
            PAUSE_TERMINAL;
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
                        PAUSE_TERMINAL;
                        break;
                    }
                }
            }

            zombie->type = zombie_types[zombie_type - 1];
            zombie->health = zombie_health[zombie_type - 1];
            zombie->damage = zombie_damage[zombie_type - 1];
            coutf(GREEN, "Tipo del zombie actualizado exitosamente.\n");
            PAUSE_TERMINAL;
        }
        break;
        case 0:
            return;
        default:
            coutf(RED, "Opción inválida. Inténtalo de nuevo.\n");
            PAUSE_TERMINAL;
            break;
        }
    }
}

void Menu_EditarGrupoZombie(Zombies_GroupsPtr zombie_group_list, SquadsPtr squad_list)
{
    if (zombie_group_list == nullptr)
    {
        coutf(RED, "No hay grupos zombies para editar.\n");
        PAUSE_TERMINAL;
        return;
    }

    // Mostrar resumen de todos los grupos zombies
    MostrarResumenGruposZombies(zombie_group_list);

    int group_number;
    coutf(GREEN, "Indique el número del grupo zombie a editar: ");
    cinv("int", group_number);

    Zombies_GroupsPtr current_group = zombie_group_list;
    while (current_group != nullptr && current_group->number != group_number)
    {
        current_group = current_group->next;
    }

    if (current_group == nullptr)
    {
        coutf(RED, "Grupo zombie no encontrado.\n");
        PAUSE_TERMINAL;
        return;
    }

    int op = -1;
    while (op)
    {
        CLEAR_SCREEN;
        coutf(BLUE, "\t\tMENU DE EDICIÓN DEL GRUPO ZOMBIE " + to_string(current_group->number) + "\n\n");
        coutf(BLUE, "1. Agregar zombie al grupo\n");
        coutf(BLUE, "2. Editar un zombie\n");
        coutf(BLUE, "3. Eliminar zombie del grupo\n\n");
        coutf(BLUE, "0. REGRESAR\n\n");

        // Mostrar resumen del grupo zombie actual
        MostrarResumenGrupoZombie(current_group);

        cinv("int", op); // Usar cinv para obtener y validar la entrada del usuario

        switch (op)
        {
        case 1:
            AgregarZombie(current_group, zombie_group_list, squad_list);
            break;
        case 2:
        {
            string zombie_name;
            coutf(GREEN, "Indique el nombre del zombie a editar: ");
            cinv("string", zombie_name);

            Zombies *current_zombie = current_group->zombies;
            while (current_zombie != nullptr && current_zombie->name != zombie_name)
            {
                current_zombie = current_zombie->next;
            }

            if (current_zombie == nullptr)
            {
                coutf(RED, "Zombie no encontrado.\n");
                PAUSE_TERMINAL;
            }
            else
            {
                Menu_EditarZombie(current_zombie, zombie_group_list, squad_list);
            }
        }
        break;
        case 3:
            EliminarZombie(current_group);
            break;
        case 0:
            return;
        default:
            coutf(RED, "Opción inválida. Inténtalo de nuevo.\n");
            PAUSE_TERMINAL;
            break;
        }
    }
}

void Menu_ZombieGroups(Zombies_GroupsPtr *zombie_group_list, SquadsPtr *squad_list)
{
    int op = -1;

    while (op)
    {
        CLEAR_SCREEN;
        coutf(BLUE, "\t\tMENU DE GESTIÓN DE GRUPOS ZOMBIES\n\n");
        coutf(BLUE, "1. Crear un nuevo grupo zombie\n");
        coutf(BLUE, "2. Consultar grupos zombies\n");
        coutf(BLUE, "3. Editar un grupo zombie\n");
        coutf(BLUE, "4. Eliminar un grupo zombie\n\n");
        coutf(BLUE, "0. REGRESAR\n\n");

        cinv("int", op); // Usar cinv para obtener y validar la entrada del usuario

        switch (op)
        {
        case 1:
            CrearGrupoZombie(zombie_group_list);
            break;
        case 2:
            ConsultarGruposZombies(zombie_group_list);
            break;
        case 3:
            Menu_EditarGrupoZombie(*zombie_group_list, *squad_list);
            break;
        case 4:
            EliminarGrupoZombie(zombie_group_list);
            break;
        default:
            break;
        }
    }
}

void Menu_EditarEstacion(MapaPtr *mapa, SquadsPtr *squad_list, Zombies_GroupsPtr *zombies_groups_list)
{
    string nombre;
    MostrarTotalMaps((*mapa)->estaciones);
    coutf(BLUE, "Ingrese el nombre de la estación a editar: ");
    cinv("string", nombre); // Usar cinv para obtener y validar la entrada del usuario

    EstacionPtr actual = (*mapa)->estaciones;
    while (actual != nullptr)
    {
        if (actual->nombre == nombre)
        {
            int op;
            CLEAR_SCREEN;
            coutf(BLUE, "1. Asignar escuadrón antizombies\n");
            coutf(BLUE, "2. Asignar grupo de zombies\n");
            coutf(BLUE, "3. Agregar conexión\n\n");
            coutf(BLUE, "0. REGRESAR\n");
            cinv("int", op); // Usar cinv para obtener y validar la entrada del usuario

            switch (op)
            {
            case 1:
                AsignarEscuadronAntizombies(actual, squad_list);
                break;
            case 2:
                AsignarGrupoZombies(actual, zombies_groups_list);
                break;
            case 3:
                AgregarConexion(actual, mapa);
                break;
            case 0:
                return;
            default:
                coutf(RED, "Opción no válida.\n");
                break;
            }
            return;
        }
        actual = actual->siguiente;
    }
    coutf(RED, "Estación no encontrada.\n");
}

void Menu_Mapa(MapaPtr *mapa, SquadsPtr *squad_list, Zombies_GroupsPtr *zombies_groups_list)
{
    int op = -1;

    while (op)
    {
        CLEAR_SCREEN;
        coutf(BLUE, "\t\tMENU DE GESTIÓN DE MAPA Y ESTACIONES\n\n");
        coutf(BLUE, "1. Crear una nueva estación\n");
        coutf(BLUE, "2. Consultar estaciones\n");
        coutf(BLUE, "3. Editar una estación\n");
        coutf(BLUE, "4. Eliminar una estación\n\n");
        coutf(BLUE, "0. REGRESAR\n\n");

        cinv("int", op); // Usar cinv para obtener y validar la entrada del usuario

        switch (op)
        {
        case 1:
            CrearEstacion(mapa);
            break;
        case 2:
            ConsultarEstaciones(mapa);
            break;
        case 3:
            Menu_EditarEstacion(mapa, squad_list, zombies_groups_list);
            break;
        case 4:
            EliminarEstacion(mapa);
            break;
        default:
            break;
        }
        PAUSE_TERMINAL;
    }
}


#endif // MENUS_H
