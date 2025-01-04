#ifndef F05_DELETE_CONNECTION_H
#define F05_DELETE_CONNECTION_H
#include "../Sources/outools.h"
#include "../Sources/struct.h"
#include "FJJ_extra.h"

/**
 * @brief Elimina una conexión de la lista de conexiones de una estación.
 *
 * @param connection_list Lista de conexiones.
 * @param destination_station Número de la estación de destino de la conexión a eliminar.
 */
void delete_Conns(conns **connection_list, int destination_station, int weight)
{
    if (*connection_list == nullptr)
    {
        return;
    }

    conns *current_connection = *connection_list;
    conns *prev_connection = nullptr;

    while (current_connection != nullptr)
    {
        if (current_connection->destiny != nullptr && current_connection->destiny->number_station == destination_station && current_connection->weight == weight)
        {
            // Desconectar la conexión de la lista de conexiones
            if (prev_connection == nullptr)
            {
                // La conexión a eliminar es la primera en la lista
                *connection_list = current_connection->next;
            }
            else
            {
                prev_connection->next = current_connection->next;
            }

            // Desconectar el puntero de destino
            current_connection->destiny = nullptr;

            // Desconectar el nodo antes de eliminarlo
            current_connection->next = nullptr;

            // Liberar la memoria de la conexión eliminada
            delete current_connection;
            return;
        }

        prev_connection = current_connection;
        current_connection = current_connection->next;
    }
    return;
};

#endif // F05_DELETE_CONNECTION_H