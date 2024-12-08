#ifndef FILE03_3_EDITAR_SOLDADO_H
#define FILE03_3_EDITAR_SOLDADO_H
#include "../sources/outools.h"
#include "../sources/structs.h"
#include "file03.3.1-nombre-soldado.h"
#include "file03.3.2-rango-soldado.h"
#include "file03.3.3-equipo-soldado.h"
#include "file11-sources.h"

void EditarSoldado(SquadsPtr current_squad)
{
    string soldier_name;
    coutf(GREEN, "Indique el nombre del soldado a editar: ");
    cinv("string", soldier_name);

    Soldier *current_soldier = current_squad->soldiers;
    while (current_soldier != nullptr && current_soldier->name != soldier_name)
    {
        current_soldier = current_soldier->next;
    }

    if (current_soldier != nullptr)
    {
        int op = -1;
        while (op)
        {
            CLEAR_SCREEN;

            // Mostrar resumen del soldado
            MostrarResumenSoldado(current_soldier);

            coutf(BLUE, "\t\tMENU DE EDICIÓN DEL SOLDADO " + current_soldier->name + "\n\n");
            coutf(BLUE, "1. Editar nombre\n");
            coutf(BLUE, "2. Editar rango\n");
            coutf(BLUE, "3. Editar equipo\n\n");
            coutf(BLUE, "0. REGRESAR\n\n");

            cinv("int", op); // Usar cinv para obtener y validar la entrada del usuario

            switch (op)
            {
            case 1:
                EditarNombreSoldado(current_soldier);
                break;
            case 2:
                EditarRangoSoldado(current_soldier, current_squad);
                break;
            case 3:
                EditarEquipoSoldado(current_soldier);
                break;
            case 0:
                return;
            default:
                coutf(RED, "Opción inválida. Inténtalo de nuevo.\n");
                PAUSE_TERMINAL;
                break;
            }
        }
    }
    else
    {
        coutf(RED, "Soldado no encontrado.\n");
        PAUSE_TERMINAL;
    }
}

#endif