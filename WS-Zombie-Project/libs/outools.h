#ifndef TYPEWRITEREFFECT_H
#define TYPEWRITEREFFECT_H

#include <string>
#include <iostream>
#include <Windows.h>
#include <cstdio>
#include <thread> // Incluye la libreria para el manejo de hilos
#include <chrono> // Incluye la libreria para el manejo del tiempo
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
}

#endif // TYPEWRITEREFFECT_H

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