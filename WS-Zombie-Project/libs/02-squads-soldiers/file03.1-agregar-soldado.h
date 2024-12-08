#ifndef FILE03_1_AGREGAR_SOLDADO_H
#define FILE03_1_AGREGAR_SOLDADO_H
#include "../sources/outools.h"
#include "../sources/structs.h"

void AgregarSoldado(SquadsPtr current_squad)
{
    // Contar el número de soldados en el escuadrón
    int num_soldados = 0;
    Soldier *current_soldier = current_squad->soldiers;
    while (current_soldier != nullptr)
    {
        num_soldados++;
        current_soldier = current_soldier->next;
    }

    if (num_soldados >= 10)
    {
        coutf(RED, "El escuadrón ya tiene el máximo de 10 soldados.\n");
        system("pause");
        return;
    }

    Soldier *new_soldier = new Soldier;
    coutf(GREEN, "Indique el nombre del soldado: ");
    cinv("string", new_soldier->name);
    new_soldier->health = 100;

    int rango_opcion;
    coutf(GREEN, "Indique el rango del soldado (1. Capitan | 2. Cadete): ");
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
        current_soldier = current_squad->soldiers;
        while (current_soldier != nullptr)
        {
            if (current_soldier->range == "Capitan")
            {
                capitan_actual = current_soldier;
                break;
            }
            current_soldier = current_soldier->next;
        }

        if (capitan_actual != nullptr)
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
                new_soldier->range = "Capitan";
            }
            else
            {
                new_soldier->range = "Cadete";
            }
        }
        else
        {
            new_soldier->range = "Capitan";
        }
    }
    else
    {
        new_soldier->range = "Cadete";
    }

    // Asignar equipo al soldado
    new_soldier->equipment = new Soldier_Equipment;
    // AsignarItems(new_soldier->equipment);
    
    new_soldier->XP = (new_soldier->equipment->item1->xp + new_soldier->equipment->item2->xp + new_soldier->equipment->item3->xp);

    new_soldier->next = current_squad->soldiers;
    current_squad->soldiers = new_soldier;

    coutf(GREEN, "Soldado agregado exitosamente.\n");
    system("pause");
};

#endif // FILE01.1_AGREGAR_SOLDADO_H