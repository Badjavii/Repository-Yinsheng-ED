#ifndef F07_4_TRAVEL_SQUAD_STATION_H
#define F07_4_TRAVEL_SQUAD_STATION_H
#include "../../Sources/struct.h"
#include "../../Sources/outools.h"
#include "../F06_manageRoutes_stations/F06.1_shortest_Path.h"
#include "../F06_manageRoutes_stations/F06.2_leastZombies_Path.h"
#include "../F06_manageRoutes_stations/F06.3_survivor_Path.h"
#include "F07.1_positionSquad_Station.h"
#include "F07.3_moveSquad_Station.h"
#include "../F05-Game/F01_start_Battle.h"

void travelSquad_Stations(squad **squad_list, station **station_list, Zgroup **zgroup_list, soldier **fallen_soldier_list, zombie **fallen_zombies_list, bpck **backpack_list)
{

    int x, y;

    // Posicionar al escuadron en una estación de inicio
    squad *target_squad = positionSquad_Station(station_list, squad_list);

    if (countStations(*station_list) == 1)
    {
        coutf(RED, "\nSolo hay una estación, por tanto, no se puede hacer nada.");
        return;
    }

    PAUSE_TERMINAL;
    CLEAR_SCREEN;

    // Inicializar el vector de la ruta
    vector<roots> root;

    showSummaryStations(*station_list);

    do
    {
        // Preguntar por el destino final
        coutf(BLUE, "\nIngresa el numero de la estación final o destino final del escuadron:\n");
        cinv("int", x);
    } while (existsStation(*station_list, x) == false);

    // Preguntar que ruta quiere
    coutf(BLUE, "\n\nTIPOS DE RUTAS");
    coutf(BLUE, "\n1. Camino mas corto.");
    coutf(BLUE, "\n2. Camino con menos zombies.");
    coutf(BLUE, "\n3. Camino con mayor probabilidad de sobreviviente (menor distancia y menos zombies).\n");

    do
    {
        coutf(BLUE, "Selecciona un tipo de ruta que quiere que tome el escuadron:\n");
        cinv("int", y);
    } while ((y > 3) || (y < 1));

    // Crear la ruta
    if (y == 1)
    {
        root = shortestPath(station_list, target_squad->target_station->number_station, x);
    }
    else if (y == 2)
    {
        root = pathWithLeastZombies(station_list, target_squad->target_station->number_station, x);
    }
    else
    {
        root = survivorPath(station_list, target_squad->target_station->number_station, x);
    }

    for (int i = 0; ((target_squad->target_station->number_station != x) && (root.size() > i)); i++)
    {

        if ((target_squad->target_station->amount_zombies > 0) && (target_squad->target_station->target_group != nullptr))
        {

            Zgroup *opponente_group = target_squad->target_station->target_group;
            battle(target_squad, opponente_group, squad_list, zgroup_list, fallen_soldier_list, fallen_zombies_list, backpack_list);
        }

        if (target_squad == nullptr)
        {
            return;
        }

        moveSquad_Station(station_list, target_squad, root[i].destination_station);
    }

    if (target_squad->target_station->number_station == x)
    {
        coutf(BLUE, "\nEl escuadron completo el viaje con exito! Se encuentran en la estación no." + to_string(x) + ".\n");
    }
    return;
}

#endif // F07_4_TRAVEL_SQUAD_STATION_H