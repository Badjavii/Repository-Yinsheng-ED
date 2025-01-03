#ifndef F04_7_SWAP_ITEMS_H
#define F04_7_SWAP_ITEMS_H
#include "../../Sources/outools.h"
#include "../../Sources/struct.h"
#include "../FZZ_extra.h"

/**
 * @brief Intercambia las listas de ítems entre list y list2.
 *
 * @param list Lista de ítems de la primera mochila.
 * @param list2 Lista de ítems de la segunda mochila.
 *
 * @details La función utiliza un puntero auxiliar para enlazar temporalmente la lista de ítems de list. Luego conecta el puntero de list a la lista de ítems de list2 y finalmente conecta el puntero de list2 con la lista que tiene el puntero auxiliar.
 */

void swap_Items(item **list, item **list2)
{
    // Utilizar un puntero auxiliar para almacenar temporalmente la lista de ítems de list
    item *aux = *list;

    // Conectar el puntero de list a la lista de ítems de list2
    *list = *list2;

    // Conectar el puntero de list2 con la lista que tiene el puntero auxiliar
    *list2 = aux;
    return;
};

#endif // F04_7_SWAP_ITEMS_H