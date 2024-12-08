#ifndef FILE03_3_1_NOMBRE_SOLDADO_H
#define FILE03_3_1_NOMBRE_SOLDADO_H
#include "../sources/outools.h"
#include "../sources/structs.h"

void EditarNombreSoldado(Soldier *current_soldier)
{
    coutf(GREEN, "Indique el nuevo nombre del soldado: ");
    cinv("string", current_soldier->name);
    coutf(GREEN, "Nombre actualizado exitosamente.\n");
    return;
}

#endif