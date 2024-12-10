#ifndef FILE03_2_ELIMINAR_SOLDADO_H
#define FILE03_2_ELIMINAR_SOLDADO_H
#include "../sources/outools.h"
#include "../sources/structs.h"

void EliminarSoldado(SquadsPtr actual_escuadron)
{
    string nombre_soldado;
    coutf(GREEN, "Indique el nombre del soldado a eliminar: ");
    cinv("string", nombre_soldado);

    Soldier *actual_soldado = actual_escuadron->soldiers;
    Soldier *soldado_previo = nullptr;

    while (actual_soldado != nullptr && actual_soldado->name != nombre_soldado)
    {
        soldado_previo = actual_soldado;
        actual_soldado = actual_soldado->next;
    }

    if (actual_soldado != nullptr)
    {
        if (soldado_previo == nullptr)
        {
            actual_escuadron->soldiers = actual_soldado->next;
        }
        else
        {
            soldado_previo->next = actual_soldado->next;
        }
        delete actual_soldado;
        coutf(GREEN, "Soldado eliminado exitosamente.\n");
    }
    else
    {
        coutf(RED, "Soldado no encontrado.\n");
    }
    return;
}

#endif