/***********************************/
/*              sopa5.cpp          */
/* --------------------------------*/
/* ----------PROPOSITO-------------*/
/* RESOLVER UNA SOPA DE LETRAS     */
/* --------------------------------*/
/*YISHENG LIANG ESPINOZA 06/04/2024*/
/* Emision inicial                 */
/***********************************/
#include <iostream>
#include <vector>
#include <string>
#include "sopa5.h"

using namespace std;

// Definición de la función para buscar la palabra en la matriz
bool buscarPalabra(vector<vector<char>>& matriz, const string& palabra, int fila, int columna, int dx, int dy) {
    int len = palabra.length();
    for (int i = 0; i < len; ++i) {
        if (fila < 0 || fila >= matriz.size() || columna < 0 || columna >= matriz[0].size() || matriz[fila][columna] != palabra[i]) {
            return false;
        }
        fila += dx;
        columna += dy;
    }
    return true;
}

// Función para obtener la dirección en palabras
string obtenerDireccion(int dx, int dy) {
    if (dx == 0 && dy == 1) {
        return "derecha";
    } else if (dx == 0 && dy == -1) {
        return "izquierda";
    } else if (dx == 1 && dy == 0) {
        return "abajo";
    } else if (dx == -1 && dy == 0) {
        return "arriba";
    } else if (dx == 1 && dy == 1) {
        return "diagonal derecha inferior";
    } else if (dx == -1 && dy == 1) {
        return "diagonal derecha superior";
    } else if (dx == 1 && dy == -1) {
        return "diagonal izquierda inferior";
    } else if (dx == -1 && dy == -1) {
        return "diagonal izquierda superior";
    } else {
        return "desconocida";
    }
}

// Función principal
int main() {
    int filas, columnas;
    cout << "Ingrese el número de filas de la matriz: ";
    cin >> filas;
    cout << "Ingrese el número de columnas de la matriz: ";
    cin >> columnas;

    vector<vector<char>> matriz(filas, vector<char>(columnas));
    cout << "Ingrese la matriz (una fila a la vez):" << endl;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cin >> matriz[i][j];
        }
    }
    char respuesta='s';
    string palabra;
    bool encontrado;
    while (respuesta=='s')
    {
            encontrado= false; 
            cout << "Ingrese la palabra a buscar: ";
            cin >> palabra;

            // Buscar la palabra en todas las direcciones
            int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
            int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
        
            for (int i = 0; i < filas; ++i) {
                for (int j = 0; j < columnas; ++j) {
                    for (int dir = 0; dir < 8; ++dir) {
                        
                        if (!encontrado) {
                            encontrado= buscarPalabra(matriz, palabra, i, j, dx[dir], dy[dir]);
                            if (encontrado)
                            {
                                cout << "La palabra \"" << palabra << "\" se encuentra en la posición inicial (" << i << ", " << j << ") en la dirección " << obtenerDireccion(dx[dir], dy[dir]) << "." << endl;
                                break;
                            }
                        }
                        
                    }
                }
            }
            if (!encontrado){
            cout << "La palabra \"" << palabra << "\" no se encontró en la matriz." << endl;
            }
        cout << "¿Desea buscar otra palabra? (s/n): ";
                            
        cin >> respuesta;
        respuesta= tolower(respuesta);
           
    }
    
    return 0;
}