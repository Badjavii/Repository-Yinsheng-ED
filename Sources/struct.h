#ifndef STRUCT_H
#define STRUCT_H

//******************* MOCHILAS ******************************/

// Estructura que representa un ítem
struct item
{
    string name;      // Nombre del ítem
    string type_item; // Tipo de ítem (arma, defensa, curación)
    int usages;       // Número de usos del ítem
    int effect_value; // Valor de daño o capacidad de curación
    item *next;       // Puntero al siguiente ítem en la lista
};

// Estructura que representa una mochila
struct bpck
{
    string name;      // Nombre de la mochila
    item *list_items; // Puntero a la lista de ítems en la mochila
    bpck *next;       // Puntero a la siguiente mochila en la lista
};

//******************* SOLDADOS ******************************/

struct zombie;  // Declaración adelantada de la estructura zombie
struct station; // Declaración adelantada de la estructura station

// Estructura que representa un soldado
struct soldier
{
    string name;      // Nombre del soldado
    int health;       // Salud del soldado
    bpck *backpag;    // Puntero a la mochila del soldado
    zombie *opponent; // Puntero al zombie que atacará
    soldier *next;    // Puntero al siguiente soldado en la lista
};

// Estructura que representa un escuadrón
struct squad
{
    int number;              // Número del escuadrón
    soldier *list_soldiers;  // Puntero a la lista de soldados en el escuadrón
    station *target_station; // Puntero a la estación que se encuentra el grupo
    squad *next;             // Puntero al siguiente escuadrón en la lista
};

//******************* ZOMBIES ******************************/

// Estructura que representa un zombie
struct zombie
{
    int id;            // ID del zombie
    string type;       // Tipo del zombie
    int health;        // Salud del zombie
    int damage;        // Daño que genera el zombie
    soldier *opponent; // Puntero al soldado que atacará
    zombie *next;      // Puntero al siguiente zombie en la lista
};

// Estructura que representa un grupo de zombies
struct Zgroup
{
    int number;              // Número del grupo
    zombie *list_zombies;    // Puntero a la lista de zombies en el grupo
    station *target_station; // Puntero a la estación que se encuentra el grupo
    Zgroup *next;            // Puntero al siguiente grupo en la lista
};

//******************* ESTACIONES ******************************/

// Estructura que representa una conexión entre estaciones
struct conns
{
    int weight;       // Peso de la conexión (distancia)
    station *destiny; // Puntero a la estación de destino
    conns *next;      // Puntero a la siguiente conexión en la lista
};

// Estructura que representa una estación
struct station
{
    string name;           // Nombre de la estación
    int number_station;    // Número de la estación
    int amount_zombies;    // Número de zombies en la estación
    squad *target_squad;   // Puntero al escuadron
    Zgroup *target_group;  // Puntero al grupo de zombies
    conns *list_adjacency; // Puntero a la lista de conexiones adyacentes
    station *next;         // Puntero a la siguiente estación en la lista
    bool visited;
};

// Struct para almacenar la información de las conexiones
struct roots
{
    int origin_station;
    int destination_station;
    int weight;
};

#endif // STRUCT_H