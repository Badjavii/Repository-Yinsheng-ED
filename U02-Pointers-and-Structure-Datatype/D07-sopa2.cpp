#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Definición de la matriz de letras (puedes modificarla según tus necesidades)
const int ROWS = 5;
const int COLS = 5;
char grid[ROWS][COLS] = {
    {'A', 'B', 'C', 'D', 'E'},
    {'F', 'G', 'H', 'I', 'J'},
    {'K', 'L', 'M', 'N', 'O'},
    {'P', 'Q', 'R', 'S', 'T'},
    {'U', 'V', 'W', 'X', 'Y'}
};

// Función para buscar una palabra en la matriz
bool searchWord(const string& word, int row, int col, int dx, int dy) {
    int len = word.length();
    for (int i = 0; i < len; ++i) {
        if (row < 0 || row >= ROWS || col < 0 || col >= COLS || grid[row][col] != word[i]) {
            return false;
        }
        row += dx;
        col += dy;
    }
    return true;
}

// Función principal
int main() {
    string word;
    while (true) {
        cout << "Ingrese la palabra a buscar (o escriba 'salir' para terminar): ";
        cin >> word;
        if (word == "salir") {
            break;
        }

        bool found = false;
        for (int row = 0; row < ROWS; ++row) {
            for (int col = 0; col < COLS; ++col) {
                // Buscar en todas las direcciones (horizontal, vertical, diagonal)
                for (int dx = -1; dx <= 1; ++dx) {
                    for (int dy = -1; dy <= 1; ++dy) {
                        if (dx != 0 || dy != 0) {
                            if (searchWord(word, row, col, dx, dy)) {
                                cout << "Palabra encontrada en (" << row << ", " << col << ") con dirección (" << dx << ", " << dy << ")." << endl;
                                found = true;
                            }
                        }
                    }
                }
            }
        }

        if (!found) {
            cout << "La palabra no se encontró en la matriz." << endl;
        }
    }

    cout << "¡Hasta luego!" << endl;
    return 0;
}