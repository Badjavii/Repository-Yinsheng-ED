#ifndef F06_1_SHORTEST_PATH_H
#define F06_1_SHORTEST_PATH_H
#include "../../Sources/outools.h"
#include "../../Sources/struct.h"
#include "../FJJ_extra.h"

#include <iostream>
#include <vector>
#include <limits>
#include <limits.h>
#include <queue>

// Definición de la constante para infinito
const int INF = 1000000000; // Un valor muy grande para representar infinito

/**
 * @brief Encuentra el camino más corto entre dos estaciones utilizando el algoritmo de Dijkstra.
 *
 * @param station_list Lista de estaciones.
 * @param start Estación de inicio.
 * @param end Estación de destino.
 * @return Vector de structs `roots` que representa el camino más corto.
 */
/*
vector<roots> shortestPath(station **station_list, int start, int end)
{

    cout << "\n\nPRUEBAAAAAAA";

    // Obtener el número total de estaciones
    int num_stations = countStations(*station_list);

    // Inicializar vectores de distancias, predecesores y visitados
    vector<int> dist(num_stations, INF);
    vector<station *> prev(num_stations, nullptr);
    vector<bool> visited(num_stations, false);

    // Establecer la distancia a la estación de inicio a 0
    dist[start] = 0;

    // Cola de prioridad para almacenar las estaciones por explorar
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;
    queue.push({0, start});

    // Ciclo principal del algoritmo de Dijkstra
    while (!queue.empty())
    {
        // Extraer la estación con la menor distancia
        int u = queue.top().second;
        queue.pop();

        // Marcar la estación como visitada
        visited[u] = true;

        // Si llegamos a la estación de destino, salimos del ciclo
        if (u == end)
            break;

        // Obtener la estación actual
        station *current = searchStation(*station_list, u);

        // Recorrer las conexiones adyacentes de la estación actual
        for (conns *conn = current->list_adjacency; conn != nullptr; conn = conn->next)
        {
            int v = conn->destiny->number_station;
            int weight = conn->weight;

            // Si la estación no ha sido visitada y encontramos un camino más corto
            if (!visited[v] && dist[u] != INF && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                prev[v] = current;
                queue.push({dist[v], v});
            }
        }
    }

    // Reconstruir el camino más corto desde la estación de destino a la estación de inicio
    vector<roots> path;
    for (station *at = searchStation(*station_list, end); at != nullptr; at = prev[at->number_station])
    {
        if (prev[at->number_station] != nullptr)
        {
            int weight = dist[at->number_station] - dist[prev[at->number_station]->number_station];
            path.push_back({prev[at->number_station]->number_station, at->number_station, weight});
        }
    }

    // Invertir el camino para que esté en orden desde el inicio hasta el destino
    for (int i = 0, j = path.size() - 1; i < j; ++i, --j)
    {
        roots temp = path[i];
        path[i] = path[j];
        path[j] = temp;
    }

    return path; // Devolver el camino más corto
}
*/

#include <iostream>
#include <vector>
#include <limits>
#include <queue>

/**
 * @brief Encuentra el camino más corto entre dos estaciones utilizando el algoritmo de Dijkstra.
 *
 * @param station_list Lista de estaciones.
 * @param start Estación de inicio.
 * @param end Estación de destino.
 * @return Vector de structs `roots` que representa el camino más corto.
 */
vector<roots> shortestPath(station **station_list, int start, int end)
{
    std::cout << "\n\nPRUEBAAAAAAA";

    // Verificar que las estaciones de inicio y fin sean válidas
    if (start < 0 || end < 0)
    {
        std::cerr << "Error: El índice de la estación de inicio o fin es inválido." << std::endl;
        return {};
    }

    int num_stations = countStations(*station_list);
    if (start >= num_stations || end >= num_stations)
    {
        std::cerr << "Error: El índice de la estación de inicio o fin está fuera del rango." << std::endl;
        return {};
    }

    vector<int> dist(num_stations, INF);
    vector<station *> prev(num_stations, nullptr);

    // Inicializar las estaciones como no visitadas
    station *current_station = *station_list;
    while (current_station != nullptr)
    {
        current_station->visited = false;
        current_station = current_station->next;
    }

    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;
    queue.push({0, start});

    while (!queue.empty())
    {
        int u = queue.top().second;
        queue.pop();

        // Marcar la estación como visitada
        station *current = searchStation(*station_list, u);
        if (current == nullptr)
        {
            std::cerr << "Error: No se pudo encontrar la estación " << u << std::endl;
            continue;
        }

        current->visited = true;

        std::cout << "Visitando estación: " << u << std::endl;

        if (u == end)
            break;

        for (conns *conn = current->list_adjacency; conn != nullptr; conn = conn->next)
        {
            int v = conn->destiny->number_station;
            int weight = conn->weight;
            station *next_station = searchStation(*station_list, v);

            if (next_station == nullptr)
            {
                std::cerr << "Error: No se pudo encontrar la estación destino " << v << std::endl;
                continue;
            }

            if (!next_station->visited && dist[u] != INF && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                prev[v] = current;
                queue.push({dist[v], v});
                std::cout << "Actualizando distancia de estación " << v << " a " << dist[v] << std::endl;
            }
        }
    }

    vector<roots> path;
    for (station *at = searchStation(*station_list, end); at != nullptr; at = prev[at->number_station])
    {
        if (prev[at->number_station] != nullptr)
        {
            int weight = dist[at->number_station] - dist[prev[at->number_station]->number_station];
            path.push_back({prev[at->number_station]->number_station, at->number_station, weight});
        }
    }

    reverse(path.begin(), path.end());

    // Imprimir el camino encontrado para depuración
    std::cout << "Camino encontrado:\n";
    for (const auto &r : path)
    {
        std::cout << "De estación " << r.origin_station << " a estación " << r.destination_station << " con peso " << r.weight << std::endl;
    }

    return path;
}

#endif // F06_1_SHORTEST_PATH_H