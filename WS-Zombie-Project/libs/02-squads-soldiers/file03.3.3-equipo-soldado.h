#ifndef FILE03_3_3_EQUIPO_SOLDADO_H
#define FILE03_3_3_EQUIPO_SOLDADO_H
#include "../sources/outools.h"
#include "../sources/structs.h"


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
    current_soldier->XP = (current_soldier->equipment->item1->xp + current_soldier->equipment->item2->xp + current_soldier->equipment->item3->xp);
    coutf(GREEN, "Equipo actualizado exitosamente.\n");
    return;
}

#endif