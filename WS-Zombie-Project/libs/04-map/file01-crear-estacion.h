#ifndef FILE01_CREAR_ESTACION_H
#define FILE01_CREAR_ESTACION_H
#include "../sources/structs.h"
#include "../sources/outools.h"

void CrearEstacion(MapaPtr *mapa)
{
    string nombre;
    coutf(BLUE, "Ingrese el nombre de la nueva estación: ");
    cinv("string", nombre);

    // Verificar si el nombre ya existe
    EstacionPtr actual = (*mapa)->estaciones;
    while (actual != nullptr)
    {
        if (actual->nombre == nombre)
        {
            coutf(RED, "El nombre de la estación ya existe. Intente con otro nombre.\n");
            return;
        }
        actual = actual->siguiente;
    }

    // Crear la nueva estación
    EstacionPtr nueva_estacion = new Estacion;
    nueva_estacion->nombre = nombre;
    nueva_estacion->siguiente = (*mapa)->estaciones;
    nueva_estacion->conexiones = nullptr;
    nueva_estacion->grupo_zombies = nullptr;
    nueva_estacion->escuadron_antizombies = nullptr;

    (*mapa)->estaciones = nueva_estacion;
    coutf(GREEN, "Estación creada exitosamente.\n");
}

#endif // FILE01_CREAR_ESTACION_H