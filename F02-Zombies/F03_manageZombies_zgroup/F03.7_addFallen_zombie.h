#ifndef F03_7_ADD_FALLEN_ZOMBIE_H
#define F03_7_ADD_FALLEN_ZOMBIE_H
#include "../../Sources/outools.h"
#include "../../Sources/struct.h"
#include "F03.1_add_zombie.h"
#include "../FSS_extra.h"

/**
 * @brief Añade un zombie caído a la lista de zombies caídos.
 *
 * @param fallen_zombies_list Lista de zombies caídos.
 * @param zombie_id ID del zombie a añadir a la lista de zombies caídos.
 * @param type Tipo del zombie.
 *
 * @details La función añade el zombie especificado a la lista de zombies caídos.
 *          Usa la función create_Zombie para crear una copia del zombie con su ID, tipo, salud en 0 y daño original,
 *          y luego lo añade a la lista de zombies caídos usando la función add_Zombie.
 */

void addFallen_zombie(zombie **fallen_zombies_list, int zombie_id, string type)
{
    add_Zombie(fallen_zombies_list, create_Zombie(zombie_id, type, 0, 0));
    return;
};

#endif // F03_7_ADD_FALLEN_ZOMBIE_H