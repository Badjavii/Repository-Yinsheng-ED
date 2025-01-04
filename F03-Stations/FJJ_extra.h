#ifndef FJJ_EXTRA_H
#define FJJ_EXTRA_H
#include "../Sources/outools.h"
#include "../Sources/struct.h"

//******************* LISTAS VACIAS ******************************/

/**
 * @brief isStationListEmpty Verifica si la lista de estaciones está vacía.
 * @brief isConnsListEmpty Verifica si la lista de conexiones está vacía.
 *
 * @param station_list Es un puntero a la lista de estaciones.
 * @param conns_list Es un puntero a la lista de conexiones.
 *
 * @return Todas las funciones retornan true si las listas están vacías, de lo contrario retornan false.
 **/

bool isStationListEmpty(station *station_list)
{
    return (station_list == nullptr);
};

bool isConnsListEmpty(conns *conns_list)
{
    return (conns_list == nullptr);
};

//******************* EXISTE EN LISTA ******************************/

/**
 * @brief existsStation Verifica si una estacion existe en la lista.
 * @brief existsStationWithName Verifica si una estacion con un nombre especifico existe en la lista.
 * @brief existsConns Verifica si una conexión existe en la lista.
 *
 * @param station_list Es un puntero a la lista de estaciones.
 * @param conns_list Es un puntero a la lista de conexiones.
 *
 * @param number Es el número del estacion a buscar.
 * @param id Es el id del zombie a buscar.
 *
 * @return La función existsStation retorna true si la estacion existe, de lo contrario retorna false.
 * @return La función existsConns retorna true si el zombie existe, de lo contrario retorna false.
 * @return La función existsConnsInGroup retorna true si el zombie existe en algún estacion, false en caso contrario.
 **/

bool existsStation(station *station_list, int number)
{
    while (station_list != nullptr)
    {
        if (station_list->number_station == number)
            return true;
        station_list = station_list->next;
    }
    return false;
};

bool existsStationWithName(station *station_list, string name)
{
    while (station_list != nullptr)
    {
        if (station_list->name == name)
            return true;
        station_list = station_list->next;
    }
    return false;
};

bool existsConns(conns *conns_list, int destiny_number, int weight)
{
    while (conns_list != nullptr)
    {
        if (conns_list->destiny->number_station == destiny_number && conns_list->weight == weight)
            return true;
        conns_list = conns_list->next;
    }
    return false;
};

//******************* BUSCAR DENTRO DE LISTA ******************************/

/**
 * @brief searchZgroup Busca un estacion en la lista.
 * @brief searchConns Busca una conexión en la lista.
 *
 * @param station_list Es un puntero a la lista de escuadrones.
 * @param conns_list Es un puntero a la lista de conexiones.
 *
 * @param number Es el número de la estacion a buscar.
 * @param destiny_number Es el numero de la conexión a buscar.

 *
 * @return La función searchZgroup retorna un puntero a la estacion si lo encuentra, de lo contrario retorna nullptr.
 * @return La función searchConns retorna un puntero a la conexión si lo encuentra, de lo contrario retorna nullptr.
 **/

station *searchStation(station *station_list, int number)
{
    while (station_list != nullptr)
    {
        if (station_list->number_station == number)
            return station_list;
        station_list = station_list->next;
    }
    return nullptr;
};

conns *searchConns(conns *conns_list, int destiny_number)
{
    while (conns_list != nullptr)
    {
        if (conns_list->destiny->number_station == destiny_number)
            return conns_list;
        conns_list = conns_list->next;
    }
    return nullptr;
};

//******************* CONTAR DENTRO DE LISTA ******************************/

/**
 * @brief countStations Cuenta el número de estaciones en la lista.
 * @brief countConns Cuenta el número de conxiones en la lista.
 *
 * @param station_list Es un puntero a la lista de estaciones.
 * @param conns_list Es un puntero a la lista de conexiones.
 *
 * @return La función countStations retorna el número de estaciones en la lista.
 * @return La función countConns retorna el número de conxiones en la lista.
 **/

int countStations(station *station_list)
{
    int i = 0;
    while (station_list != nullptr)
    {
        i++;
        station_list = station_list->next;
    }
    return i;
};

int countConns(conns *conns_list)
{
    int i = 0;
    while (conns_list != nullptr)
    {
        i++;
        conns_list = conns_list->next;
    }
    return i;
};

//******************* MOSTRAR DENTRO DE LISTA ******************************/

/**
 * @brief showSummaryStations Muestra un resumen de las estaciones en la lista.
 * @brief showSummaryConns Muestra un resumen de los zombies en la lista.
 *
 * @param station_list Es un puntero a la lista de estaciones.
 * @param conns_list Es un puntero a la lista de conexiones.
 *
 * @details La función showSummaryStations recorre la lista de estaciones y muestra el número de conexiones y la cantidad de zombies en la estacion.
 * La función showSummaryConns recorre la lista de conexiones y muestra los destinos, la distancia, y la cantidad de zombies que hay.
 *
 * @return Ninguna función retorna un valor.
 **/

void showSummaryStations(station *station_list)
{
    coutf(BLUE, "\n\nRESUMEN DE ESTACIONES\n");
    coutf(BLUE, "=============================\n");
    while (station_list != nullptr)
    {
        coutf(BLUE, "- Estacion " + to_string(station_list->number_station) + ": " + station_list->name + " (" + to_string(countConns(station_list->list_adjacency)) + " conexiones y " + to_string(station_list->amount_zombies) + " zombies).\n");
        station_list = station_list->next;
    }
    return;
};

void showSummaryConns(conns *conns_list)
{
    coutf(BLUE, "\n\nRESUMEN DE CONEXIONES\n");
    coutf(BLUE, "=============================\n");
    while (conns_list != nullptr)
    {
        station *destiny_station = conns_list->destiny;
        coutf(BLUE, "- Conexión a estacion " + to_string(destiny_station->number_station) + ": " + destiny_station->name + " (" + to_string(conns_list->weight) + " km y " + to_string(destiny_station->amount_zombies) + " zombies.\n");
        conns_list = conns_list->next;
    }
    return;
};

#endif // FJJ_EXTRA_H