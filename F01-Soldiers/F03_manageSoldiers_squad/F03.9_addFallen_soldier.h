#ifndef F03_10_ADD_FALLEN_SOLDIER_H
#define F03_10_ADD_FALLEN_SOLDIER_H
#include "../../Sources/outools.h"
#include "../../Sources/struct.h"
#include "../FZZ_extra.h"
#include "F03.1_add_soldier.h"

/**
 * @brief Añade un soldado caído a la lista de soldados caídos.
 *
 * @param fallen_soldiers_list Lista de soldados caídos.
 * @param target_soldier Puntero al soldado a añadir a la lista de soldados caídos.
 *
 * @details La función añade el soldado especificado a la lista de soldados caídos.
 *          Usa la función create_Soldier para crear una copia del soldado con su nombre y salud en 0,
 *          y luego lo añade a la lista de soldados caídos usando la función add_Soldier.
 */

void addFallen_soldier(soldier **fallen_soldiers_list, string name)
{
    add_Soldier(fallen_soldiers_list, create_Soldier(name, 0));
    return;
}

#endif // F03_10_ADD_FALLEN_SOLDIER_H