#ifndef FJJ_EXTRA_H
#define FJJ_EXTRA_H
#include "../Sources/outools.h"
#include "../Sources/struct.h"

//******************* LISTAS VACIAS ******************************/

/**
 * @brief isStationListEmpty Verifica si la lista de estaciones está vacía.
 * @brief isConnsListEmpty Verifica si la lista de conexiones está vacía.
 * @brief isAvalibleAnySquadToConnect Verifica si hay algún escuadrón que no se encuentra en ninguna estación.
 * @brief isAvalibleAnyZgroupToConnect Verifica si hay algún grupo de zombies que no se encuentra en ninguna estación.
 * @brief isSquadConnectedToStation Verifica si un escuadrón está conectado a alguna estación.
 * @brief isZgroupConnectedToStation Verifica si un grupo de zombies está conectado a alguna estación.
 *
 * @param station_list Es un puntero a la lista de estaciones.
 * @param conns_list Es un puntero a la lista de conexiones.
 * @param squad_list Puntero a la lista de escuadrones.
 * @param squad Puntero al escuadrón a verificar.
 * @param zgroup Puntero al grupo de zombies a verificar.
 *
 *
 * @return Todas las funciones retornan true si las listas están vacías, de lo contrario retornan false.
 * @return isAvalibleAnySquadToConnect true si hay algún escuadrón disponible, false en caso contrario.
 * @return isAvalibleAnyZgroupToConnect true si hay algún grupo de zombies disponible, false en caso contrario.
 * @return isSquadConnectedToStation true si el escuadrón está conectado a alguna estación, false en caso contrario.
 * @return isZgroupConnectedToStation true si el grupo de zombies está conectado a alguna estación, false en caso contrario.
 **/

bool isStationListEmpty(station *station_list)
{
    return (station_list == nullptr);
};

bool isConnsListEmpty(conns *conns_list)
{
    return (conns_list == nullptr);
};

bool isSquadConnectedToStation(squad *squad)
{
    return squad->target_station != nullptr;
};

bool isZgroupConnectedToStation(Zgroup *zgroup)
{
    return zgroup->target_station != nullptr;
};

bool isAvalibleAnySquadToConnect(squad *squad_list)
{
    // Recorrer la lista de escuadrones
    squad *current_squad = squad_list;
    while (current_squad != nullptr)
    {
        // Si encontramos un escuadrón que no está asignado a ninguna estación, retornamos true
        if (isSquadConnectedToStation(current_squad) == false)
        {
            return true;
        }

        current_squad = current_squad->next;
    }

    // Si todos los escuadrones están asignados a alguna estación, retornamos false
    return false;
};

bool isAvalibleAnyZgroupToConnect(Zgroup *zgroup_list)
{
    // Recorrer la lista de grupos de zombies
    Zgroup *current_zgroup = zgroup_list;
    while (current_zgroup != nullptr)
    {
        // Si encontramos un grupo de zombies que no está asignado a ninguna estación, retornamos true
        if (isZgroupConnectedToStation(current_zgroup) == false)
        {
            return true;
        }

        current_zgroup = current_zgroup->next;
    }

    // Si todos los grupos de zombies están asignados a alguna estación, retornamos false
    return false;
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
 * @brief searchMinWeightConns Busca la adyacencia con el menor peso en una lista de conexiones.
 *
 * @param station_list Es un puntero a la lista de escuadrones.
 * @param conns_list Es un puntero a la lista de conexiones.
 * @param list_adjacency Puntero a la lista de conexiones adyacentes.
 *
 * @param number Es el número de la estacion a buscar.
 * @param destiny_number Es el numero de la conexión a buscar.

 *
 * @return La función searchZgroup retorna un puntero a la estacion si lo encuentra, de lo contrario retorna nullptr.
 * @return La función searchConns retorna un puntero a la conexión si lo encuentra, de lo contrario retorna nullptr.
 * @return La función searchMinWeightConns retorna un puntero a la conexión con el menor peso.
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

conns *searchMinWeightConns(conns *list_adjacency)
{
    if (list_adjacency == nullptr)
    {
        return nullptr; // Retornar nullptr si la lista está vacía
    }

    conns *min_conns = list_adjacency;
    conns *current_conns = list_adjacency->next;

    // Recorrer la lista de conexiones adyacentes
    while (current_conns != nullptr)
    {
        // Comparar pesos para encontrar el menor
        if (current_conns->weight < min_conns->weight)
        {
            min_conns = current_conns; // Actualizar la conexión con el menor peso
        }
        current_conns = current_conns->next;
    }

    return min_conns; // Retornar la conexión con el menor peso
}

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
 * @brief showSummaryAvalibleSquads Muestra un resumen de todos los escuadrones que no han sido conectados a ninguna estación.
 * @brief showSummaryAvalibleZgroups Muestra un resumen de todos los grupos de zombies que no han sido conectados a ninguna estación.
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
        if (station_list->target_group != nullptr)
        {
            coutf(BLUE, "   - Conectado con el grupo no." + to_string(station_list->target_group->number) + "\n");
        }
        else
        {
            coutf(BLUE, "   - Sin grupo conectado.\n");
        }

        if (station_list->target_squad != nullptr)
        {
            coutf(BLUE, "   - Conectado con el escuadron no." + to_string(station_list->target_squad->number) + "\n");
        }
        else
        {
            coutf(BLUE, "   - Sin escuadron conectado.\n");
        }
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

void showSummaryAvalibleSquads(squad *squad_list)
{
    coutf(BLUE, "\n\nRESUMEN DE ESCUADRONES DISPONIBLES\n");
    coutf(BLUE, "=============================\n");

    squad *current_squad = squad_list;
    while (current_squad != nullptr)
    {
        if (isSquadConnectedToStation(current_squad) == false)
        {
            coutf(BLUE, "- Escuadrón no." + to_string(current_squad->number) + " ( " + to_string(countSoldier(current_squad->list_soldiers)) + " soldados).\n");
        }
        current_squad = current_squad->next;
    }

    return;
};

void showSummaryAvalibleZgroups(Zgroup *zgroup_list)
{
    coutf(BLUE, "\n\nRESUMEN DE GRUPOS DE ZOMBIES DISPONIBLES\n");
    coutf(BLUE, "=============================\n");

    Zgroup *current_zgroup = zgroup_list;
    while (current_zgroup != nullptr)
    {
        if (!isZgroupConnectedToStation(current_zgroup))
        {
            coutf(BLUE, "- Grupo de zombies no." + to_string(current_zgroup->number) + " (" + to_string(countZombie(current_zgroup->list_zombies)) + " zombies).\n");
        }
        current_zgroup = current_zgroup->next;
    }

    return;
};

#endif // FJJ_EXTRA_H