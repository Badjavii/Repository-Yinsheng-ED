#include <iostream>
#include "libs/dialogues.h"
#include "libs/outools.h"
#include "libs/menus.h"
using namespace std;

int main()
{

    coutf(YELLOW, "¿Deseas omitir la intro? (1. Si | 2. No)\n");
    int op = -1;
    cinv("int", op);
    while (op != 1 && op != 2)
    {
        coutf(RED, "Opción inválida. Inténtalo de nuevo: ");
        cinv("int", op);
    }
    if (op == 2)
        coutStory();
    system("pause");
    system("cls");

    Principal_Menu();

    return 0;
}