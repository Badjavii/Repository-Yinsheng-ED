#ifndef F04_IMPORT_STATIONS_H
#define F04_IMPORT_STATIONS_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <random>
#include "../Sources/outools.h"
#include "../Sources/struct.h"
#include "../F02-Zombies/FSS_extra.h"
#include "../F03-Stations/F01_add_station.h"
#include "../F03-Stations/F04_add_connection.h"
#include "../F02-Zombies/F01_add_zgroup.h"
#include "../F03-Stations/FJJ_extra.h"
#include "../F02-Zombies/FSS_extra.h"

// Struct para almacenar la información de las conexiones
struct ConnectionInfo
{
    int origin_station;
    int destination_station;
    int weight;
};

/**
 * @brief Muestra el contenido del vector de conexiones ordenadas.
 *
 * @param connections Vector de conexiones ordenadas.
 */
void showConnections(vector<ConnectionInfo> &connections)
{
    if (connections.empty())
    {
        coutf(RED, "\nNo hay conexiones para mostrar.");
        return;
    }

    coutf(YELLOW, "\n\nLista de Conexiones:\n");
    coutf(YELLOW, "=========================\n");

    for (const auto &conn : connections)
    {
        coutf(YELLOW, "Estación de Origen: " + to_string(conn.origin_station) + "\n");
        coutf(YELLOW, "Estación de Destino: " + to_string(conn.destination_station) + "\n");
        coutf(YELLOW, "Peso: " + to_string(conn.weight) + "\n");
        coutf(YELLOW, "-------------------------\n");
    }
    return;
}

/**
 * @brief Crea las conexiones entre las estaciones.
 *
 * @param station_list Lista de estaciones.
 * @param connections Vector de conexiones ordenadas.
 */
void createConnections(station **station_list, const vector<ConnectionInfo> &connections)
{
    for (const auto &conn : connections)
    {
        station *origin_station = searchStation(*station_list, conn.origin_station);
        station *dest_station = searchStation(*station_list, conn.destination_station);
        if (origin_station != nullptr && dest_station != nullptr)
        {
            conns *new_connection = create_Connection(conn.weight, dest_station);
            add_Connection(&(origin_station->list_adjacency), new_connection);
        }
    }
    return;
};

// Función para leer el archivo y procesar la información
void import_Stations(vector<zombie *> &types_Zombies, station **station_list, Zgroup **zgroup_list)
{
    string root = "C:/Mapa.zmb";
    ifstream file(root);
    string line;

    if (!file.is_open())
    {
        cerr << "Error al abrir el archivo: " << root << endl;
        return;
    }
    else
    {
        cout << "Archivo abierto correctamente: " << root << endl;
    }

    getline(file, line); // Leer el número de estaciones

    int station_count = sTOi(line);
    if (station_count <= 0)
    {
        cerr << "Cantidad de estaciones no válida: " << station_count << endl;
        file.close();
        return;
    }

    vector<ConnectionInfo> connections; // Vector para almacenar las conexiones

    while (getline(file, line))
    {
        if (line.empty() || line == "---")
            continue; // Si la línea está vacía o es un separador, pasar a la siguiente

        // Leer el número de la estación
        int station_number = sTOi(line);

        // Leer el nombre de la estación
        if (!getline(file, line))
            break;
        string station_name = line;

        // Crear la estación
        station *new_station = create_station(station_name, station_number, 0);
        add_Station(station_list, new_station);

        // Leer los zombies de la estación
        if (getline(file, line) && line == "-")
        {
            Zgroup *new_zgroup = create_Zgroup(station_number);
            add_Zgroup(zgroup_list, new_zgroup);
            new_station->target_group = new_zgroup;
            new_zgroup->target_station = new_station;

            while (getline(file, line) && line != "--")
            {
                if (line.empty())
                    continue;

                istringstream iss(line);
                int quantity;
                char delim;
                string type;
                iss >> quantity >> delim >> type; // Leer cantidad, delimitador y tipo de la línea

                // Verificar si el tipo de zombie existe, si no, crearlo
                if (!existsTypeZombie(types_Zombies, type))
                {
                    zombie *new_type = new zombie;
                    new_type->id = 0;
                    new_type->type = type;
                    new_type->health = generateRandomNumber(1, 13);
                    new_type->damage = generateRandomNumber(1, 13);
                    new_type->opponent = nullptr;
                    new_type->next = nullptr;
                    types_Zombies.push_back(new_type);
                }

                for (int i = 0; i < quantity; ++i)
                {
                    int random_id;
                    do
                    {
                        random_id = generateRandomNumber(1, 10000);
                    } while (existsZombieInGroup(*zgroup_list, random_id));

                    zombie *new_zombie = new zombie;
                    new_zombie->id = random_id;

                    for (auto &type_zombie : types_Zombies)
                    {
                        if (type_zombie->type == type)
                        {
                            new_zombie->type = type_zombie->type;
                            new_zombie->health = type_zombie->health;
                            new_zombie->damage = type_zombie->damage;
                            break;
                        }
                    }
                    new_zombie->opponent = nullptr;
                    new_zombie->next = nullptr;

                    add_Zombie(&(new_zgroup->list_zombies), new_zombie);
                }
            }

            int amount_zombies = countZombie(new_zgroup->list_zombies);
            new_station->amount_zombies = amount_zombies;

            // Verificar si la lista de zombies del grupo está vacía y eliminar el grupo si es necesario
            if (new_zgroup->list_zombies == nullptr)
            {
                delete_Zgroup(zgroup_list, new_zgroup->number);
            }
        }

        // Leer las conexiones y almacenarlas en el vector
        getline(file, line); // Leer la siguiente línea para verificar si hay conexiones
        if (line != "---")
        {
            if (!line.empty())
            {
                string cadena;
                int i = 0;
                while (i < line.length())
                {
                    int dest_number = 0;
                    int weight = 0;

                    // Leer el número de la estación de destino
                    while (i < line.length() && line[i] != ':')
                    {
                        cadena += line[i++];
                    }
                    dest_number = sTOi(cadena);
                    cadena.clear();
                    i++; // avanzar después del ':'

                    // Leer la ponderación de la conexión
                    while (i < line.length() && line[i] != '|')
                    {
                        cadena += line[i++];
                    }
                    weight = sTOi(cadena);
                    cadena.clear();
                    if (i < line.length())
                    {
                        i++; // avanzar después del '|'
                    }

                    // Crear el trio ordenado y agregarlo al vector
                    ConnectionInfo new_connection;
                    new_connection.origin_station = station_number;
                    new_connection.destination_station = dest_number;
                    new_connection.weight = weight;
                    connections.push_back(new_connection);
                }
            }
        }
    }

    file.close();

    // Crear las conexiones usando el vector de "trios ordenados"
    createConnections(station_list, connections);
}

#endif // F04_IMPORT_STATIONS_H