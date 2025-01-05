#ifndef F06_MANAGEROUTES_STATIONS_H
#define F06_MANAGEROUTES_STATIONS_H
#include "../../Sources/outools.h"
#include "../../Sources/struct.h"
#include "F06.1_shortest_Path.h"
#include "F06.2_leastZombies_Path.h"
#include "F06.3_survivor_Path.h"
#include "../FJJ_extra.h"

void manageRoutes_Stations(squad **squad_list, Zgroup **zgroup_list, station **station_list)
{
    int op = -1, x, y;
    string chain, chain2;

    while (op)
    {
        CLEAR_SCREEN;
        coutf(BLUE, "\t\tMENU DE GESTIÓN DE RUTAS DE ESTACIONES\n\n");
        coutf(BLUE, "1. Calcular el camino más corto entre dos estaciones\n");
        coutf(BLUE, "2. Calcular el camino con menos zombies entre dos estaciones\n");
        coutf(BLUE, "3. Calcular el camino más corto entre dos estaciones para un sobreviviente\n");
        coutf(BLUE, "0. REGRESAR\n\n");

        cinv("int", op); // Usar cinv para obtener y validar la entrada del usuario

        switch (op)
        {
        case 1:
            if (isStationListEmpty(*station_list) == true)
            {
                coutf(RED, "\nNo hay estaciones, por tanto, no se puede hacer nada.");
                break;
            }

            if (countStations(*station_list) == 1)
            {
                coutf(RED, "\nSolo hay una estación, por tanto, no se puede hacer nada.");
                break;
            }

            showSummaryStations(*station_list);

            coutf(GREEN, "\nIngrese el número de la estación de inicio:\n");
            cinv("int", x);

            if (existsStation(*station_list, x) == false)
            {
                coutf(RED, "\nNo existe esa estación.");
                break;
            }

            coutf(GREEN, "\nIngrese el número de la estación de destino:\n");
            cinv("int", y);

            if (existsStation(*station_list, y) == false)
            {
                coutf(RED, "\nNo existe esa estación.");
                break;
            }

            {
                vector<roots> path = shortestPath(station_list, x, y);
                // Imprimir el camino
                for (auto st : path)
                {
                    coutf(YELLOW, "Estación " + to_string(st.origin_station) + " a Estación " + to_string(st.destination_station) + " con peso " + to_string(st.weight) + "\n");
                }
            }

            break;
        case 2:
            if (isStationListEmpty(*station_list) == true)
            {
                coutf(RED, "\nNo hay estaciones, por tanto, no se puede hacer nada.");
                break;
            }

            if (countStations(*station_list) == 1)
            {
                coutf(RED, "\nSolo hay una estación, por tanto, no se puede hacer nada.");
                break;
            }

            showSummaryStations(*station_list);

            coutf(GREEN, "\nIngrese el número de la estación de inicio:\n");
            cinv("int", x);

            if (existsStation(*station_list, x) == false)
            {
                coutf(RED, "\nNo existe esa estación.");
                break;
            }

            coutf(GREEN, "\nIngrese el número de la estación de destino:\n");
            cinv("int", y);

            if (existsStation(*station_list, y) == false)
            {
                coutf(RED, "\nNo existe esa estación.");
                break;
            }

            {
                vector<roots> path = pathWithLeastZombies(station_list, x, y);
                // Imprimir el camino
                for (auto st : path)
                {
                    coutf(YELLOW, "Estación " + to_string(st.origin_station) + " a Estación " + to_string(st.destination_station) + " con zombies " + to_string(st.weight) + "\n");
                }
            }

            break;
        case 3:
            if (isStationListEmpty(*station_list) == true)
            {
                coutf(RED, "\nNo hay estaciones, por tanto, no se puede hacer nada.");
                break;
            }

            if (countStations(*station_list) == 1)
            {
                coutf(RED, "\nSolo hay una estación, por tanto, no se puede hacer nada.");
                break;
            }

            showSummaryStations(*station_list);

            coutf(GREEN, "\nIngrese el número de la estación de inicio:\n");
            cinv("int", x);

            if (existsStation(*station_list, x) == false)
            {
                coutf(RED, "\nNo existe esa estación.");
                break;
            }

            coutf(GREEN, "\nIngrese el número de la estación de destino:\n");
            cinv("int", y);

            if (existsStation(*station_list, y) == false)
            {
                coutf(RED, "\nNo existe esa estación.");
                break;
            }

            {
                vector<roots> path = survivorPath(station_list, x, y);
                // Imprimir el camino
                for (auto st : path)
                {
                    coutf(YELLOW, "Estación " + to_string(st.origin_station) + " a Estación " + to_string(st.destination_station) + " con peso " + to_string(st.weight) + "\n");
                }
            }

            break;
        case 0:
            return;
        default:
            coutf(RED, "Opción no válida.\n");
        }
        cout << "\n\n";
        PAUSE_TERMINAL;
    }
    return;
};

#endif // F06_MANAGEROUTES_STATIONS_H