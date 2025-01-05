#ifndef F00_MAIN_STATIONS_H
#define F00_MAIN_STATIONS_H
#include "../Sources/outools.h"
#include "../Sources/struct.h"
#include "F01_add_station.h"
#include "F02_delete_station.h"
#include "F03_consult_stations.h"
#include "F04_add_connection.h"
#include "F05_delete_connection.h"
#include "F06_manageRoutes_stations/F06_manageRoutes_stations.h"
#include "F07_manageSquads&Groups_stations/F07_manageSquads&Groups_stations.h"
#include "FJJ_extra.h"

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

void Menu_Stations(Zgroup **zgroup_list, squad **squad_list, station **stations_list)
{
    int op = -1, x, y, z;
    string chain;

    while (op)
    {
        CLEAR_SCREEN; // Limpiar la pantalla
        coutf(BLUE, "\t\tMENU DE GESTIÓN DE ESTACIONES\n\n");
        coutf(BLUE, "1. Crear una nueva estacion\n");
        coutf(BLUE, "2. Eliminar una estaciones\n");
        coutf(BLUE, "3. Consultar estaciones\n");
        coutf(BLUE, "4. Crear una conexión entre estaciones\n");
        coutf(BLUE, "5. Eliminar una conexión\n");
        coutf(BLUE, "6. Gestionar las rutas entre estaciones\n");
        coutf(BLUE, "7. Gestionar formas de vida (escuadrones y grupos) en una estaciones\n\n");
        coutf(BLUE, "0. REGRESAR\n\n");

        cinv("int", op);

        switch (op)
        {
        case 1:
            coutf(BLUE, "\nIngresa el numero de la estación\n");
            cinv("int", x);

            if (existsStation(*stations_list, x) == true)
            {
                coutf(RED, "\nYa existe una estación con ese numero. Intentalo de nuevo.");
                break;
            }

            coutf(BLUE, "\nIngresa el nombre de la estación\n");
            cinv("string", chain);

            if (existsStationWithName(*stations_list, chain) == true)
            {
                coutf(RED, "\nYa existe una estación con ese nombre. Intentalo de nuevo.");
                break;
            }

            add_Station(stations_list, create_station(chain, x, 0));
            break;
        case 2:
            coutf(YELLOW, "\nNOTA: Eliminar una estación implica que todas sus conexiones serán eliminadas en caso de hayan.");

            if (isStationListEmpty(*stations_list) == true)
            {
                coutf(RED, "\nNo hay estaciones para eliminar.");
                break;
            }

            showSummaryStations(*stations_list);

            coutf(BLUE, "\nIngresa el numero de la estación que quieres eliminar\n");
            cinv("int", x);

            if (existsStation(*stations_list, x) == false)
            {
                coutf(RED, "\nNo existe una estación con ese numero. Intentalo de nuevo.");
                break;
            }

            delete_Station(stations_list, x);
            break;
        case 3:
            consult_Station(*stations_list);
            break;
        case 4:
            if (isStationListEmpty(*stations_list) == true)
            {
                coutf(RED, "\nNo hay estaciones para crear conexiones.");
                break;
            }

            if (countStations(*stations_list) < 2)
            {
                coutf(RED, "\nNo hay suficientes estaciones para crear una conexión. Deben haber minimo 2 estaciones.");
                break;
            }

            showSummaryStations(*stations_list);

            coutf(YELLOW, "\nIngrese el numero de la estación de origen para la conexión:\n");
            cinv("int", x);

            if (existsStation(*stations_list, x) == false)
            {
                coutf(RED, "\nNo existe la estación #" + to_string(x) + ".");
                break;
            }

            coutf(YELLOW, "\nIngrese el numero de la estación de destino para la conexión:\n");
            cinv("int", y);

            if (existsStation(*stations_list, y) == false)
            {
                coutf(RED, "\nNo existe la estación #" + to_string(x) + ".");
                break;
            }

            coutf(YELLOW, "\nIngrese el valor de distancia que tendrá la conexión:\n");
            cinv("int", z);

            if (existsConns(searchStation(*stations_list, x)->list_adjacency, y, z) == true)
            {
                coutf(RED, "\nYa existe una conexión entre esas conexiones con el mismo valor de distancia.");
                break;
            }

            add_Connection(&(searchStation(*stations_list, x)->list_adjacency), create_Connection(z, searchStation(*stations_list, y)));
            break;
        case 5:

            if (isStationListEmpty(*stations_list) == true)
            {
                coutf(RED, "\nNo hay estaciones, por tanto, no hay conexiones para eliminar.");
                break;
            }

            if (countStations(*stations_list) < 2)
            {
                coutf(RED, "\nNo hay mas de 2 estaciones, entonces no hay conexiones.");
                break;
            }

            showSummaryStations(*stations_list);

            coutf(BLUE, "\nIngresa el numero de la estación a la que quieres eliminarle una conexión\n");
            cinv("int", x);

            if (existsStation(*stations_list, x) == false)
            {
                coutf(RED, "\nNo existe la estacion #" + to_string(x) + ".");
                break;
            }

            if (isConnsListEmpty(searchStation(*stations_list, x)->list_adjacency) == true)
            {
                coutf(RED, "\nLa estacion #" + to_string(x) + " no tiene conexiones.");
                break;
            }

            showSummaryConns(searchStation(*stations_list, x)->list_adjacency);

            coutf(BLUE, "\nIngresa el numero de la estación de destino de la conexión que quieres eliminar\n");
            cinv("int", y);

            if (existsStation(*stations_list, y) == false)
            {
                coutf(RED, "\nNo existe la estacion #" + to_string(y) + ".");
                break;
            }

            coutf(BLUE, "\nIngresa el valor de distancia de la conexión que quieres eliminar\n");
            cinv("int", z);

            if (existsConns(searchStation(*stations_list, x)->list_adjacency, y, z) == false)
            {
                coutf(RED, "\nNo existe la conexión de la estación #" + to_string(x) + " a la estación " + to_string(y) + " de " + to_string(y) + " km.");
                break;
            }

            delete_Conns(&(searchStation(*stations_list, x)->list_adjacency), y, z);
            break;
        case 6:
            manageRoutes_Stations(squad_list, zgroup_list, stations_list);
            break;
        case 7:
            manageSquadsAndGroups_Stations(squad_list, zgroup_list, stations_list);
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