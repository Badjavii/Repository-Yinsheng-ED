#ifndef OUTOOLS_H
#define OUTOOLS_H

#include <string>
#include <iostream>
#include <Windows.h>
#include <cstdio>
#include <thread> // Incluye la libreria para el manejo de hilos
#include <chrono> // Incluye la libreria para el manejo del tiempo
#include <sstream> // Incluye la librería para el manejo de string streams
using namespace std;

// Definir colores
#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

// #### Función que imprime texto con carácteres especiales (como á, é, ú, etc) ####
void coutf(const string &color, const string &text)
{
    SetConsoleOutputCP(CP_UTF8);    // Configurar la consola para usar UTF-8
    cout << color << text << RESET; // Imprime el texto en el color especificado y resetea el color
}

// #### Función que imprime texto con efecto de máquina de escribir ####
// Esta función utiliza el manejo de hilos para pausar la ejecución entre la impresión de cada carácter.
// El manejo de hilos permite ejecutar múltiples secuencias de instrucciones de manera concurrente,
// mejorando la eficiencia y capacidad de respuesta de las aplicaciones.

void couttw(const string &color, const string &text, unsigned int CoutDelay)
{
    SetConsoleOutputCP(CP_UTF8); // Configurar la consola para usar UTF-8

    cout << color;
    for (char c : text) // Recorrer cada carácter del texto
    {
        cout << c << flush; // Imprime el carácter y fuerza la salida inmediata del búfer

        // Pausar la ejecucion por el tiempo especificado en CoutDelay
        this_thread::sleep_for(chrono::milliseconds(CoutDelay));
    }
    cout << RESET << endl;
};

// Función de validación genérica
// Esta función intenta convertir la entrada de tipo string a un tipo T
// Si la conversión es exitosa y no hay caracteres adicionales en la entrada, retorna true
template <typename T>
bool isValid(const string &input, T &variable) {
    istringstream iss(input);
    return (iss >> variable) && (iss.eof());
}

// Especialización de la función de validación para strings
// Para strings, simplemente verificamos que la entrada no esté vacía
template <>
bool isValid<string>(const string &input, string &variable) {
    variable = input;
    return !input.empty();
}

// Función cinv genérica que utiliza plantillas
// Esta función pide al usuario una entrada y la valida según el tipo de dato especificado
template <typename T>
void cinv(const string &datatype, T &variable) {
    string input;
    coutf(YELLOW, "» "); // Imprime el prompt en amarillo
    while (true) {
        getline(cin, input); // Lee la entrada del usuario
        if (isValid(input, variable)) { // Valida la entrada
            break; // Si la entrada es válida, sale del bucle
        } else {
            coutf(RED, "Entrada inválida. Inténtalo de nuevo: "); // Si la entrada no es válida, muestra un mensaje de error
        }
    }
}

#endif // OUTOOLS_H

/* NOTA:

En C++, el flujo de salida estándar (cout) utiliza un búfer para almacenar
temporalmente los datos antes de imprimirlos en la pantalla. Esto significa
que, por eficiencia, cout no siempre imprime inmediatamente cada carácter
que recibe; en su lugar, espera hasta que el búfer esté lleno o hasta que
se encuentre un carácter de nueva línea (\n).

El manipulador (flush) se utiliza para forzar la salida inmediata del contenido
del búfer. Esto asegura que cada carácter se imprima en la pantalla tan
pronto como se envía a cout, sin esperar a que el búfer se llene o a que
se encuentre un carácter de nueva línea.*/