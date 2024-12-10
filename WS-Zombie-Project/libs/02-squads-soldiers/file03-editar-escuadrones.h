#ifndef FILE01_EDITAR_H
#define FILE01_EDITAR_H
#include "../sources/outools.h"
#include "../sources/structs.h"
#include "file03.1-agregar-soldado.h"
#include "file03.2-eliminar-soldado.h"
#include "file03.3-editar-soldado.h"
#include "file11-sources.h"

void Menu_EditarEscuadron(Squads* lista_escuadrones)
{
    if (isSquadsListEmpty(lista_escuadrones) == true)
    {
        coutf(RED, "La lista de escuadrones está vacía.\n");
        return;
    }

    // Mostrar resumen de todos los escuadrones
    MostrarTotalEscuadrones(lista_escuadrones);

    int num_escuadron;
    coutf(GREEN, "Indique el número del escuadron que desea editar: ");
    cinv("int", num_escuadron);

    SquadsPtr actual_escuadron = lista_escuadrones;
    while (actual_escuadron != nullptr && actual_escuadron->number != num_escuadron)
    {
        actual_escuadron = actual_escuadron->next;
    }

    if (actual_escuadron == nullptr)
    {
        coutf(RED, "Escuadrón no encontrado.\n");
        PAUSE_TERMINAL;
        return;
    }

    int op = -1;
    while (op)
    {
        CLEAR_SCREEN;
        coutf(BLUE, "\t\tMENU DE EDICIÓN DE ESCUADRON #" + to_string(num_escuadron) + "\n\n");
        coutf(BLUE, "1. Agregar soldado\n");
        coutf(BLUE, "2. Eliminar soldado\n");
        coutf(BLUE, "3. Editar soldado\n\n");
        coutf(BLUE, "0. REGRESAR\n\n");

        // Mostrar resumen del escuadrón
        MostrarResumenEscuadron(actual_escuadron);

        cinv("int", op); // Usar cinv para obtener y validar la entrada del usuario

        switch (op)
        {
        case 1:
            AgregarSoldado(actual_escuadron);
            break;
        case 2:
            EliminarSoldado(actual_escuadron);
            break;
        case 3:
            EditarSoldado(actual_escuadron);
            break;
        case 0:
            return;
        default:
            coutf(RED, "Opción inválida. Inténtalo de nuevo.\n");
            break;
        }
        PAUSE_TERMINAL;
    }
    return;
}

#endif // FILE01_EDITAR_H