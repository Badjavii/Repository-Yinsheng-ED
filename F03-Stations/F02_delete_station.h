#ifndef F02_DELETE_STATION_H
#define F02_DELETE_STATION_H
#include "../Sources/outools.h"
#include "../Sources/struct.h"
#include "F05_delete_connection.h"
#include "FJJ_extra.h"

/**
 * @brief Elimina una estación de la lista de estaciones.
 *
 * @param station_list Lista de estaciones.
 * @param station_number Número de la estación a eliminar.
 */
void delete_Station(station **station_list, int station_number)
{
    if (*station_list == nullptr)
    {
        return;
    }

    station *current_station = *station_list;
    station *prev_station = nullptr;

    // Buscar la estación a eliminar
    while (current_station != nullptr)
    {
        if (current_station->number_station == station_number)
        {
            // Eliminar todas las conexiones de la estación
            conns *current_connection = current_station->list_adjacency;
            while (current_connection != nullptr)
            {
                conns *next_connection = current_connection->next;
                delete_Conns(&(current_station->list_adjacency), current_connection->destiny->number_station, current_connection->weight);
                current_connection = next_connection;
            }

            // Desconectar la estación de la lista de estaciones
            if (prev_station == nullptr)
            {
                // La estación a eliminar es la primera en la lista
                *station_list = current_station->next;
            }
            else
            {
                prev_station->next = current_station->next;
            }

            // Desconectar con el grupo de zombies
            current_station->target_group->target_station = nullptr;
            current_station->target_group = nullptr;

            // Desconectar con el escuadron de soldados
            current_station->target_squad = nullptr;

            // Desconectar el nodo antes de eliminarlo
            current_station->next = nullptr;

            // Liberar la memoria de la estación eliminada
            delete current_station;
            return;
        }

        prev_station = current_station;
        current_station = current_station->next;
    }
    return;
};

#endif // F02_DELETE_STATION_H