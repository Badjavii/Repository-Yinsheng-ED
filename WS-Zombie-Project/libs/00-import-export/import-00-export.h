#ifndef IMPORT-00-EXPORT_H
#define IMPORT-00-EXPORT_H
#include "../sources/structs.h"
#include "importar-01-escuadrones.h"
#include "importar-02-estaciones.h"
#include "importar-03-grupos.h"

void importar(Squads** Lista_escuadrones, Estacion** Grafo_mapa, Zombies_Groups** Lista_gruposZ){
    importar_escuadrones(Lista_escuadrones);
    importar_estaciones(Grafo_mapa);
    importar_gruposZ(Lista_gruposZ);
    return;
};


#endif // IMPORT-00-EXPORT_H