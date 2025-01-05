#ifndef F03_3_KILL_SOLDIER_H
#define F03_3_KILL_SOLDIER_H
#include "../../Sources/outools.h"
#include "../../Sources/struct.h"
#include "../FZZ_extra.h"
#include "F03.2_delete_soldier.h"
#include "F03.9_addFallen_soldier.h"
#include "../F05_delete_squad.h"
#include "../F04_manageBpck_squad/F04.8_inherit_items.h"

/**
 * @brief Mata a un soldado heredando su mochila a otro soldado y luego eliminando al soldado.
 *
 * @param squad Puntero al escuadrón.
 * @param soldierName Nombre del soldado a eliminar.
 * @param backpack_list Doble puntero a la lista de mochilas.
 *
 * @details La función hereda la mochila del soldado especificado a otro soldado del escuadrón
 *          (si aplica) y luego añade una copia del soldado en la lista de soldados
 *          fallecidos para despues eliminar al soldado.
 */

void kill_Soldier(squad **squad_list, squad *target_squad, string name, soldier **falle_soldier_list, bpck **backpack_list)
{

    // Heredar la mochila del soldado a eliminar
    inherit_Items(target_squad, name, backpack_list);

    // Añadir una copia del soldado a la lista de soldados caidos
    addFallen_soldier(falle_soldier_list, name);

    // Eliminar al soldado
    delete_Soldier(&(target_squad->list_soldiers), name, backpack_list);

    coutf(BLUE, "\n\nEl soldado " + name + " se encuentra descansando en paz.\n");

    // Si ya no hay soldados en el escuadron, eliminar el escuadron
    if (isSoldierListEmpty(target_squad->list_soldiers) == true)
    {
        delete_Squad(squad_list, target_squad->number, backpack_list);
        coutf(BLUE, "\n\nTodo el escuadron " + to_string(target_squad->number) + " se encuentra descansando en paz.\n");
    }

    return;
};

#endif // F03_3_KILL_SOLDIER_H