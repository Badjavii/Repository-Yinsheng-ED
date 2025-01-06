#ifndef F04_BINNACLE_H
#define F04_BINNACLE_H
#include "../Sources/outools.h"
#include "../Sources/struct.h"
#include "../F01-Soldiers/FZZ_extra.h"
#include "../F02-Zombies/FSS_extra.h"
#include "../F01-Soldiers/F07_showLiving_soldiers.h"
#include "../F01-Soldiers/F06_showFallen_soldiers.h"
#include "../F02-Zombies/F06_showLiving_zombies.h"
#include "../F02-Zombies/F05_showFallen_zombies.h"

void Menu_Binnacle(Zgroup **zgroup_list, squad **squad_list, soldier **fallen_soldier_list, zombie **fallen_zombies_list)
{
    int op = -1, x, y, z;
    string chain;

    while (op)
    {
        CLEAR_SCREEN; // Limpiar la pantalla
        coutf(BLUE, "\t\tBITACORA DE CONSULTA\n\n");
        coutf(BLUE, "1. Mostrar todos los soldados vivos por cada escuadron\n");
        coutf(BLUE, "2. Mostrar todos los soldados caidos (muertos)\n");
        coutf(BLUE, "3. Mostrar todos los zombies vivos por cada grupos\n");
        coutf(BLUE, "4. Mostrar todos los zombies caidos (muertos)\n\n");
        coutf(BLUE, "0. REGRESAR\n\n");

        cinv("int", op);

        switch (op)
        {
        case 1:
            showLiving_soldiers(*squad_list);
            break;
        case 2:
            showFallen_soldiers(*fallen_soldier_list);
            break;
        case 3:
            showLiving_Zombies(*zgroup_list);
            break;
        case 4:
            showFallen_zombies(*fallen_zombies_list);
            break;
        case 0:
            return;
        default:
            break;
        }
        cout << "\n\n";
        PAUSE_TERMINAL; // Pausar la terminal para que el usuario pueda ver el resultado antes de continuar
    }
}

#endif // F04_BINNACLE_H