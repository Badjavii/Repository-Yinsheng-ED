#ifndef 00-IMPORT-EXPORT_H
#define 00-IMPORT-EXPORT_H
#include "../sources/structs.h"
#include "01-importar-escuadrones.h"
#include "02-importar-estaciones.h"
#include "03-importar-grupos.h"

void importar(Squads** Lista_escuadrones, Mapa** Grafo_mapa, Zombies_Groups** Lista_gruposZ){
    importar_escuadrones(Lista_escuadrones);
    importar_estaciones(Grafo_mapa);
    importar_gruposZ(Lista_gruposZ);
    return;
};


#endif // IMPORT-EXPORT_H