#ifndef MAIN_MENU_H
#define MAIN_MENU_H
#include "../Sources/outools.h"
#include "../Sources/struct.h"
#include "../F01-Soldiers/F00_main_squads.h"
#include "../F02-Zombies/F00_main_zgroup.h"
#include "../F03-Stations/F00_main_stations.h"

/**
 * @brief Función que muestra el menú principal y maneja las opciones seleccionadas por el usuario.
 *
 * @param squad_l Es un puntero doble a la estructura squad que señala a la lista de escuadrones.
 * @param backpack_l Es un puntero doble a la estructura bpck que señala a la lista de mochilas.
 * @param station_l Es un puntero doble a la estructura stations que señala a la lista de estaciones.
 * @param zgroup_l Es un puntero doble a la estructura zgroup que señala a la lista de grupos de zombies (comentado).
 *
 *
 * @details Esta función presenta el menú principal del programa al usuario y gestiona la selección de opciones.
 * Cada opción del menú lleva al usuario a diferentes submenús para la gestión de escuadrones, grupos de zombies y estaciones.
 * Si el usuario selecciona la opción de salir, la función termina la ejecución del menú.
 * Las listas de escuadrones, mochilas y estaciones se pasan como punteros dobles para permitir la modificación directa de estas estructuras.
 *
 * @return La función no retorna ningún valor.
 */

void main_menu(squad **squad_l, bpck **backpack_l, station **station_l, soldier **fallen_soldier_l, vector<item *> pre_items, Zgroup **zgroup_l, zombie **fallen_zombie_list, vector<zombie *> type_Zombies)
{

    squad *squad_list = *squad_l;
    bpck *backpack_list = *backpack_l;
    station *station_list = *station_l;
    Zgroup *zgroup_list = *zgroup_l;

    int op = -1;

    while (op)
    {
        CLEAR_SCREEN; // Limpiar la pantalla
        coutf(BLUE, "\t\t##### PRINCIPAL MENU #####\n\n");
        coutf(BLUE, "1. Gestión de escuadrones antizombies\n");
        coutf(BLUE, "2. Gestión de grupos de zombies\n");
        coutf(BLUE, "3. Gestión de estaciones\n");
        coutf(BLUE, "4. Revisar bitacora\n");
        coutf(BLUE, "5. QUE INICIE LA AVENTURA (iniciar juego)\n\n");
        coutf(BLUE, "0. GAME OVER\n\n");

        cinv("int", op);

        switch (op)
        {
        case 1:

            /**
             * @brief Gestión de los escuadrones.
             *
             * @param squad_list Es un puntero doble a la lista de escuadrones.
             * @param backpack_list Es un puntero doble a la lista de mochilas.
             */

            Menu_Squads(&squad_list, &backpack_list, fallen_soldier_l, pre_items, &zgroup_list, fallen_zombie_list);
            break;
        case 2:
            /*
                @brief Gestión de los grupos de zombies.

                @param **zombies_groups_list Es un puntero doble a la lista de grupos de zombies.
                @param **squad_list Es un puntero doble a la lista de escuadrones.
            */
            Menu_Zgroups(&zgroup_list, &squad_list, &backpack_list, fallen_soldier_l, fallen_zombie_list, type_Zombies);
            break;
        case 3:
            /*
                @brief Gestión de los mapas.

                @param **mapa Es un puntero doble al mapa.
                @param **squad_list Es un puntero doble a la lista de escuadrones.
                @param **zombies_groups_list Es un puntero doble a la lista de grupos de zombies.
            */
            Menu_Stations(&zgroup_list, &squad_list, &station_list, fallen_soldier_l, fallen_zombie_list, &backpack_list);
            break;
        case 0:
            // Salir del menú
            return;
        default:
            break;
        }
        cout << "\n\n";
        PAUSE_TERMINAL; // Pausar la terminal para que el usuario pueda ver el resultado antes de continuar
    }
};

#endif // MAIN_MENU_H