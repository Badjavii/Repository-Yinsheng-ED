#ifndef F01_ADD_ZGROUP_H
#define F01_ADD_ZGROUP_H
#include "../Sources/outools.h"
#include "../Sources/struct.h"
#include "FSS_extra.h"

/**
 * @brief Crea un nuevo grupo de zombies.
 *
 * @param number Es el número del grupo de zombies a crear.
 *
 * @return La función retorna un puntero al nuevo grupo de zombies creado.
 */

Zgroup *create_Zgroup(int number)
{
    Zgroup *newZgroup = new Zgroup;
    newZgroup->number = number;
    newZgroup->list_zombies = nullptr;
    newZgroup->target_station = nullptr;
    newZgroup->next = nullptr;
    return newZgroup;
};

/**
 * @brief Añade un nuevo grupo de zombies a la lista de grupos de zombies.
 *
 * @param zgroup_list Es un puntero doble a la lista de grupos de zombies.
 * @param newZgroup Es un puntero al nuevo grupo de zombies a añadir.
 *
 * @return La función no retorna ningún valor.
 */

void add_Zgroup(Zgroup **zgroup_list, Zgroup *newZgroup)
{
    Zgroup *current_zgroup = *zgroup_list;

    if (current_zgroup == nullptr)
    {
        *zgroup_list = newZgroup;
        return;
    }

    while (current_zgroup->next != nullptr)
    {
        current_zgroup = current_zgroup->next;
    }

    current_zgroup->next = newZgroup;
    return;
};

#endif // F01_ADD_ZGROUP_H