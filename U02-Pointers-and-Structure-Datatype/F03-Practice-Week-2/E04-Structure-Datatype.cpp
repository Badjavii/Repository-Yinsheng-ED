#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

typedef struct
{
    string Marca;
    string Modelo;
    int Year;
    string Pais;
} tVehiculo;

int main()
{

    typedef tVehiculo *tVehiculoPtr;
    tVehiculoPtr puntero = NULL;

    tVehiculo Vehiculo1;
    tVehiculo Vehiculo2;
    tVehiculo Vehiculo3;
    tVehiculo Vehiculo4;

    tVehiculo Vehiculos[4] = {Vehiculo1, Vehiculo2, Vehiculo3, Vehiculo4};
    string Modelos[4] = {"Corolla", "Runner", "RobaChicas300", "Fiestero"};
    string Marcas[4] = {"Toyota", "Mercedes", "Ferrari", "Audi"};
    int Years[4] = {2023, 1995, 3026, 2000};
    string Paises[4] = {"Japon", "USA", "Rusa", "Pakistan"};

    int limite = sizeof(Marcas) / sizeof(Marcas[0]);

    for (int i = 0; i < limite; i++)
    {
        Vehiculos[i].Modelo = Modelos[i];
        Vehiculos[i].Marca = Marcas[i];
        Vehiculos[i].Year = Years[i];
        Vehiculos[i].Pais = Paises[i];
    }

    for (int i = 0; i < limite; i++)
    {
        puntero = &(Vehiculos[i]);
        cout << "Registro Vehiculo" << i + 1 << endl;
        cout << "Marca: " << puntero->Marca << endl;
        cout << "Modelo: " << puntero->Modelo << endl;
        cout << "Year: " << puntero->Year << endl;
        cout << "Pais: " << puntero->Pais << endl;
        cout << "\n";
    }

    system("pause");
    system("cls");
    return 0;
};
