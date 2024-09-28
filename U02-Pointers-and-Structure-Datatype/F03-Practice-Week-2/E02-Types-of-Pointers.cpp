#include "iostream"
#include <stdlib.h>

using namespace std;

int main()
{

    typedef int *tIntPtr;       // Definir el tipo de puntero (puntero a un entero)
    typedef char *tCharPtr;     // Definir el tipo de puntero (puntero a un character)
    typedef double *tDoublePtr; // Definir el tipo de puntero (puntero a un real)

    int entero = 5;             // Declarar e inicializar una variable de tipo entero
    tIntPtr puntI = &entero;    // Declarar un puntero de tipo "a entero" y asignarle el DMA de 'entero'
    char caracter = 'C';        // Declarar e inicializar una variable de tipo caracter
    tCharPtr puntC = &caracter; // Declarar un puntero de tipo "a caracter" y asignarle el DMA de 'caracter'
    double real = 5.23;         // Declarar e inicializar una variable de tipo real
    tDoublePtr puntD = &real;   // Declarar un puntero de tipo "a real" y asignarle el DMA de 'real'

    cout << *puntI << "  " << *puntC << "  " << *puntD << endl;
    cout << "La direccion de memoria que contiene puntI: " << puntI << endl;
    cout << "La direccion de memoria que contiene puntD: " << puntD << endl;
    cout << "La direccion de memoria que contiene puntC: " << puntC << endl;
    cout << "\n";
    cout << "La direccion de memoria de puntI: " << &puntI << endl;
    cout << "La direccion de memoria de puntD: " << &puntD << endl;
    cout << "La direccion de memoria de puntC: " << &puntC << endl;

    system("pause");
    return 0;
}