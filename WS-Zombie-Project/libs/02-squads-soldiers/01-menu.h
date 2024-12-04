#ifndef FILE00_MENU_H
#define FILE00_MENU_H
#include "../sources/outools.h"
#include "../sources/structs.h"


void Menu_Squads(SquadsPtr *squad_list)
{
    int op = -1;

    while (op)
    {
        CLEAR_SCREEN;
        coutf(BLUE, "\t\tMENU DE GESTIÓN DE ESCUADRONES ANTIZOMBIES\n\n");
        coutf(BLUE, "1. Crear un nuevo escuadron\n");
        coutf(BLUE, "2. Consultar escuadrones\n");
        coutf(BLUE, "3. Editar un escuadron\n");
        coutf(BLUE, "4. Eliminar un escuadron\n\n");
        coutf(BLUE, "0. REGRESAR\n\n");

        cinv("int", op); // Usar cinv para obtener y validar la entrada del usuario

        switch (op)
        {
        case 1:
            CrearEscuadron(squad_list);
            break;
        case 2:
            ConsultarEscuadrones(squad_list);
            break;
        case 3:
            Menu_EditarEscuadron(*squad_list);
            break;
        case 4:
            EliminarEscuadron(squad_list);
            break;
        default:
            break;
        }
    }
}

#endif // FILE00_MENU_H