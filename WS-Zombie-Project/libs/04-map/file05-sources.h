#ifndef FILE05_SOURCES_H
#define FILE05_SOURCES_H
#include "../sources/structs.h"
#include "../sources/outools.h"


void ConsultarEstaciones(MapaPtr *mapa)
{
    EstacionPtr actual = (*mapa)->estaciones;
    if (actual == nullptr)
    {
        coutf(RED, "No hay estaciones en el mapa.\n");
        return;
    }

    coutf(BLUE, "Estaciones en el mapa:\n");
    int contador = 1;
    while (actual != nullptr)
    {
        coutf(YELLOW, to_string(contador) + "# Estacion " + actual->nombre + ", Conexión con: ");

        // Mostrar conexiones
        EstacionPtr conexion = actual->conexiones;
        if (conexion == nullptr)
        {
            coutf(YELLOW, "No hay conexiones");
        }
        else
        {
            while (conexion != nullptr)
            {
                coutf(YELLOW, conexion->nombre);
                conexion = conexion->siguiente;
                if (conexion != nullptr)
                {
                    coutf(YELLOW, ", ");
                }
            }
        }
        cout << "\n";

        // Mostrar escuadrón antizombies
        if (actual->escuadron_antizombies != nullptr)
        {
            coutf(GREEN, "    Escuadron Antizombies #: " + to_string(actual->escuadron_antizombies->number));
        }
        else
        {
            coutf(GREEN, "    No hay escuadron antizombies");
        }
        cout << "\n";

        // Mostrar grupo de zombies
        if (actual->grupo_zombies != nullptr)
        {
            coutf(GREEN, "    Grupo Zombies #: " + to_string(actual->grupo_zombies->number));
        }
        else
        {
            coutf(GREEN, "    No hay grupo zombies");
        }
        cout << "\n";

        actual = actual->siguiente;
        contador++;
    }
    return;
}

void MostrarTotalMaps(EstacionPtr Estacion)
{
    coutf(BLUE, "---------------------------------------\n");
    coutf(BLUE, " Resumén de todos los escuadrones\n");
    coutf(BLUE, "---------------------------------------\n");
    coutf(GREEN, "Nombre               Conexión\n");
    coutf(BLUE, "--------------   ---------------------------\n");

    EstacionPtr estacion = Estacion;
    while (estacion != nullptr)
    {
        coutf(BLUE, estacion->nombre + "      ");
        if (!estacion->conexiones)
            coutf(BLUE, "No hay conexiones\n");
        else
            coutf(BLUE, estacion->conexiones->nombre + "/10\n");
        estacion = estacion->siguiente;
    }

    coutf(BLUE, "---------------------------------------\n");
    return;
}

#endif // FILE05_SOURCES_H