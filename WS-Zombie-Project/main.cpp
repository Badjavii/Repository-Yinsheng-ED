#include <iostream>
#include "libs/sources/dialogues.h"
#include "libs/sources/outools.h"
#include "libs/sources/structs.h"
#include "libs/menus.h"
#include "libs/00-import-export/file00-import-export.h"
using namespace std;

int main()
{
    // Introdución al lore del juego
    coutf(YELLOW, "¿Deseas omitir la intro? (1. Si | 2. No)\n");
    int op = -1;
    cinv("int", op);
    while (op != 1 && op != 2) // Validar ¿1 o 2?
    {
        coutf(RED, "Opción inválida. Inténtalo de nuevo: ");
        cinv("int", op);
    }
    if (op == 2)
        coutStory(); // Imprimir el lore

    PAUSE_TERMINAL;
    CLEAR_SCREEN;

    // Imprimir Logo ASCII del juego
    printAsciiArt();
    PAUSE_TERMINAL;
    CLEAR_SCREEN;

    // Inicializacion de estructuras dinamicas
    SquadsPtr squad_list = nullptr;
    Zombies_GroupsPtr zombies_groups_list = nullptr;
    MapaPtr mapa = new Mapa;

    // Importar datos desde archivos txt (COMING SOON)
    showProgressSpinner(3000, "Importando Datos del Sistema");
    importar(&squad_list, &mapa->estaciones,&zombies_groups_list);
    PAUSE_TERMINAL;
    CLEAR_SCREEN;

    // Inicio Gestion del Programa
    Principal_Menu(&squad_list, &zombies_groups_list, &mapa);

    // Batalla de los zombies (COMING SOON)
    // ......................
    // ......................

    // Fin del Programa: exportar y liberar datos
    // export_data(squad_list, zombies_groups_list, mapa);      // Exportar datos hacia el archivo txt (COMING SOON)
    LiberarEscuadrones(&squad_list);      // Liberar los escuadrones
    LiberarZombies(&zombies_groups_list); // Liberar los grupos zombies
    LiberarMapa(&mapa);                   // Liberar el mapa
    showProgressSpinner(3000, "Exportando Datos del Sistema");
    showProgressSpinner(3000, "Liberando Memoria");
    showProgressSpinner(1000, "Saliendo del Programa");

    return 0;
}