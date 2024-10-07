#ifndef STRUCTS_H
#define STRUCTS_H
#include <iostream>
#include <string>

using namespace std;

struct weapons{
    string name;
    string type_weapon;
};

struct Soldier_Equipment{
    weapons* weapon1;
    weapons* weapon2;
    weapons* weapon3;
};

struct Soldier
{
    string name;
    int health;
    Soldier_Equipment* equipment;
    Soldier* next;
};

struct Squads{
    int number;
    Squads* next;
    Soldier* soldiers;
};

struct Zombies{
    string name;
    int damage;
    int health;
};

struct Zombies_Groups{
    int number;
    Zombies* zombies;
    Zombies_Groups* next;
};

struct Maps{
    string name;
    Maps* next;
    Maps* way1;
    Maps* way2;
};


typedef Squads* SquadsPtr;                  // Definir tipo de puntero a nodo "Squads"
typedef Zombies_Groups* Zombies_GroupsPtr;  // Definir tipo de puntero a nodo "Zombies Groups"

#endif // STRUCTS_H
