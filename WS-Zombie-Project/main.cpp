#include <iostream>
#include "libs/dialogues.h"
#include "libs/outools.h"
#include "libs/structs.h"
#include "libs/menus.h"
// #include "libs/DocManager.h"          // Libreria para el manejo de archivos de texto (COMING SOON)
// #include "libs/Datos/maps.txt"        // Archivo de texto
// #include "libs/Datos/squads.txt"      // Archivo de texto
// #include "libs/Datos/zombies.txt"     // Archivo de texto
using namespace std;

int main()
{
    // Introdución al lore del juego
    coutf(YELLOW, "HOLA¿Deseas omitir la intro? (1. Si | 2. No)\n");
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

    // Importar datos desde el archivo txt (COMING SOON)
    // importarDatos(&squad_list, &zombies_groups_list, &mapa, "squads.txt", "zombies.txt", "maps.txt");

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
    showProgressSpinner(3000, "Exportandos Datos del Sistema");
    showProgressSpinner(3000, "Liberando Memoria");
    showProgressSpinner(1000, "Saliendo del Programa");

    return 0;
}