#ifndef F01_ADD_STATION_H
#define F01_ADD_STATION_H
#include "../Sources/outools.h"
#include "../Sources/struct.h"
#include "FJJ_extra.h"

/**
 * @brief Crea una nueva estación.
 *
 * @param name Nombre de la estación.
 * @param number Número de la estación.
 * @param amount_zombies Número de zombies en la estación.
 *
 * @return La función retorna un puntero a la nueva estación creada.
 */
station *create_station(string name, int number, int amount_zombies)
{
    station *new_station = new station;
    new_station->name = name;
    new_station->number_station = number;
    new_station->amount_zombies = amount_zombies;
    new_station->target_squad = nullptr;
    new_station->target_group = nullptr;
    new_station->list_adjacency = nullptr;
    new_station->next = nullptr;
    return new_station;
};

/**
 * @brief Añade una nueva estación a la lista de estaciones.
 *
 * @param station_list Es un puntero doble a la lista de estaciones.
 * @param new_station Es un puntero a la nueva estación a añadir.
 *
 * @return La función no retorna ningún valor.
 */
void add_Station(station **station_list, station *new_station)
{
    station *current_station = *station_list;

    if (current_station == nullptr)
    {
        *station_list = new_station;
        return;
    }

    while (current_station->next != nullptr)
    {
        current_station = current_station->next;
    }

    current_station->next = new_station;
    return;
};

#endif // F01_ADD_STATION_H