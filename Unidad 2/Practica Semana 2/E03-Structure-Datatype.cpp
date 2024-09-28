#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct
{
    int codigo;
    string nombre;
    double sueldo;
} tRegistro;

int main()
{
    tRegistro registro;
    typedef tRegistro *tRegistroPtr;
    tRegistroPtr puntero = &registro;
    registro.codigo = 12345;
    registro.nombre = "Javier";
    registro.sueldo = 95000;

    cout << "Codigo: " << puntero->codigo << "\nNombre: " << puntero->nombre << " \nSueldo: " << puntero->sueldo << endl;
    return 0;
}