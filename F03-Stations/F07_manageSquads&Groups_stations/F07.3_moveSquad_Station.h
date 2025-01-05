#ifndef F07_3_MOVESQUAD_STATION_H
#define F07_3_MOVESQUAD_STATION_H
#include "../../Sources/outools.h"
#include "../../Sources/struct.h"
#include "../../F02-Zombies/FSS_extra.h"
#include "../FJJ_extra.h"

/**
 * @brief Mueve un escuadrón de su estación actual a una nueva estación.
 *
 * @param station_list Puntero a la lista de estaciones.
 * @param moving_squad Puntero al escuadrón que se va a mover.
 * @param new_station_number Número de la nueva estación a la que se va a mover el escuadrón.
 */
void moveSquad_Station(station **station_list, squad *moving_squad, int next_station_number)
{
    // Buscar la nueva estación por su número
    station *next_station = searchStation(*station_list, next_station_number);
    if (next_station == nullptr)
    {
        coutf(RED, "\nLa estación con el número " + to_string(next_station_number) + " no existe.\n");
        return;
    }

    // Desconectar cualquier escuadrón previamente conectado a la nueva estación
    if (next_station->target_squad != nullptr)
    {
        next_station->target_squad->target_station = nullptr;
        next_station->target_squad = nullptr;
    }

    // Conectar la nueva estación a el escuadrón
    next_station->target_squad = moving_squad;

    // Desconectar el escuadrón de su estación actual
    moving_squad->target_station->target_squad = nullptr;

    // Conectar el escuadrón a la nueva estación
    moving_squad->target_station = next_station;

    coutf(GREEN, "\nEscuadrón no." + to_string(moving_squad->number) + " movido a la estación no." + to_string(next_station_number) + ".\n");
    return;
}

#endif // F07_3_MOVESQUAD_STATION_H