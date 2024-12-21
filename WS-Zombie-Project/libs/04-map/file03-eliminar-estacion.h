#ifndef FILE03_ELIMINAR_ESTACION_H
#define FILE03_ELIMINAR_ESTACION_H
#include "../sources/structs.h"
#include "../sources/outools.h"

void EliminarEstacion(MapaPtr *mapa)
{
    //MostrarTotalMaps((*mapa)->estaciones);
    string nombre;
    coutf(BLUE, "Ingrese el nombre de la estación a eliminar: ");
    cinv("string", nombre);
    EstacionPtr actual = (*mapa)->estaciones;
    EstacionPtr anterior = nullptr;

    while (actual != nullptr)
    {
        if (actual->nombre == nombre)
        {
            if (anterior == nullptr)
            {
                (*mapa)->estaciones = actual->siguiente;
            }
            else
            {
                anterior->siguiente = actual->siguiente;
            }

            // Desvincular grupos de zombies y escuadrones
            actual->grupo_zombies = nullptr;
            actual->escuadron_antizombies = nullptr;

            // Liberar conexiones
            EstacionPtr conexion_actual = actual->conexiones;
            while (conexion_actual != nullptr)
            {
                EstacionPtr conexion_siguiente = conexion_actual->siguiente;
                delete conexion_actual;
                conexion_actual = conexion_siguiente;
            }

            // Liberar la estación
            delete actual;
            coutf(GREEN, "Estación eliminada exitosamente.\n");
            return;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    coutf(RED, "Estación no encontrada.\n");
    return;
}

#endif // FILE03_ELIMINAR_ESTACION_H