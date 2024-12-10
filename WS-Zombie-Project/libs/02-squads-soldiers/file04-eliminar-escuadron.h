#ifndef FILE04_ELIMINAR_ESCUADRON_H
#define FILE04_ELIMINAR_ESCUADRON_H
#include "../sources/outools.h"
#include "../sources/structs.h"
#include "file11-sources.h"

void EliminarEscuadron(SquadsPtr *squad_list)
{
    if (isSquadsListEmpty(*squad_list))
    {
        coutf(RED, "No hay escuadrones disponibles.\n");
        system("pause");
        return;
    }

    int squad_number;
    coutf(GREEN, "Indique el número del escuadron a eliminar: ");
    cinv("int", squad_number);

    SquadsPtr current = *squad_list;
    SquadsPtr previous = nullptr;

    while (current != nullptr && current->number != squad_number)
    {
        previous = current;
        current = current->next;
    }

    if (current != nullptr)
    {
        if (previous == nullptr)
        {
            *squad_list = current->next;
        }
        else
        {
            previous->next = current->next;
        }
        delete current;
        coutf(GREEN, "Escuadrón eliminado exitosamente.\n");
    }
    else
    {
        coutf(RED, "Escuadrón no encontrado.\n");
    }
    return;
}

#endif