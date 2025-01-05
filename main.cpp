#include <iostream>
#include "Sources/outools.h"
#include "Sources/struct.h"
#include "Sources/dialogues.h"
#include "F00-Main-Menu/main_menu.h"
#include "F06-Import/F01_import_soldiers.h"
#include "F06-Import/F02_import_items.h"
#include "F06-Import/F03_import_zombies.h"
#include "F06-Import/F04_import_stations.h"
#include "F03-Stations/F03_consult_stations.h"
using namespace std;

int main()
{

    squad *squad_list = nullptr;             // Lista de escuadrones
    soldier *fallen_soldiers_list = nullptr; // Lista de soldados caídos
    bpck *backpack_list = nullptr;           // Lista de mochilas
    Zgroup *zgroups_list = nullptr;          // Lista de grupos de zombies
    zombie *fallen_zombie_list = nullptr;    // Lista de zombies caídos
    station *station_list = nullptr;         // Lista de estaciones
    vector<item *> pre_items;                // Vector de ítems predeterminados
    vector<zombie *> types_zombies;          // Vector de tipos de zombies

    // Lectura de archivos e importación de datos
    showProgressSpinner(3000, "Importando Datos del Sistema");
    import_Items(pre_items);                                      // Importar items predeterminados
    import_Zombies(types_zombies);                                // Importar tipos de zombies
    import_Stations(types_zombies, &station_list, &zgroups_list); // Importar estaciones
    import_Soldiers(&squad_list, pre_items, &backpack_list);      // Importar escuadrones y soldados

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

    main_menu(&squad_list, &backpack_list, &station_list, &fallen_soldiers_list, pre_items, &zgroups_list, &fallen_zombie_list, types_zombies);

    return 0;
}