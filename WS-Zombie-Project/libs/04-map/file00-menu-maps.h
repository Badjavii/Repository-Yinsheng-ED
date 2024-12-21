#ifndef FILE00_MENU_MAPS_H
#define FILE00_MENU_MAPS_H
#include "../sources/structs.h"
#include "../sources/outools.h"
#include "file01-crear-estacion.h"
#include "file02-editar-estacion.h"
#include "file03-eliminar-estacion.h"
#include "file05-sources.h"

void Menu_Mapa(MapaPtr *mapa, SquadsPtr *squad_list, Zombies_GroupsPtr *zombies_groups_list)
{
    int op = -1;

    while (op)
    {
        CLEAR_SCREEN;
        coutf(BLUE, "\t\tMENU DE GESTIÓN DE MAPA Y ESTACIONES\n\n");
        coutf(BLUE, "1. Crear una nueva estación\n");
        coutf(BLUE, "2. Consultar estaciones\n");
        coutf(BLUE, "3. Editar una estación\n");
        coutf(BLUE, "4. Eliminar una estación\n\n");
        coutf(BLUE, "0. REGRESAR\n\n");

        cinv("int", op); // Usar cinv para obtener y validar la entrada del usuario

        switch (op)
        {
        case 1:
            CrearEstacion(mapa);
            break;
        case 2:
            ConsultarEstaciones(mapa);
            break;
        case 3:
            Menu_EditarEstacion(mapa, squad_list, zombies_groups_list);
            break;
        case 4:
            EliminarEstacion(mapa);
            break;
        default:
            break;
        }
        PAUSE_TERMINAL;
    }
}

#endif // FILE00_MENU_MAPS_H