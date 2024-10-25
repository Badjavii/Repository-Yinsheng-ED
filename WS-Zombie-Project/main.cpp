#include <iostream>
#include "libs/dialogues.h"
#include "libs/outools.h"
#include "libs/structs.h"
#include "libs/menus.h"
using namespace std;

int main()
{
    // Introdución al lore del juego
    coutf(YELLOW, "¿Deseas omitir la intro? (1. Si | 2. No)\n");
    int op = -1;
    cinv("int", op);
    while (op != 1 && op != 2)  // Validar ¿1 o 2?
    {
        coutf(RED, "Opción inválida. Inténtalo de nuevo: ");
        cinv("int", op);
    }
    if (op == 2)
        coutStory();            // Imprimir el lore
    
    system("pause");
    system("cls");

    // Imprimir Logo ASCII del juego
    printAsciiArt();
    system("pause");
    system("cls");

    // Inicio Gestion del Programa
    Principal_Menu();

    return 0;
}