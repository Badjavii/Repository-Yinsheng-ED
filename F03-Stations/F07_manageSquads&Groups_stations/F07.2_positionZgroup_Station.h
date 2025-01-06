#ifndef F07_2_POSITIONZGROUP_STATION_H
#define F07_2_POSITIONZGROUP_STATION_H
#include "../../Sources/outools.h"
#include "../../Sources/struct.h"
#include "../../F02-Zombies/FSS_extra.h"
#include "../FJJ_extra.h"

void positionZgroup_Station(station **station_list, Zgroup **zgroup_list)
{
    // Verificar si la lista de estaciones está vacía
    if (isStationListEmpty(*station_list) == true)
    {
        coutf(RED, "\nNo hay estaciones, por tanto, no se puede hacer nada.");
        return;
    }

    // Verificar si la lista de grupos de zombies está vacía
    if (isZgroupListEmpty(*zgroup_list) == true)
    {
        coutf(RED, "\nNo hay grupos de zombies, por tanto, no se puede hacer nada.");
        return;
    }

    // Verificar si hay algún grupo de zombies disponible para conectar
    if (isAvalibleAnyZgroupToConnect(*zgroup_list) == false)
    {
        coutf(RED, "\nNo hay ningún grupo de zombies disponible para posicionar en una estación.");
        return;
    }

    // Mostrar resumen de estaciones
    showSummaryStations(*station_list);

    // Solicitar al usuario que ingrese el número de la estación
    int x;
    coutf(GREEN, "\nIngrese el número de la estación:\n");
    cinv("int", x);

    // Verificar si la estación existe
    if (existsStation(*station_list, x) == false)
    {
        coutf(RED, "\nNo existe esa estación.");
        return;
    }

    // Mostrar resumen de grupos de zombies disponibles
    showSummaryAvalibleZgroups(*zgroup_list);

    // Solicitar al usuario que ingrese el número del grupo de zombies
    int y;
    coutf(GREEN, "\nIngrese el número del grupo de zombies:\n");
    cinv("int", y);

    // Verificar si el grupo de zombies existe
    if (!existsZgroup(*zgroup_list, y))
    {
        coutf(RED, "\nNo existe ese grupo de zombies.");
        return;
    }

    // Verificar si el grupo de zombies ya está conectado a una estación
    if (isZgroupConnectedToStation(searchZgroup(*zgroup_list, y)) == true)
    {
        coutf(RED, "\nEse grupo de zombies ya está conectado a una estación.");
        return;
    }

    // Posicionar el grupo de zombies en la estación, sin importar si ya había uno asignado
    station *target_station = searchStation(*station_list, x);
    target_station->target_group = searchZgroup(*zgroup_list, y);
    target_station->amount_zombies = countZombie((*zgroup_list)->list_zombies);
    coutf(GREEN, "\nGrupo de zombies no." + to_string(y) + " posicionado en la estación no." + to_string(x) + ".\n");
}

#endif // F07_2_POSITIONZGROUP_STATION_H