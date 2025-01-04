#ifndef F03_CONSULT_STATIONS_H
#define F03_CONSULT_STATIONS_H
#include "../Sources/outools.h"
#include "../Sources/struct.h"
#include "FJJ_extra.h"

/**
 * @brief Consulta las estaciones y muestra la información detallada.
 *
 * @param station_list Lista de estaciones.
 * @details La función recorre cada estación y muestra la información detallada de cada una, incluyendo la cantidad de zombies y las conexiones con otras estaciones.
 */
void consult_Station(station *station_list)
{
    if (station_list == nullptr)
    {
        coutf(RED, "\nNo hay estaciones.");
        return;
    }

    station *current_station = station_list;

    coutf(YELLOW, "\n\nCONSULTA DE ESTACIONES\n");
    coutf(YELLOW, "========================================\n");

    while (current_station != nullptr)
    {
        coutf(YELLOW, "\nEstación No. " + to_string(current_station->number_station) + ":\n");
        coutf(YELLOW, "Nombre: " + current_station->name + "\n");
        coutf(YELLOW, "Cantidad de Zombies: " + to_string(current_station->amount_zombies) + "\n");

        if (current_station->list_adjacency == nullptr)
        {
            coutf(YELLOW, "  No hay conexiones en esta estación.\n");
        }
        else
        {
            coutf(YELLOW, "Conexiones:\n");
            conns *current_connection = current_station->list_adjacency;
            while (current_connection != nullptr)
            {
                coutf(YELLOW, "  - Estación: " + to_string(current_connection->destiny->number_station) + ", " + current_connection->destiny->name + "\n");
                coutf(YELLOW, "    Distancia: " + to_string(current_connection->weight) + "\n");
                current_connection = current_connection->next;
            }
        }

        current_station = current_station->next;
        coutf(YELLOW, "----------------------------------------\n");
    }

    return;
};

#endif // F03_CONSULT_STATIONS_H