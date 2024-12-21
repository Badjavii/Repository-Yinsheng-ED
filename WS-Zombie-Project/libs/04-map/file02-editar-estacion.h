#ifndef FILE02_EDITAR_ESTACION_H
#define FILE02_EDITAR_ESTACION_H
#include "../sources/structs.h"
#include "../sources/outools.h"
#include "file02.1-asignar-escuadron.h"
#include "file02.2-asignar-grupo.h"
#include "file02.3-agregar-conexion.h"
#include "file05-sources.h"

void Menu_EditarEstacion(MapaPtr *mapa, SquadsPtr *squad_list, Zombies_GroupsPtr *zombies_groups_list)
{
    string nombre;
    MostrarTotalMaps((*mapa)->estaciones);
    coutf(BLUE, "Ingrese el nombre de la estación a editar: ");
    cinv("string", nombre); // Usar cinv para obtener y validar la entrada del usuario

    EstacionPtr actual = (*mapa)->estaciones;
    while (actual != nullptr)
    {
        if (actual->nombre == nombre)
        {
            int op;
            CLEAR_SCREEN;
            coutf(BLUE, "1. Asignar escuadrón antizombies\n");
            coutf(BLUE, "2. Asignar grupo de zombies\n");
            coutf(BLUE, "3. Agregar conexión\n\n");
            coutf(BLUE, "0. REGRESAR\n");
            cinv("int", op); // Usar cinv para obtener y validar la entrada del usuario

            switch (op)
            {
            case 1:
                AsignarEscuadronAntizombies(actual, squad_list);
                break;
            case 2:
                AsignarGrupoZombies(actual, zombies_groups_list);
                break;
            case 3:
                AgregarConexion(actual, mapa);
                break;
            case 0:
                return;
            default:
                coutf(RED, "Opción no válida.\n");
                break;
            }
            return;
        }
        actual = actual->siguiente;
    }
    coutf(RED, "Estación no encontrada.\n");
}

#endif // FILE02_EDITAR_ESTACION_H