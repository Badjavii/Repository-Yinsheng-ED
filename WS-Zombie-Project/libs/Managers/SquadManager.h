#ifndef SQUADMANAGER_H
#define SQUADMANAGER_H
#include <iostream>
#include "../outools.h"
#include "../structs.h"
#include <vector>
using namespace std;

void MostrarResumenSoldado(Soldier *soldier)
{
    coutf(BLUE, "--------------------------------------------------------------------------------\n");
    coutf(BLUE, "                   Resumen del Soldado '" + soldier->name + "'\n");
    coutf(BLUE, "--------------------------------------------------------------------------------\n");
    coutf(BLUE, "Nombre             Rango                              Items\n");
    coutf(BLUE, "-----------      --------------     -----------------------------------------\n");
    coutf(BLUE, soldier->name + "                    " + soldier->range + "               " +
                    soldier->equipment->item1->name + ", " +
                    soldier->equipment->item2->name + ", " +
                    soldier->equipment->item3->name + "\n");
    coutf(BLUE, "--------------------------------------------------------------------------------\n");
}

int ContarSoldados(Soldier *soldiers)
{
    int count = 0;
    while (soldiers != nullptr)
    {
        count++;
        soldiers = soldiers->next;
    }
    return count;
}

bool isSquadsListEmpty(SquadsPtr head)
{
    return head == nullptr;
}

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

void ConsultarEscuadrones(SquadsPtr *squad_list)
{
    if (isSquadsListEmpty(*squad_list))
    {
        coutf(RED, "No hay escuadrones disponibles.\n");
        system("pause");
        return;
    }

    SquadsPtr current_squad = *squad_list;

    while (current_squad != nullptr)
    {
        coutf(GREEN, "Escuadrón número: " + to_string(current_squad->number) + "\n");

        Soldier *current_soldier = current_squad->soldiers;
        if (current_soldier == nullptr)
        {
            coutf(YELLOW, "  No hay soldados en este escuadrón.\n");
        }
        else
        {
            while (current_soldier != nullptr)
            {
                coutf(BLUE, "  Soldado: " + current_soldier->name + ", Rango: " + current_soldier->range + ", Items ofensivo: " + current_soldier->equipment->item1->name + "\n");
                current_soldier = current_soldier->next;
            }
        }

        current_squad = current_squad->next;
    }
    system("pause");
}

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
    system("pause");
}

void LiberarEscuadrones(SquadsPtr *squad_list)
{
    while (*squad_list != nullptr)
    {
        SquadsPtr temp_squad = *squad_list;
        *squad_list = (*squad_list)->next;

        // Liberar memoria de los soldados
        Soldier *current_soldier = temp_squad->soldiers;
        while (current_soldier != nullptr)
        {
            Soldier *temp_soldier = current_soldier;
            current_soldier = current_soldier->next;
            delete temp_soldier;
        }

        delete temp_squad;
    }
}

void LiberarZombies(Zombies_GroupsPtr *zombies_groups_list)
{
    while (*zombies_groups_list != nullptr)
    {
        Zombies_GroupsPtr temp_group = *zombies_groups_list;
        *zombies_groups_list = (*zombies_groups_list)->next;

        // Liberar memoria de los zombies
        delete[] temp_group->zombies;

        delete temp_group;
    }
}

void AsignarItems(Soldier_Equipment *equipment)
{
    int opcion;

    // Asignar ítem ofensivo
    coutf(GREEN, "Seleccione un ítem ofensivo:\n");
    for (int i = 0; i < items_ofensivos.size(); ++i)
    {
        coutf(GREEN, to_string(i + 1) + ". " + items_ofensivos[i] + ": " + description_item_ofensivo[i] + "\n");
    }
    cinv("int", opcion);
    while (opcion < 1 || opcion > items_ofensivos.size())
    {
        coutf(RED, "Opción inválida. Inténtalo de nuevo: ");
        cinv("int", opcion);
    }
    equipment->item1 = new items; // Inicializar item1
    equipment->item1->name = items_ofensivos[opcion - 1];
    equipment->item1->description = description_item_ofensivo[opcion - 1];
    equipment->item1->uses = uses_item_ofensivo[opcion - 1];
    equipment->item1->xp = xp_item_ofensivo[opcion - 1];
    equipment->item1->type_item = "Ofensivo";

    // Asignar ítem defensivo
    coutf(GREEN, "Seleccione un ítem defensivo:\n");
    for (int i = 0; i < items_defensivos.size(); ++i)
    {
        coutf(GREEN, to_string(i + 1) + ". " + items_defensivos[i] + ": " + description_item_defensivo[i]  + "\n");
    }
    cinv("int", opcion);
    while (opcion < 1 || opcion > items_defensivos.size())
    {
        coutf(RED, "Opción inválida. Inténtalo de nuevo: ");
        cinv("int", opcion);
    }
    equipment->item2 = new items; // Inicializar item2
    equipment->item2->name = items_defensivos[opcion - 1];
    equipment->item2->description = description_item_defensivo[opcion - 1];
    equipment->item2->uses = uses_item_defensivos[opcion - 1];
    equipment->item2->xp = xp_item_defensivo[opcion - 1];
    equipment->item2->type_item = "Defensivo";

    // Asignar ítem de curación
    coutf(GREEN, "Seleccione un ítem de curación:\n");
    for (int i = 0; i < items_curacion.size(); ++i)
    {
        coutf(GREEN, to_string(i + 1) + ". " + items_curacion[i] + ": " + description_item_curacion[i]  + "\n");
    }
    cinv("int", opcion);
    while (opcion < 1 || opcion > items_curacion.size())
    {
        coutf(RED, "Opción inválida. Inténtalo de nuevo: ");
        cinv("int", opcion);
    }
    equipment->item3 = new items; // Inicializar item3
    equipment->item3->name = items_curacion[opcion - 1];
    equipment->item3->description = description_item_curacion[opcion - 1];
    equipment->item3->uses = uses_item_curacion[opcion - 1];
    equipment->item3->xp = xp_item_curacion[opcion - 1];
    equipment->item3->type_item = "Curación";
}

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
    AsignarItems(new_soldier->equipment);

    new_soldier->next = current_squad->soldiers;
    current_squad->soldiers = new_soldier;

    coutf(GREEN, "Soldado agregado exitosamente.\n");
    system("pause");
}

void EliminarSoldado(SquadsPtr current_squad)
{
    string soldier_name;
    coutf(GREEN, "Indique el nombre del soldado a eliminar: ");
    cinv("string", soldier_name);

    Soldier *current_soldier = current_squad->soldiers;
    Soldier *previous_soldier = nullptr;

    while (current_soldier != nullptr && current_soldier->name != soldier_name)
    {
        previous_soldier = current_soldier;
        current_soldier = current_soldier->next;
    }

    if (current_soldier != nullptr)
    {
        if (previous_soldier == nullptr)
        {
            current_squad->soldiers = current_soldier->next;
        }
        else
        {
            previous_soldier->next = current_soldier->next;
        }
        delete current_soldier;
        coutf(GREEN, "Soldado eliminado exitosamente.\n");
    }
    else
    {
        coutf(RED, "Soldado no encontrado.\n");
    }
    system("pause");
}

void EditarNombreSoldado(Soldier *current_soldier)
{
    coutf(GREEN, "Indique el nuevo nombre del soldado: ");
    cinv("string", current_soldier->name);
    coutf(GREEN, "Nombre actualizado exitosamente.\n");
    system("pause");
}

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
    system("pause");
}

void EditarEquipoSoldado(Soldier *current_soldier)
{
    int item_opcion;
    coutf(GREEN, "Seleccione el ítem a editar (1. Ofensivo | 2. Defensivo | 3. Curación): ");
    cinv("int", item_opcion);

    while (item_opcion < 1 || item_opcion > 3)
    {
        coutf(RED, "Opción inválida. Inténtalo de nuevo: ");
        cinv("int", item_opcion);
    }

    switch (item_opcion)
    {
    case 1:
        coutf(GREEN, "Seleccione un nuevo ítem ofensivo:\n");
        for (int i = 0; i < items_ofensivos.size(); ++i)
        {
            coutf(GREEN, to_string(i + 1) + ". " + items_ofensivos[i] + ": " + description_item_ofensivo[i] + "\n");
        }
        cinv("int", item_opcion);
        while (item_opcion < 1 || item_opcion > items_ofensivos.size())
        {
            coutf(RED, "Opción inválida. Inténtalo de nuevo: ");
            cinv("int", item_opcion);
        }
        current_soldier->equipment->item1->name = items_ofensivos[item_opcion - 1];
        current_soldier->equipment->item1->description = description_item_ofensivo[item_opcion - 1];
        current_soldier->equipment->item1->uses = uses_item_ofensivo[item_opcion - 1];
        current_soldier->equipment->item1->xp = xp_item_ofensivo[item_opcion - 1];
        current_soldier->equipment->item1->type_item = "Ofensivo";
        break;
    case 2:
        coutf(GREEN, "Seleccione un nuevo ítem defensivo:\n");
        for (int i = 0; i < items_defensivos.size(); ++i)
        {
            coutf(GREEN, to_string(i + 1) + ". " + items_defensivos[i] + ": " + description_item_defensivo[i]  + "\n");
        }
        cinv("int", item_opcion);
        while (item_opcion < 1 || item_opcion > items_defensivos.size())
        {
            coutf(RED, "Opción inválida. Inténtalo de nuevo: ");
            cinv("int", item_opcion);
        }
        current_soldier->equipment->item2->name = items_defensivos[item_opcion - 1];
        current_soldier->equipment->item2->description = description_item_defensivo[item_opcion - 1];
        current_soldier->equipment->item2->uses = uses_item_defensivos[item_opcion - 1];
        current_soldier->equipment->item2->xp = xp_item_defensivo[item_opcion - 1];
        current_soldier->equipment->item2->type_item = "Defensivo";
        break;
    case 3:
        coutf(GREEN, "Seleccione un nuevo ítem de curación:\n");
        for (int i = 0; i < items_curacion.size(); ++i)
        {
            coutf(GREEN, to_string(i + 1) + ". " + items_curacion[i] + ": " + description_item_curacion[i]  + "\n");
        }
        cinv("int", item_opcion);
        while (item_opcion < 1 || item_opcion > items_curacion.size())
        {
            coutf(RED, "Opción inválida. Inténtalo de nuevo: ");
            cinv("int", item_opcion);
        }
        current_soldier->equipment->item3->name = items_curacion[item_opcion - 1];
        current_soldier->equipment->item3->description = description_item_curacion[item_opcion - 1];
        current_soldier->equipment->item3->uses = uses_item_curacion[item_opcion - 1];
        current_soldier->equipment->item3->xp = xp_item_curacion[item_opcion - 1];
        current_soldier->equipment->item3->type_item = "Curación";
        break;
    }
    coutf(GREEN, "Equipo actualizado exitosamente.\n");
    system("pause");
}

void MostrarResumenEscuadron(SquadsPtr current_squad)
{
    coutf(RESET, "-------------------------------------------------------------------------\n");
    coutf(GREEN, "                          Resumén de Escuadrón\n");
    coutf(RESET, "-------------------------------------------------------------------------\n");
    coutf(RESET, "Rango          Nombre                   Items\n");
    coutf(RESET, "--------    ----------------       --------------------------------------\n");

    Soldier *current_soldier = current_squad->soldiers;
    while (current_soldier != nullptr)
    {
        coutf(RESET, current_soldier->range + "    ");
        coutf(RESET, current_soldier->name + "        ");
        coutf(RESET, current_soldier->equipment->item1->name + ", ");
        coutf(RESET, current_soldier->equipment->item2->name + ", ");
        coutf(RESET, current_soldier->equipment->item3->name + "\n");
        current_soldier = current_soldier->next;
    }

    coutf(RESET, "-------------------------------------------------------------------------\n");
}

void MostrarTotalEscuadrones(SquadsPtr squad_list)
{
    coutf(BLUE, "---------------------------------------\n");
    coutf(BLUE, " Resumén de todos los escuadrones\n");
    coutf(BLUE, "---------------------------------------\n");
    coutf(GREEN, "Numero      Cantidad de Soldados\n");
    coutf(BLUE, "--------   ---------------------------\n");

    SquadsPtr current_squad = squad_list;
    while (current_squad != nullptr)
    {
        int num_soldados = ContarSoldados(current_squad->soldiers);
        coutf(BLUE, to_string(current_squad->number) + "      " + to_string(num_soldados) + "/10\n");
        current_squad = current_squad->next;
    }

    coutf(BLUE, "---------------------------------------\n");
}

#endif // SQUADMANAGER_H
