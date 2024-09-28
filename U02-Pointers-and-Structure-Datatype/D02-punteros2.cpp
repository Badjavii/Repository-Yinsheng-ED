#include "iostream"
#include <stdlib.h>


using namespace std;

int main()
{
   
typedef int *tIntPtr;
typedef char *tCharPtr;
typedef double *tDoublePtr;

int entero = 5;
tIntPtr puntI = &entero; 
char caracter = 'C';
tCharPtr puntC = &caracter;
double real = 5.23;
tDoublePtr puntD = &real;

cout << *puntI << "  " << *puntC << "  " << *puntD << endl;

}