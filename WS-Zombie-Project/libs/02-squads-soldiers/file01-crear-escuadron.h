#ifndef FILE01_CREAR_ESCUADRON_H
#define FILE01_CREAR_ESCUADRON_H
#include "../sources/outools.h"
#include "../sources/structs.h"
#include "file11-sources.h"

void CrearEscuadron(SquadsPtr *squad_list)
{
    int squad_number;
    coutf(GREEN, "Indique el número del escuadron: ");
    cinv("int", squad_number);

    // Verificar si el número del escuadrón ya existe
    SquadsPtr current = *squad_list;
    while (current != nullptr)
    {
        if (current->number == squad_number)
        {
            coutf(RED, "El número del escuadrón ya existe. Intente con otro número.\n");
            system("pause");
            return;
        }
        current = current->next;
    }

    // Crear el nuevo escuadrón
    SquadsPtr new_squad = new Squads;
    new_squad->number = squad_number;
    new_squad->next = *squad_list;
    new_squad->soldiers = nullptr;
    *squad_list = new_squad;

    coutf(GREEN, "Escuadrón creado exitosamente.\n");
    system("pause");
}

#endif