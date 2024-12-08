#ifndef FILE11_SOURCES_H
#define FILE11_SOURCES_H
#include "../sources/outools.h"
#include "../sources/structs.h"

bool isSquadsListEmpty(Squads* head)
{
    return head == nullptr;
};

void MostrarResumenEscuadron(SquadsPtr current_squad)
{
    coutf(RESET, "----------------------------------------------------------------------------------\n");
    coutf(GREEN, "                          Resumén de Escuadrón\n");
    coutf(RESET, "----------------------------------------------------------------------------------\n");
    coutf(RESET, "Rango          Nombre            XP                Items\n");
    coutf(RESET, "--------    ----------------  ---------     --------------------------------------\n");

    Soldier *current_soldier = current_squad->soldiers;
    while (current_soldier != nullptr)
    {
        coutf(RESET, current_soldier->range + "        ");
        coutf(RESET, current_soldier->name + "        ");
        coutf(RESET, to_string(current_soldier->XP) + "        ");
        coutf(RESET, current_soldier->equipment->item1->name + ", ");
        coutf(RESET, current_soldier->equipment->item2->name + ", ");
        coutf(RESET, current_soldier->equipment->item3->name + "\n");
        current_soldier = current_soldier->next;
    }

    coutf(RESET, "----------------------------------------------------------------------------------\n");
    return;
};

int ContarSoldados(Soldier *soldiers)
{
    int count = 0;
    while (soldiers != nullptr)
    {
        count++;
        soldiers = soldiers->next;
    }
    return count;
};

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
    return;
};

void MostrarResumenSoldado(Soldier *soldier)
{
    coutf(BLUE, "-------------------------------------------------------------------------------------------------------------------------\n");
    coutf(GREEN, "                             Resumen del Soldado '" + soldier->name + "'\n");
    coutf(BLUE, "-------------------------------------------------------------------------------------------------------------------------\n");
    coutf(GREEN, "Nombre             Rango                              Items\n");
    coutf(BLUE, "-----------      --------------     -------------------------------------------------------------------------------------\n");
    coutf(BLUE, soldier->name + "               " + soldier->range + "               " +
                    soldier->equipment->item1->name + " (" + to_string(soldier->equipment->item1->xp) + " xp y " + to_string(soldier->equipment->item1->uses)+ " usos), " +
                    soldier->equipment->item2->name + " (" + to_string(soldier->equipment->item2->xp) + " xp y " + to_string(soldier->equipment->item2->uses)+ " usos), " +
                    soldier->equipment->item3->name + " (" + to_string(soldier->equipment->item3->xp) + " xp y " + to_string(soldier->equipment->item3->uses)+ " usos) \n");
    coutf(BLUE, "-------------------------------------------------------------------------------------------------------------------------\n\n");
    return;
};

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
                int xp = current_soldier->equipment->item1->xp + current_soldier->equipment->item2->xp + current_soldier->equipment->item3->xp;
                coutf(BLUE, "  Soldado: " + current_soldier->name + ", Rango: " + current_soldier->range + ", Items ofensivo: " + current_soldier->equipment->item1->name + ", XP Total: " + to_string(current_soldier->XP)  + "\n");
                current_soldier = current_soldier->next;
            }
        }

        current_squad = current_squad->next;
    }
    return;
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
    return;
}

#endif