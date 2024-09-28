#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Para convertir letras a minúsculas
using namespace std;

// Función para buscar una palabra en la matriz (ignorando mayúsculas y minúsculas)
bool searchWord(const string& word, const vector<vector<char>>& grid, int row, int col, int dx, int dy) {
    int len = word.length();
    for (int i = 0; i < len; ++i) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) {
            return false;
        }
        char gridChar = tolower(grid[row][col]); // Convertir a minúsculas
        char wordChar = tolower(word[i]); // Convertir a minúsculas
        if (gridChar != wordChar) {
            return false;
        }
        row += dx;
        col += dy;
    }
    return true;
}

// Función principal
int main() {
    int rows, cols;
    cout << "Ingrese el número de filas de la matriz: ";
    cin >> rows;
    cout << "Ingrese el número de columnas de la matriz: ";
    cin >> cols;

    vector<vector<char>> grid(rows, vector<char>(cols));
    cout << "Ingrese la matriz de letras:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> grid[i][j];
        }
    }

    string word;
    while (true) {
        cout << "Ingrese la palabra a buscar (o escriba 'salir' para terminar): ";
        cin >> word;
        if (word == "salir") {
            break;
        }

        bool found = false;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                // Buscar en todas las direcciones (horizontal, vertical, diagonal)
                for (int dx = -1; dx <= 1; ++dx) {
                    for (int dy = -1; dy <= 1; ++dy) {
                        if (dx != 0 || dy != 0) {
                            if (searchWord(word, grid, row, col, dx, dy)) {
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
