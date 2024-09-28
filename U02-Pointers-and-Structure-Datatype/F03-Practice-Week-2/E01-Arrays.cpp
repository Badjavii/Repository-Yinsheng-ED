#include <iostream>
#include "libs/suma.h"
#include <string>
using namespace std;

int main()
{

    cout << "Se inicia un mini algoritmo para ver como se imprimen los elementos de un arreglo en C++ \n\n";

    int edades[] = {1, 2, 9, 8, 16, 32, 9, 50, 26, 28, 1, 87}; // Declarar e inicializar un array de
    int limite = {sizeof(edades) / sizeof(edades[0])};
    for (int i = 0; i < limite; i++)
        cout << edades[i] << ", ";

    system("pause");
    system("cls");
    return 0;
}