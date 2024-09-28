#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Función para mostrar la sopa de letras
void mostrarSopa(vector<string> sopa) {
  for (int i = 0; i < sopa.size(); i++) {
    for (int j = 0; j < sopa[i].size(); j++) {
      cout << sopa[i][j] << " ";
    }
    cout << endl;
  }
}

// Función para buscar la palabra en la sopa de letras
bool buscarPalabra(vector<string> sopa, string palabra) {
  int filas = sopa.size();
  int columnas = sopa[0].size();

  // Recorrer la sopa de letras en diferentes direcciones
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      // Buscar la palabra horizontalmente
      if (j + palabra.size() <= columnas) {
        bool encontrado = true;
        for (int k = 0; k < palabra.size(); k++) {
          if (sopa[i][j + k] != palabra[k]) {
            encontrado = false;
            break;
          }
        }
        if (encontrado) {
          return true;
        }
      }

      // Buscar la palabra verticalmente
      if (i + palabra.size() <= filas) {
        bool encontrado = true;
        for (int k = 0; k < palabra.size(); k++) {
          if (sopa[i + k][j] != palabra[k]) {
            encontrado = false;
            break;
          }
        }
        if (encontrado) {
          return true;
        }
      }

      // Buscar la palabra diagonalmente hacia abajo y a la derecha
      if (i + palabra.size() <= filas && j + palabra.size() <= columnas) {
        bool encontrado = true;
        for (int k = 0; k < palabra.size(); k++) {
          if (sopa[i + k][j + k] != palabra[k]) {
            encontrado = false;
            break;
          }
        }
        if (encontrado) {
          return true;
        }
      }

      // Buscar la palabra diagonalmente hacia arriba y a la derecha
      if (i - palabra.size() >= 0 && j + palabra.size() <= columnas) {
        bool encontrado = true;
        for (int k = 0; k < palabra.size(); k++) {
          if (sopa[i - k][j + k] != palabra[k]) {
            encontrado = false;
            break;
          }
        }
        if (encontrado) {
          return true;
        }
      }
    }
  }

  // La palabra no se encontró
  return false;
}

int main() {
  // Ingresar la sopa de letras
  int filas, columnas;
  cout << "Ingrese el número de filas: ";
  cin >> filas;
  cout << "Ingrese el número de columnas: ";
  cin >> columnas;

  vector<string> sopa(filas);
  for (int i = 0; i < filas; i++) {
    cin >> sopa[i];
  }

  // Ingresar la palabra a buscar
  string palabra;
  cout << "Ingrese la palabra a buscar: ";
  cin >> palabra;

  // Mostrar la sopa de letras
  cout << endl << "Sopa de letras:" << endl;
  mostrarSopa(sopa);

  // Buscar la palabra
  bool encontrado = buscarPalabra(sopa, palabra);

  // Mostrar el resultado
  if (encontrado) {
    cout << endl << "La palabra \"" << palabra << "\" se encontró en la sopa de letras." << endl;
  } else {
    cout << endl << "La palabra \"" << palabra << "\" no se encontró en la sopa de letras." << endl;
  }

  return 0;
}
