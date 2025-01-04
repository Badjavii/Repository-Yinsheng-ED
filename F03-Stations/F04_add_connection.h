#ifndef F04_ADD_CONNECTION_H
#define F04_ADD_CONNECTION_H
#include "../Sources/outools.h"
#include "../Sources/struct.h"

/**
 * @brief Crea una nueva conexión entre estaciones.
 *
 * @param weight Peso de la conexión (distancia).
 * @param destiny Puntero a la estación de destino.
 *
 * @return La función retorna un puntero a la nueva conexión creada.
 */

conns *create_Connection(int weight, station *destiny)
{
    conns *new_connection = new conns;
    new_connection->weight = weight;
    new_connection->destiny = destiny;
    new_connection->next = nullptr;
    return new_connection;
}

/**
 * @brief Añade una nueva conexión a la lista de conexiones de una estación.
 *
 * @param connection_list Es un puntero doble a la lista de conexiones.
 * @param new_connection Es un puntero a la nueva conexión a añadir.
 *
 * @return La función no retorna ningún valor.
 */

void add_Connection(conns **connection_list, conns *new_connection)
{
    conns *current_connection = *connection_list;

    if (current_connection == nullptr)
    {
        *connection_list = new_connection;
        return;
    }

    while (current_connection->next != nullptr)
    {
        current_connection = current_connection->next;
    }

    current_connection->next = new_connection;
    return;
}

#endif // F04_ADD_CONNECTION_H