#ifndef STRUCTS_H
#define STRUCTS_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> items_ofensivos = {"Katana", "Cuchillo", "Pistola", "Ametralladora", "Rifle", "Escopeta", "Pistola de ácido"};
vector<string> items_defensivos = {"Granada explosiva", "Granada de humo", "Granada P2-Z", "Armadura", "Escudo"};
vector<string> items_curacion = {"Vendas", "Pociones carne zombie", "Botiquines"};

struct items
{
    string name;
    string type_item;
};

struct Soldier_Equipment
{
    items *item1;
    items *item2;
    items *item3;
};

struct Soldier
{
    string name;
    string range;
    int health;
    Soldier_Equipment *equipment;
    Soldier *next;
};

struct Squads
{
    int number;
    Squads *next;
    Soldier *soldiers;
};

struct Zombies
{
    string name;
    string type;
    int damage;
    int health;
    Zombies *next;
};

struct Zombies_Groups
{
    int number;
    Zombies *zombies;
    Zombies_Groups *next;
};

struct Estacion
{
    string nombre;
    Estacion *siguiente;
    Estacion *conexiones;
    Zombies_Groups *grupo_zombies;
    Squads *escuadron_antizombies;
};

struct Mapa
{
    Estacion *estaciones;
};

typedef Squads *SquadsPtr;                 // Definir tipo de puntero a nodo "Squads"
typedef Zombies_Groups *Zombies_GroupsPtr; // Definir tipo de puntero a nodo "Zombies Groups"
typedef Mapa *MapaPtr;                     // Definir tipo de puntero a nodo "Mapa"
typedef Estacion *EstacionPtr;             // Definir tipo de puntero a nodo "Estacion"

#endif // STRUCTS_H
