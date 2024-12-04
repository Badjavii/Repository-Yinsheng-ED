#ifndef FILE02_IMPORT_EXPORT_H
#define FILE00_IMPORT_EXPORT_H
#include "../sources/structs.h"
#include "file01-importar-escuadrones.h"
#include "file02-importar-estaciones.h"
#include "file03-importar-grupos.h"

void importar(Squads** Lista_escuadrones, Estacion** Grafo_mapa, Zombies_Groups** Lista_gruposZ){
    importar_escuadrones(Lista_escuadrones);
    importar_estaciones(Grafo_mapa);
    importar_gruposZ(Lista_gruposZ);
    return;
};


#endif // FILE00_IMPORT_EXPORT_H