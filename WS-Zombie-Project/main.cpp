#include <iostream>
#include "libs/sources/dialogues.h"
#include "libs/sources/outools.h"
#include "libs/sources/structs.h"
#include "libs/01-main-menu/menu.h"
#include "libs/00-import-export/file00-import-export.h"
#include "libs/05-liberar/file00-liberar.h"
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
    Squads* lista_escuadrones = nullptr;
    Zombies_Groups* lista_grupos_zombies = nullptr;
    Mapa* grafo_mapa = new Mapa;

    // Importar datos desde archivos txt (COMING SOON)
    showProgressSpinner(3000, "Importando Datos del Sistema");
    importar(&lista_escuadrones, &grafo_mapa->estaciones,&lista_grupos_zombies);
    PAUSE_TERMINAL;
    CLEAR_SCREEN;

    // Inicio Gestion del Programa
    Principal_Menu(&lista_escuadrones, &lista_grupos_zombies, &grafo_mapa);

    // Batalla de los zombies (COMING SOON)
    // ......................
    // ......................

    // Fin del Programa: liberar datos
    LiberarEscuadrones(&lista_escuadrones);      // Liberar los escuadrones
    LiberarZombies(&lista_grupos_zombies); // Liberar los grupos zombies
    LiberarMapa(&grafo_mapa);                   // Liberar el mapa
    showProgressSpinner(2000, "Exportando Datos del Sistema");
    showProgressSpinner(2000, "Liberando Memoria");
    showProgressSpinner(1000, "Saliendo del Programa");

    return 0;
}