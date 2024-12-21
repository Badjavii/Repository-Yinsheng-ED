#ifndef FILE00_MENU_ZOMBIES_H
#define FILE00_MENU_ZOMBIES_H
#include "../sources/structs.h"
#include "../sources/outools.h"
#include "file01-crear-grupo.h"
#include "file02-editar-grupo.h"
#include "file03-eliminar-grupo.h"
#include "file05-sources.h"

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
        case 0:
            return;
        default:
            break;
        }
        PAUSE_TERMINAL;
    }
};

#endif 