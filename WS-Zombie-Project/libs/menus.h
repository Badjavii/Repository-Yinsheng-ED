#ifndef MENUS_H
#define MENUS_H
#include <iostream>
#include "outools.h"
#include "structs.h"
using namespace std;

void Menu_Squads(SquadsPtr *squad_list) {
    int op = -1;

    while (op) {
        system("cls");
        coutf(BLUE, "\t\tMENU DE GESTIÓN DE ESCUADRONES ANTIZOMBIES\n\n");
        coutf(BLUE, "1. Crear un nuevo escuadron\n");
        coutf(BLUE, "2. Consultar un escuadron\n");
        coutf(BLUE, "3. Eliminar un escuadron\n\n");
        coutf(BLUE, "0. REGRESAR\n\n");

        cinv("int", op); // Usar cinv para obtener y validar la entrada del usuario

        switch (op) {
            case 1:
                /* Crear un nuevo escuadrón */
                break;
            case 2:
                /* Consultar un escuadrón */
                break;
            case 3:
                /* Eliminar un escuadrón */
                break;
            default:
                break;
        }
    }
};

void Principal_Menu() {
    SquadsPtr squad_list = NULL;
    Zombies_GroupsPtr zombies_groups_list = NULL;
    int op = -1;

    while (op) {
        system("cls");
        coutf(BLUE, "\t\tPRINCIPAL MENU\n\n");
        coutf(BLUE, "1. Escuadrones Antizombies\n");
        coutf(BLUE, "2. Grupos de Zombies\n");
        coutf(BLUE, "3. Mapas\n");
        coutf(BLUE, "\n0. GAME OVER\n\n");

        cinv("int", op); // Usar cinv para obtener y validar la entrada del usuario

        switch (op) {
            case 1:
                /* Management of the Squads */
                Menu_Squads(&squad_list);
                break;
            case 2:
                /* Management of the Zombies Groups
                Menu_ZombiesGroups()*/
                break;
            case 3:
                //
                break;
            default:
                break;
        }
        system("pause");
    }
};

#endif MENUS_H