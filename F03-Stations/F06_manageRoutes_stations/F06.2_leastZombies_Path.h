#ifndef LEASTZOMBIES_PATH_H
#define LEASTZOMBIES_PATH_H
#include "../../Sources/outools.h"
#include "../../Sources/struct.h"
#include "../FJJ_extra.h"
#include <iostream>
#include <vector>
#include <limits>
#include <limits.h>
#include <queue>

// Definición de la constante para infINinito
const int INFIN = 1e9; // Un valor muy grande para representar infINinito

/**
 * @brief Encuentra el camino con menos zombies entre dos estaciones utilizando una versión modificada del algoritmo de Dijkstra.
 *
 * @param station_list Lista de estaciones.
 * @param start Estación de inicio.
 * @param end Estación de destino.
 * @return Vector de structs `roots` que representa el camino con menos zombies.
 */

vector<roots> pathWithLeastZombies(station **station_list, int start, int end)
{
    // Obtener el número total de estaciones
    int num_stations = countStations(*station_list);
    cout << "Número total de estaciones: " << num_stations << endl; // Mensaje de depuración

    // Inicializar vectores de distancias, predecesores y visitados
    vector<int> dist(num_stations, INFIN);
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
        cout << "Visitando estación: " << u << endl; // Mensaje de depuración

        // Marcar la estación como visitada
        visited[u] = true;

        // Si llegamos a la estación de destino, salimos del ciclo
        if (u == end)
            break;

        // Obtener la estación actual
        station *current = searchStation(*station_list, u);
        if (current == nullptr)
        {
            cerr << "Error: no se pudo encontrar la estación " << u << endl;
            continue;
        }

        // Recorrer las conexiones adyacentes de la estación actual
        for (conns *conn = current->list_adjacency; conn != nullptr; conn = conn->next)
        {
            int v = conn->destiny->number_station;
            int zombies = conn->destiny->amount_zombies; // Usar la cantidad de zombies como peso

            // Si la estación no ha sido visitada y encontramos un camino con menos zombies
            if (!visited[v] && dist[u] != INFIN && dist[u] + zombies < dist[v])
            {
                dist[v] = dist[u] + zombies;
                prev[v] = current;
                queue.push({dist[v], v});
            }
        }
    }

    // Reconstruir el camino con menos zombies desde la estación de destino a la estación de inicio
    vector<roots> path;
    for (station *at = searchStation(*station_list, end); at != nullptr; at = prev[at->number_station])
    {
        if (prev[at->number_station] != nullptr)
        {
            int zombies = dist[at->number_station] - dist[prev[at->number_station]->number_station];
            path.push_back({prev[at->number_station]->number_station, at->number_station, zombies});
        }
    }

    // Invertir el camino para que esté en orden desde el inicio hasta el destino
    reverse(path.begin(), path.end());

    return path; // Devolver el camino con menos zombies
}

#endif // LEASTZOMBIES_PATH_H