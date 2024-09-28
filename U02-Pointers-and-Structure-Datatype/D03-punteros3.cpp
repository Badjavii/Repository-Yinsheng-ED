#include "iostream"
#include <stdlib.h>


using namespace std;

int main()
{
   
typedef struct {
   int codigo;
   string nombre;
   double sueldo;
} tRegistro;

tRegistro registro;
typedef tRegistro *tRegistroPtr;
tRegistroPtr puntero = &registro;
registro.codigo = 12345;
registro.nombre = "Javier";
registro.sueldo = 95000; // 

cout << puntero->codigo << "  " << puntero->nombre 
     << "  " << puntero->sueldo << endl;
return 0;
}