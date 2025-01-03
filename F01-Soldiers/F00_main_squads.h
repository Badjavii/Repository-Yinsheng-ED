#ifndef F00_MAIN_SQUADS_H
#define F00_MAIN_SQUADS_H
#include "../Sources/outools.h"
#include "../Sources/struct.h"
#include "F01_add_squad.h"
#include "F02_consult_squad.h"
#include "F03_manageSoldiers_squad/F03_manageSoldiers_squad.h"
#include "F04_manageBpck_squad/F04_manageBpck_squad.h"
#include "F05_delete_squad.h"
#include "F06_showFallen_soldiers.h"
#include "F07_showLiving_soldiers.h"
#include "FZZ_extra.h"

/**
 * @brief Función que muestra el menú de gestión de escuadrones antizombies y maneja las opciones seleccionadas por el usuario.
 *
 * @param squad_list Es un puntero doble a la lista de escuadrones.
 * @param backpack_list Es un puntero doble a la lista de mochilas.
 *
 * @var op Variable entera que almacena la opción seleccionada por el usuario.
 * @var x Variable entera usada para almacenar temporalmente el número del escuadrón ingresado por el usuario.
 *
 * @details Esta función presenta el menú de gestión de escuadrones antizombies y
 * permite al usuario crear, consultar, editar o eliminar escuadrones.
 * Dependiendo de la opción seleccionada, se llama a las funciones correspondientes para realizar la acción
 * requerida.
 *
 * @return La función no retorna ningún valor.
 **/

void Menu_Squads(squad **squad_list, bpck **backpack_list, soldier **fallen_soldier_list, vector<item *> pre_items, Zgroup **zgroup_list, zombie **fallen_zombie_list)
{
    int op = -1, x;

    while (op)
    {
        CLEAR_SCREEN; // Limpiar la pantalla
        coutf(BLUE, "\t\tMENU DE GESTIÓN DE ESCUADRONES ANTIZOMBIES\n\n");
        coutf(BLUE, "1. Crear un nuevo escuadron\n");
        coutf(BLUE, "2. Consultar escuadrones\n");
        coutf(BLUE, "3. Gestionar los integrantes (soldados) de un escuadron\n");
        coutf(BLUE, "4. Gestionar el equipamento (mochilas) de un escuadron\n");
        coutf(BLUE, "5. Eliminar un escuadron\n");
        coutf(BLUE, "6. Mostrar todos los soldados caidos (muertos)\n");
        coutf(BLUE, "7. Mostrar todos los soldados vivos por cada escuadron\n\n");
        coutf(BLUE, "0. REGRESAR\n\n");

        cinv("int", op);

        switch (op)
        {
        case 1:
            coutf(BLUE, "\nIngresa el numero del escuadron\n");
            cinv("int", x);

            if (existsSquad(*squad_list, x) == true)
            {
                coutf(RED, "\nYa existe un escuadron con ese numero. Intentalo de nuevo.");
                break;
            }

            add_Squad(squad_list, create_Squad(x));
            break;
        case 2:
            consult_Squads(*squad_list);
            break;
        case 3:
            if (isSquadListEmpty(*squad_list) == true)
            {
                coutf(RED, "\nNo hay escuadrones para editar.");
                break;
            }

            showSummarySquad(*squad_list);

            coutf(YELLOW, "\nIngrese el numero del escuadron que quiere editar:\n");
            cinv("int", x);

            if (existsSquad(*squad_list, x) == false)
            {
                coutf(RED, "\nNo existe el escuadron #" + to_string(x) + ".");
                break;
            }

            manageSoldiers_Squad(squad_list, (searchSquad(*squad_list, x)), fallen_soldier_list, backpack_list, zgroup_list, fallen_zombie_list);
            break;
        case 4:
            if (isSquadListEmpty(*squad_list) == true)
            {
                coutf(RED, "\nNo hay escuadrones, por tanto, no se puede gestionar ningun equipamento.");
                break;
            }

            showSummarySquad(*squad_list);

            coutf(BLUE, "\nIngresa el numero del escuadron\n");
            cinv("int", x);

            if (existsSquad(*squad_list, x) == false)
            {
                coutf(RED, "\nNo existe el escuadron #" + to_string(x) + ".");
                break;
            }

            manageBpck_Squad(backpack_list, (searchSquad(*squad_list, x)), pre_items);

            break;
        case 5:
            coutf(YELLOW, "\nNOTA: Eliminar a un escuadron implica que todos sus soldados seran eliminados en caso de hayan.");

            if (isSquadListEmpty(*squad_list) == true)
            {
                coutf(RED, "\nNo hay escuadrones para eliminar.");
                break;
            }

            showSummarySquad(*squad_list);

            coutf(BLUE, "\nIngresa el numero del escuadron a eliminar\n");
            cinv("int", x);

            if (existsSquad(*squad_list, x) == false)
            {
                coutf(RED, "\nNo existe el escuadron #" + to_string(x) + ".");
                break;
            }

            delete_Squad(squad_list, x, backpack_list);
            break;
        case 6:
            showFallen_soldiers(*fallen_soldier_list);
            break;
        case 7:
            showLiving_soldiers(*squad_list);
            break;
        case 0:
            return;
        default:
            break;
        }
        cout << "\n\n";
        PAUSE_TERMINAL; // Pausar la terminal para que el usuario pueda ver el resultado antes de continuar
    }
}

#endif // F00_MAIN_SQUADS_H
