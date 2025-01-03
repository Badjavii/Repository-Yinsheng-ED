#ifndef F01_ADD_SQUAD_H
#define F01_ADD_SQUAD_H
#include "../Sources/outools.h"
#include "../Sources/struct.h"
#include "FZZ_extra.h"

/**
 * @brief Crea un nuevo escuadrón.
 *
 * @param number Es el número del escuadrón a crear.
 *
 * @return La función retorna un puntero al nuevo escuadrón creado.
 **/

squad *create_Squad(int number)
{
    squad *newSquad = new squad;
    newSquad->number = number;
    newSquad->list_soldiers = nullptr;
    newSquad->next = nullptr;
    return newSquad;
};

/**
 * @brief Añade un nuevo escuadrón a la lista de escuadrones.
 *
 * @param **squad_list Es un puntero doble a la lista de escuadrones.
 * @param *newSquad Es un puntero al nuevo escuadrón a añadir.
 *
 * @var *current_squad Es un puntero al escuadrón actual en la lista.
 *
 * @return La función no retorna ningún valor.
 */

void add_Squad(squad **squad_list, squad *newSquad)
{
    squad *current_squad = *squad_list;

    if (isSquadListEmpty(current_squad) == true)
    {
        *squad_list = newSquad;
        return;
    }

    while (current_squad->next != nullptr)
        current_squad = current_squad->next;

    current_squad->next = newSquad;
    return;
};

#endif // F01_ADD_SQUAD_H
