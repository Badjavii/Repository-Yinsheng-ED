/*Esta libreria, aparte de contener la definicion (o programacion) de 
la estructuras, tambien contiene la declaracion de las funciones que se 
encargan de hacer la insercion en las estructuras que ultizara el DocManager
para hacer la importacion de datos desde los archivos de texto al programa principal*/


#ifndef STRUCTS_H
#define STRUCTS_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Items Ofensivos
vector<string> items_ofensivos = {"Katana", "Cuchillo", "Pistola", "Ametralladora", "Rifle", "Escopeta", "Pistola de ácido"};
vector<int> uses_item_ofensivo = {20, 50, 30, 140, 60, 15, 40};
vector<int> xp_item_ofensivo = {10, 5, 12, 50, 30, 25, 18};
vector<string> description_item_ofensivo = {
    "Corte preciso, pero alta exposición.",
    "Muy poco eficaz.",
    "Eficaz a corta distancia.",
    "Alta cadencia, pero difícil de controlar.",
    "Precisión a larga distancia.",
    "Potencia devastadora, pero lenta recarga.",
    "Daño continuo, pero limitada munición."
};

// Items Defensivos
vector<string> items_defensivos = {"Granada explosiva", "Granada de humo", "Granada P2-Z", "Armadura", "Escudo"};
vector<int> uses_item_defensivos = {3, 6, 2, 10, 12};
vector<int> xp_item_defensivo = {20, 10, 30, 40, 25};
vector<string> description_item_defensivo = {
    "Daño en área, pero uso limitado.",
    "Ocultación temporal.",
    "Desactiva electrónica, pero rara.",
    "Protección extra, pero pesada.",
    "Bloquea ataques, pero reduce movilidad."
};

// Items Curacion
vector<string> items_curacion = {"Vendas", "Pociones carne zombie", "Botiquines"};
vector<int> uses_item_curacion = {6, 1, 3};
vector<int> xp_item_curacion = {5, 20, 15};
vector<string> description_item_curacion = {
    "Curación provisional.",
    "En caso de emergencias.",
    "Efectivos, pero escasos."
};

struct items
{
    string name;
    string type_item;
    string description;
    int xp;
    int uses;
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

// Definicion de nuevos tipos de punteros
typedef Squads *SquadsPtr;                 // Definir tipo de puntero a nodo "Squads"
typedef Zombies_Groups *Zombies_GroupsPtr; // Definir tipo de puntero a nodo "Zombies Groups"
typedef Mapa *MapaPtr;                     // Definir tipo de puntero a nodo "Mapa"
typedef Estacion *EstacionPtr;             // Definir tipo de puntero a nodo "Estacion"

// Declaracion de funciones de insercion para el DocManager
void insertarSoldado(Soldier **head, Soldier *newSoldier);
void insertarGrupoZombies(Zombies_Groups **head, int number, Zombies *zombies);
void insertarEstacion(Mapa **mapa, const string &nombre, Estacion *conexiones, Zombies_Groups *grupo_zombies, Squads *escuadron_antizombies);

#endif // STRUCTS_H
