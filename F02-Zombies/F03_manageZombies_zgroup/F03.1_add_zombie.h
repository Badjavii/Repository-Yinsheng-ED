#ifndef F03_1_ADD_ZOMBIE_H
#define F03_1_ADD_ZOMBIE_H
#include "../../Sources/outools.h"
#include "../../Sources/struct.h"
#include "../FSS_extra.h"

/**
 * @brief Crea un nuevo zombie.
 *
 * @param id ID del zombie.
 * @param type Tipo del zombie.
 * @param health Salud del zombie.
 * @param damage Daño que genera el zombie.
 *
 * @details La función crea un nuevo zombie con los datos especificados y retorna un puntero al mismo.
 *
 * @return Puntero al nuevo zombie creado.
 */

zombie *create_Zombie(int id, string type, int health, int damage)
{
    zombie *newZombie = new zombie;
    newZombie->id = id;
    newZombie->type = type;
    newZombie->health = health;
    newZombie->damage = damage;
    newZombie->opponent = nullptr;
    newZombie->next = nullptr;
    return newZombie;
};

/**
 * @brief Añade un nuevo zombie a la lista de zombies.
 *
 * @param zombie_list Doble puntero a la lista de zombies.
 * @param newZombie Puntero al nuevo zombie a añadir.
 * @details La función añade el nuevo zombie al final de la lista de zombies.
 */

void add_Zombie(zombie **zombie_list, zombie *newZombie)
{
    zombie *current_zombie = *zombie_list;

    if (current_zombie == nullptr)
    {
        *zombie_list = newZombie;
        return;
    }

    while (current_zombie->next != nullptr)
    {
        current_zombie = current_zombie->next;
    }

    current_zombie->next = newZombie;
    return;
};

#endif // F03_1_ADD_ZOMBIE_H