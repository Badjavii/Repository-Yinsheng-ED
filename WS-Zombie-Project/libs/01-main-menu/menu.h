#ifndef MENU_H
#define MENU_H
#include <iostream>
#include "../sources/structs.h"
#include "../02-squads-soldiers"
#include "../03-zombies"
#include "../04-map"
using namespace std;

void Principal_Menu(Squads **squad_l, Zombies_Groups **zombies_grop_l, Mapa **mapa_g)
{
    SquadsPtr squad_list = *squad_l;
    Zombies_GroupsPtr zombies_groups_list = *zombies_grop_l;
    MapaPtr mapa = *mapa_g;
    mapa->estaciones = nullptr;
    int op = -1;

    while (op)
    {
        CLEAR_SCREEN;
        coutf(BLUE, "\t\tPRINCIPAL MENU\n\n");
        coutf(BLUE, "1. Escuadrones Antizombies\n");
        coutf(BLUE, "2. Grupos de Zombies\n");
        coutf(BLUE, "3. Mapas\n");
        coutf(BLUE, "\n0. GAME OVER\n\n");

        cinv("int", op); // Usar cinv para obtener y validar la entrada del usuario

        switch (op)
        {
        case 1:
            /* Management of the Squads */
            Menu_Squads(&squad_list);
            break;
        case 2:
            /* Management of the Zombies Groups*/
            Menu_ZombieGroups(&zombies_groups_list, &squad_list);
            break;
        case 3:
            Menu_Mapa(&mapa, &squad_list, &zombies_groups_list);
            break;
        case 0:
            // Salir
            break;
        default:
            break;
        }
        PAUSE_TERMINAL;
    }
}

#endif // MENU_H