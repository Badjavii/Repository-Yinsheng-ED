#include "iostream"
#include <stdlib.h>


using namespace std;

int main()
{
   
    int i = 5;
    int j = 13;
    int *punt; 
    punt = &i; 
    cout << *punt << endl; // Muestra el valor de i
    punt = &j;
    cout << *punt << endl; // Ahora muestra el valor de j
    int *otro; otro = &i;
    cout << *otro + *punt << endl; // i + j
    int k = *punt;
    cout << k << endl; // Mismo valor que j
    return 0;

}