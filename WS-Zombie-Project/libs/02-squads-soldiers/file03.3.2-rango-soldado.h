#ifndef FILE03_3_2_RANGO_SOLDADO_H
#define FILE03_3_2_RANGO_SOLDADO_H
#include "../sources/outools.h"
#include "../sources/structs.h"

void EditarRangoSoldado(Soldier *current_soldier, SquadsPtr current_squad)
{
    int rango_opcion;
    coutf(GREEN, "Indique el nuevo rango del soldado (1. Capitan | 2. Cadete): ");
    cinv("int", rango_opcion);

    while (rango_opcion < 1 || rango_opcion > 2)
    {
        coutf(RED, "Opción inválida. Inténtalo de nuevo: ");
        cinv("int", rango_opcion);
    }

    if (rango_opcion == 1)
    {
        // Verificar si ya existe un capitán
        Soldier *capitan_actual = nullptr;
        Soldier *temp_soldier = current_squad->soldiers;
        while (temp_soldier != nullptr)
        {
            if (temp_soldier->range == "Capitan")
            {
                capitan_actual = temp_soldier;
                break;
            }
            temp_soldier = temp_soldier->next;
        }

        if (capitan_actual != nullptr && capitan_actual != current_soldier)
        {
            int cambiar_capitan;
            coutf(RED, "Ya existe un Capitan, ¿deseas quitarle el rango al Capitan " + capitan_actual->name + "? (1. Si | 2. No): ");
            cinv("int", cambiar_capitan);

            while (cambiar_capitan < 1 || cambiar_capitan > 2)
            {
                coutf(RED, "Opción inválida. Inténtalo de nuevo: ");
                cinv("int", cambiar_capitan);
            }

            if (cambiar_capitan == 1)
            {
                capitan_actual->range = "Cadete";
                current_soldier->range = "Capitan";
            }
            else
            {
                current_soldier->range = "Cadete";
            }
        }
        else
        {
            current_soldier->range = "Capitan";
        }
    }
    else
    {
        current_soldier->range = "Cadete";
    }
    coutf(GREEN, "Rango actualizado exitosamente.\n");
    return;
}

#endif