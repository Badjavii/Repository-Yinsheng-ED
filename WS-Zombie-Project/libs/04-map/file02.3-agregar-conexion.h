#ifndef FILE02_3_AGREGAR_CONEXION_H
#define FILE02_3_AGREGAR_CONEXION_H
#include "../sources/structs.h"
#include "../sources/outools.h"

void AgregarConexion(EstacionPtr estacion, MapaPtr *mapa)
{
    string nombre;
    coutf(BLUE, "Ingrese el nombre de la estación a conectar: ");
    cinv("string", nombre); // Usar cinv para obtener y validar la entrada del usuario

    EstacionPtr actual = (*mapa)->estaciones;
    while (actual != nullptr)
    {
        if (actual->nombre == nombre)
        {
            EstacionPtr nueva_conexion = new Estacion;
            nueva_conexion->nombre = actual->nombre;
            nueva_conexion->siguiente = estacion->conexiones;
            estacion->conexiones = nueva_conexion;
            coutf(GREEN, "Conexión agregada exitosamente.\n");
            return;
        }
        actual = actual->siguiente;
    }
    coutf(RED, "Estación no encontrada.\n");
    return;
}

#endif // FILE02_3_AGREGAR_CONEXION_H