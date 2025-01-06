#ifndef F07_1_POSITION_SQUAD_STATION_H
#define F07_1_POSITION_SQUAD_STATION_H
#include "../../Sources/outools.h"
#include "../../Sources/struct.h"
#include "../../F01-Soldiers/FZZ_extra.h"
#include "../FJJ_extra.h"

squad *positionSquad_Station(station **station_list, squad **squad_list)
{
    // Verificar si la lista de estaciones está vacía
    if (isStationListEmpty(*station_list) == true)
    {
        coutf(RED, "\nNo hay estaciones, por tanto, no se puede hacer nada.");
        return nullptr;
    }

    // Verificar si la lista de escuadrones está vacía
    if (isSquadListEmpty(*squad_list) == true)
    {
        coutf(RED, "\nNo hay escuadrones, por tanto, no se puede hacer nada.");
        return nullptr;
    }

    // Verificar si hay algún escuadrón disponible para conectar
    if (isAvalibleAnySquadToConnect(*squad_list) == false)
    {
        coutf(RED, "\nNo hay ninguna estación disponible para posicionar un escuadron.");
        return nullptr;
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
        return nullptr;
    }

    // Mostrar resumen de escuadrones disponibles
    showSummaryAvalibleSquads(*squad_list);

    // Solicitar al usuario que ingrese el número del escuadrón
    int y;
    coutf(GREEN, "\nIngrese el número del escuadron:\n");
    cinv("int", y);

    // Verificar si el escuadrón existe
    if (existsSquad(*squad_list, y) == false)
    {
        coutf(RED, "\nNo existe ese escuadron.");
        return nullptr;
    }

    // Verificar si el escuadrón ya está conectado a una estación
    if (isSquadConnectedToStation(searchSquad(*squad_list, y)) == true)
    {
        coutf(RED, "\nEse escuadron ya está conectado a una estación.");
        return nullptr;
    }

    // Posicionar el escuadrón en la estación, sin importar si ya había uno asignado
    squad *target_squad = searchSquad(*squad_list, y);
    target_squad->target_station = searchStation(*station_list, x);
    target_squad->target_station->target_squad = target_squad;
    coutf(GREEN, "\nEscuadron no." + to_string(y) + " posicionado en la estación no." + to_string(x) + ".\n");
    return target_squad;
};

#endif // F07_1_POSITION_SQUAD_STATION_H