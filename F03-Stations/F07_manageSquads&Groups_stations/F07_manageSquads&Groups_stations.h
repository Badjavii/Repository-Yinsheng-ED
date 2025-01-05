#ifndef F07_MANAGESQUADS_GROUPS_STATIONS_H
#define F07_MANAGESQUADS_GROUPS_STATIONS_H
#include "../../Sources/outools.h"
#include "../../Sources/struct.h"
#include "../../F01-Soldiers/FZZ_extra.h"
#include "F07.1_positionSquad_Station.h"
#include "F07.2_positionZgroup_Station.h"
#include "F07.3_moveSquad_Station.h"
#include "../FJJ_extra.h"

void manageSquadsAndGroups_Stations(squad **squad_list, Zgroup **zgroup_list, station **station_list)
{
    int op = -1, x, y, z;
    string chain, chain2;

    while (op)
    {
        CLEAR_SCREEN;
        coutf(BLUE, "\t\tMENU DE GESTIÓN DE RUTAS DE SERES VIVOS (ESCUADRONES Y GRUPOS) EN ESTACIONES\n\n");
        coutf(BLUE, "1. Posiciona un escuadron en una estación\n");
        coutf(BLUE, "2. Posiciona un grupo de zombies en una estación\n");
        coutf(BLUE, "3. Mueve al escuadron a la siguiente estación\n");
        coutf(BLUE, "4. Hacer que un escuadron vieje desde una estación a otra\n");
        coutf(BLUE, "0. REGRESAR\n\n");

        cinv("int", op); // Usar cinv para obtener y validar la entrada del usuario

        switch (op)
        {
        case 1:
            positionSquad_Station(station_list, squad_list);
            break;
        case 2:
            positionZgroup_Station(station_list, zgroup_list);
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

            if (isSquadListEmpty(*squad_list) == true)
            {
                coutf(RED, "\nNo hay escuadrones, por tanto, no se puede hacer nada.");
                break;
            }

            showSummarySquad(*squad_list);

            coutf(GREEN, "\nIngrese el número del escuadrón de inicio:\n");
            cinv("int", x);

            if (existsSquad(*squad_list, x) == false)
            {
                coutf(RED, "\nNo existe ese escuadron.");
                break;
            }

            if (isSquadConnectedToStation(searchSquad(*squad_list, x)) == false)
            {
                coutf(RED, "\nEl escuadron no esta posicionado en ninguna estación. Posicionalo e intentalo de nuevo.");
                break;
            }

            coutf(BLUE, "\nEscuadron no." + to_string(x) + " en la estación no." + to_string(searchSquad(*squad_list, x)->target_station->number_station) + ".\n");

            showSummaryStations(*station_list);

            coutf(GREEN, "\nIngrese el número de la estación a la que deseas mover el escuadron:\n");
            cinv("int", y);

            if (existsStation(*station_list, y) == false)
            {
                coutf(RED, "\nNo existe esa estación.");
                break;
            }

            moveSquad_Station(station_list, searchSquad(*squad_list, x), y);
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

#endif // F07_MANAGESQUADS_GROUPS_STATIONS_H