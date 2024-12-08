#ifndef FILE03_ESTACIONES_H
#define FILE03_ESTACIONES_H
#include "../sources/outools.h"
#include "../sources/structs.h"
#include "file01-escuadrones.h"
#include "file02-zombies.h"

void LiberarMapa(MapaPtr *mapa)
{
    EstacionPtr estacion_actual = (*mapa)->estaciones;
    while (estacion_actual != nullptr)
    {
        EstacionPtr estacion_siguiente = estacion_actual->siguiente;
        // Liberar conexiones
        EstacionPtr conexion_actual = estacion_actual->conexiones;
        while (conexion_actual != nullptr)
        {
            EstacionPtr conexion_siguiente = conexion_actual->siguiente;
            delete conexion_actual;
            conexion_actual = conexion_siguiente;
        }
        // Liberar grupos de zombies y escuadrones
        LiberarZombies(&(estacion_actual->grupo_zombies));
        LiberarEscuadrones(&(estacion_actual->escuadron_antizombies));
        // Liberar la estación
        delete estacion_actual;
        estacion_actual = estacion_siguiente;
    }
    delete *mapa;
    *mapa = nullptr;
}

#endif