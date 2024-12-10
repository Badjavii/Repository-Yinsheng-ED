#ifndef FILE00_MENU_H
#define FILE00_MENU_H
#include "../sources/outools.h"
#include "../sources/structs.h"
#include "file01-crear-escuadron.h"
#include "file02-consultar-escuadrones.h"
#include "file03-editar-escuadrones.h"
#include "file04-eliminar-escuadron.h"


void Menu_Squads(Squads **lista_escuadrones)
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
            CrearEscuadron(lista_escuadrones);
            break;
        case 2:
            ConsultarEscuadrones(lista_escuadrones);
            break;
        case 3:
            Menu_EditarEscuadron(*lista_escuadrones);
            break;
        case 4:
            EliminarEscuadron(lista_escuadrones);
            break;
        case 0:
            return;
        default:
            break;
        }
        PAUSE_TERMINAL;
    }
}

#endif // FILE00_MENU_H