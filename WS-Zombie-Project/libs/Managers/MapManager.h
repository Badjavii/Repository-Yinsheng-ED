#ifndef MAPSMANAGER_H
#define MAPSMANAGER_H
#include <iostream>
#include "../outools.h"
#include "../structs.h"
#include "SquadManager.h"
#include "ZombieManager.h"
using namespace std;

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
}

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
}

void AsignarEscuadronAntizombies(EstacionPtr estacion, SquadsPtr *squad_list)
{
    if (isSquadsListEmpty(*squad_list))
    {
        coutf(RED, "No hay escuadrones antizombies disponibles. Cree un escuadrón antes de asignarlo a una estación.\n");
        return;
    }

    MostrarTotalEscuadrones(*squad_list);

    int numero;
    coutf(BLUE, "Ingrese el número del escuadrón antizombies a asignar: ");
    cinv("int", numero);

    // Verificar si el escuadrón ya está asignado a otra estación
    EstacionPtr actual = estacion;
    while (actual != nullptr)
    {
        if (actual->escuadron_antizombies != nullptr && actual->escuadron_antizombies->number == numero)
        {
            coutf(RED, "El escuadrón antizombies ya está asignado a otra estación.\n");
            return;
        }
        actual = actual->siguiente;
    }

    // Asignar el escuadrón antizombies
    SquadsPtr escuadron = *squad_list;
    while (escuadron != nullptr)
    {
        if (escuadron->number == numero)
        {
            estacion->escuadron_antizombies = escuadron;
            coutf(GREEN, "Escuadrón antizombies asignado exitosamente.\n");
            return;
        }
        escuadron = escuadron->next;
    }
    coutf(RED, "Escuadrón antizombies no encontrado.\n");
}

void AsignarGrupoZombies(EstacionPtr estacion, Zombies_GroupsPtr *zombies_groups_list)
{
    if (isZombiesGroupsListEmpty(*zombies_groups_list))
    {
        coutf(RED, "No hay grupos de zombies disponibles. Cree un grupo de zombies antes de asignarlo a una estación.\n");
        return;
    }

    MostrarResumenGruposZombies(*(zombies_groups_list));
    int numero;
    coutf(BLUE, "Ingrese el número del grupo de zombies a asignar: ");
    cinv("int", numero);

    // Verificar si el grupo de zombies ya está asignado a otra estación
    EstacionPtr actual = estacion;
    while (actual != nullptr)
    {
        if (actual->grupo_zombies != nullptr && actual->grupo_zombies->number == numero)
        {
            coutf(RED, "El grupo de zombies ya está asignado a otra estación.\n");
            return;
        }
        actual = actual->siguiente;
    }

    // Asignar el grupo de zombies
    Zombies_GroupsPtr grupo = *zombies_groups_list;
    while (grupo != nullptr)
    {
        if (grupo->number == numero)
        {
            estacion->grupo_zombies = grupo;
            coutf(GREEN, "Grupo de zombies asignado exitosamente.\n");
            return;
        }
        grupo = grupo->next;
    }
    coutf(RED, "Grupo de zombies no encontrado.\n");
}

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
}

#endif // MAPSMANAGER_H
