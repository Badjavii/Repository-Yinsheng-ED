#ifndef F00_MAIN_STATIONS_H
#define F00_MAIN_STATIONS_H
#include "../Sources/outools.h"
#include "../Sources/struct.h"

/**
 * @brief Función que muestra el menú de gestión de grupoes antizombies y maneja las opciones seleccionadas por el usuario.
 *
 * @param zgroup_list Es un puntero doble a la lista de grupoes.
 * @param backpack_list Es un puntero doble a la lista de mochilas.
 *
 * @var op Variable entera que almacena la opción seleccionada por el usuario.
 * @var x Variable entera usada para almacenar temporalmente el número del escuadrón ingresado por el usuario.
 *
 * @details Esta función presenta el menú de gestión de grupoes antizombies y
 * permite al usuario crear, consultar, editar o eliminar grupoes.
 * Dependiendo de la opción seleccionada, se llama a las funciones correspondientes para realizar la acción
 * requerida.
 *
 * @return La función no retorna ningún valor.
 **/

void Menu_Stations(Zgroup **zgroup_list, squad **squad_list, bpck **backpack_list, soldier **fallen_soldier_list, zombie **fallen_zombie_list, vector<zombie *> type_Zombies)
{
    int op = -1, x;

    while (op)
    {
        CLEAR_SCREEN; // Limpiar la pantalla
        coutf(BLUE, "\t\tMENU DE GESTIÓN DE ESTACIONES\n\n");
        coutf(BLUE, "1. Crear una nueva estacion\n");
        coutf(BLUE, "2. Consultar estaciones\n");
        coutf(BLUE, "3. Gestionar las rutas entre estaciones\n");
        coutf(BLUE, "4. Eliminar un estaciones\n");
        coutf(BLUE, "5. Mostrar todos los zombies caidos (muertos)\n");
        coutf(BLUE, "6. Mostrar todos los zombies vivos por cada estaciones\n\n");
        coutf(BLUE, "0. REGRESAR\n\n");

        cinv("int", op);

        switch (op)
        {
        case 1:
            coutf(BLUE, "\nIngresa el numero del grupo\n");
            cinv("int", x);

            if (existsZgroup(*zgroup_list, x) == true)
            {
                coutf(RED, "\nYa existe un grupo con ese numero. Intentalo de nuevo.");
                break;
            }

            add_Zgroup(zgroup_list, create_Zgroup(x));
            break;
        case 2:
            consult_Zgroup(*zgroup_list);
            break;
        case 3:
            if (isZgroupListEmpty(*zgroup_list) == true)
            {
                coutf(RED, "\nNo hay grupos para editar.");
                break;
            }

            showSummaryZgroup(*zgroup_list);

            coutf(YELLOW, "\nIngrese el numero del grupo que quieres editar:\n");
            cinv("int", x);

            if (existsZgroup(*zgroup_list, x) == false)
            {
                coutf(RED, "\nNo existe el grupo #" + to_string(x) + ".");
                break;
            }

            manageZombies_Zgroup(zgroup_list, (searchZgroup(*zgroup_list, x)), fallen_zombie_list, squad_list, fallen_soldier_list, backpack_list, type_Zombies);
            break;
        case 4:
            coutf(YELLOW, "\nNOTA: Eliminar a un grupo implica que todos sus zombies seran eliminados en caso de hayan.");

            if (isZgroupListEmpty(*zgroup_list) == true)
            {
                coutf(RED, "\nNo hay grupos para eliminar.");
                break;
            }

            showSummaryZgroup(*zgroup_list);

            coutf(BLUE, "\nIngresa el numero del grupo a eliminar\n");
            cinv("int", x);

            if (existsZgroup(*zgroup_list, x) == false)
            {
                coutf(RED, "\nNo existe el grupo #" + to_string(x) + ".");
                break;
            }

            delete_Zgroup(zgroup_list, x);
            break;
        case 5:
            showFallen_zombies(*fallen_zombie_list);
            break;
        case 6:
            showLiving_Zombies(*zgroup_list);
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

#endif // F00_MAIN_STATIONS_H