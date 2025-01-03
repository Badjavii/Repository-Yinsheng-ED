#ifndef FZZ_EXTRA_H
#define FZZ_EXTRA_H
#include "../Sources/outools.h"
#include "../Sources/struct.h"

//******************* LISTAS VACIAS ******************************/

/**
 * @brief isSquadListEmpty Verifica si la lista de escuadrones está vacía.
 * @brief isSoldierListEmpty Verifica si la lista de soldados está vacía.
 * @brief isBpckListEmpty Verifica si la lista de mochilas está vacía.
 * @brief isItemListEmpty Verifica si la lista de ítems está vacía.
 *
 * @param squad_list Es un puntero a la lista de escuadrones.
 * @param soldier_list Es un puntero a la lista de soldados.
 * @param backpack_list Es un puntero a la lista de mochilas.
 * @param item_list Es un puntero a la lista de ítems.
 *
 * @return Todas las funciones retornan true si las listas están vacías, de lo contrario retornan false.
 **/

bool isSquadListEmpty(squad *squad_list)
{
    return (squad_list == nullptr);
};

bool isSoldierListEmpty(soldier *soldier_list)
{
    return (soldier_list == nullptr);
};

bool isBpckListEmpty(bpck *backpack_list)
{
    return (backpack_list == nullptr);
};

bool isItemListEmpty(item *item_list)
{
    return (item_list == nullptr);
};

//******************* EXISTE EN LISTA ******************************/

/**
 * @brief existsSquad Verifica si un escuadrón existe en la lista.
 * @brief existsSoldier Verifica si un soldado existe en la lista.
 * @brief existsBpck Verifica si una mochila existe en la lista.
 * @brief existsItem Verifica si un ítem existe en la lista.
 *
 * @param squad_list Es un puntero a la lista de escuadrones.
 * @param soldier_list Es un puntero a la lista de soldados.
 * @param backpack_list Es un puntero a la lista de mochilas.
 * @param item_list Es un puntero a la lista de ítems.
 *
 * @param number Es el número del escuadrón a buscar.
 * @param name Es el nombre del soldado a buscar.
 * @param name Es el nombre de la mochila a buscar.
 * @param name Es el nombre del ítem a buscar.
 * @param effect_value Es el valor de efecto del ítem a buscar.
 * @param usages Es el número de usos del ítem a buscar.
 *
 * @return La función existsSquad retorna true si el escuadrón existe, de lo contrario retorna false.
 * @return La función existsSoldier retorna true si el soldado existe, de lo contrario retorna false.
 * @return La función existsBpck retorna true si la mochila existe, de lo contrario retorna false.
 * @return La función existsItem retorna true si el ítem existe, de lo contrario retorna false.
 **/

bool existsSquad(squad *squad_list, int number)
{
    while (squad_list != nullptr)
    {
        if (squad_list->number == number)
            return true;
        squad_list = squad_list->next;
    }
    return false;
};

bool existsSoldier(soldier *soldier_list, string name)
{
    while (soldier_list != nullptr)
    {
        if (soldier_list->name == name)
            return true;
        soldier_list = soldier_list->next;
    }
    return false;
};

bool existsSoldierInSquad(squad *squad_list, string name)
{
    while (squad_list != nullptr)
    {
        soldier *current_zombie = squad_list->list_soldiers;
        while (current_zombie != nullptr)
        {
            if (current_zombie->name == name)
            {
                return true;
            }
            current_zombie = current_zombie->next;
        }
        squad_list = squad_list->next;
    }
    return false;
};

bool existsBpck(bpck *backpack_list, string name)
{
    while (backpack_list != nullptr)
    {
        if (backpack_list->name == name)
            return true;
        backpack_list = backpack_list->next;
    }
    return false;
};

bool existsItem(item *item_list, string name, int effect_value, int usages)
{
    while (item_list != nullptr)
    {
        if ((item_list->name == name) && (item_list->effect_value == effect_value) && (item_list->usages == usages))
            return true;
        item_list = item_list->next;
    }
    return false;
};

//******************* BUSCAR DENTRO DE LISTA ******************************/

/**
 * @brief searchSquad Busca un escuadrón en la lista.
 * @brief searchSoldier Busca un soldado en la lista.
 * @brief searchBpck Busca una mochila en la lista.
 * @brief searchItem Busca un ítem en la lista.
 *
 * @param squad_list Es un puntero a la lista de escuadrones.
 * @param soldier_list Es un puntero a la lista de soldados.
 * @param backpack_list Es un puntero a la lista de mochilas.
 * @param item_list Es un puntero a la lista de ítems.
 *
 * @param number Es el número del escuadrón a buscar.
 * @param name Es el nombre del soldado a buscar.
 * @param name Es el nombre de la mochila a buscar.
 * @param name Es el nombre del ítem a buscar.
 * @param effect_value Es el valor de efecto del ítem a buscar.
 * @param usages Es el número de usos del ítem a buscar.
 *
 * @return La función searchSquad retorna un puntero al escuadrón si lo encuentra, de lo contrario retorna nullptr.
 * @return La función searchSoldier retorna un puntero al soldado si lo encuentra, de lo contrario retorna nullptr.
 * @return La función searchBpck retorna un puntero a la mochila si la encuentra, de lo contrario retorna nullptr.
 * @return La función searchItem retorna un puntero al ítem si lo encuentra, de lo contrario retorna nullptr.
 **/

squad *searchSquad(squad *squad_list, int number)
{
    while (squad_list != nullptr)
    {
        if (squad_list->number == number)
            return squad_list;
        squad_list = squad_list->next;
    }
    return nullptr;
};

soldier *searchSoldier(soldier *soldier_list, string name)
{
    while (soldier_list != nullptr)
    {
        if (soldier_list->name == name)
            return soldier_list;
        soldier_list = soldier_list->next;
    }
    return nullptr;
};

bpck *searchBpck(bpck *backpack_list, string name)
{
    while (backpack_list != nullptr)
    {
        if (backpack_list->name == name)
            return backpack_list;
        backpack_list = backpack_list->next;
    }
    return nullptr;
};

item *searchItem(item *item_list, string name, int effect_value, int usages)
{
    while (item_list != nullptr)
    {
        if ((item_list->name == name) && (item_list->effect_value == effect_value) && (item_list->usages == usages))
            return item_list;
        item_list = item_list->next;
    }
    return nullptr;
};

//******************* CONTAR DENTRO DE LISTA ******************************/

/**
 * @brief countSquad Cuenta el número de escuadrones en la lista.
 * @brief countSoldier Cuenta el número de soldados en la lista.
 * @brief countBpck Cuenta el número de mochilas en la lista.
 * @brief countBpckinSquad Cuenta las mochilas en un escuadrón.
 * @brief countItem Cuenta el número de ítems en la lista.
 *
 * @param squad_list Es un puntero a la lista de escuadrones.
 * @param soldier_list Es un puntero a la lista de soldados.
 * @param backpack_list Es un puntero a la lista de mochilas.
 * @param item_list Es un puntero a la lista de ítems.
 *
 * @return La función countSquad retorna el número de escuadrones en la lista.
 * @return La función countSoldier retorna el número de soldados en la lista.
 * @return La función countBpck retorna el número de mochilas en la lista.
 * @return countBpckinSquad int Número de mochilas en el escuadrón.
 * @return La función countItem retorna el número de ítems en la lista.
 **/

int countSquad(squad *squad_list)
{
    int i = 0;
    while (squad_list != nullptr)
    {
        i++;
        squad_list = squad_list->next;
    }
    return i;
};

int countSoldier(soldier *soldier_list)
{
    int i = 0;
    while (soldier_list != nullptr)
    {
        i++;
        soldier_list = soldier_list->next;
    }
    return i;
};

int countBpck(bpck *backpack_list)
{
    int i = 0;
    while (backpack_list != nullptr)
    {
        i++;
        backpack_list = backpack_list->next;
    }
    return i;
};

int countBpckinSquad(soldier *soldier_list)
{
    int count = 0;
    while (soldier_list != nullptr)
    {
        if (soldier_list->backpag != nullptr)
        {
            count++;
        }
        soldier_list = soldier_list->next;
    }
    return count;
};

int countItem(item *item_list)
{
    int i = 0;
    while (item_list != nullptr)
    {
        i++;
        item_list = item_list->next;
    }
    return i;
};

//******************* MOSTRAR DENTRO DE LISTA ******************************/

/**
 * @brief showSummarySquad Muestra un resumen de los escuadrones en la lista.
 * @brief showSummarySoldier Muestra un resumen de los soldados en la lista.
 * @brief showSummaryBpck Muestra un resumen de las mochilas en la lista.
 * @brief showSummaryBpckinSquad Muestra un resumen de las mochilas dentro de un escuadrón.
 * @brief showSummaryItem Muestra un resumen de los ítems en la lista.
 * @brief showItemVector Muestra los ítems en el vector de punteros a ítems.
 *
 * @param squad_list Es un puntero a la lista de escuadrones.
 * @param soldier_list Es un puntero a la lista de soldados.
 * @param backpack_list Es un puntero a la lista de mochilas.
 * @param item_list Es un puntero a la lista de ítems.
 * @param pre_items Vector de punteros a ítems a mostrar.
 *
 * @details La función showSummarySquad recorre la lista de escuadrones y muestra el número de escuadrón y la cantidad de soldados en cada uno.
 * La función showSummarySoldier recorre la lista de soldados y muestra el nombre, la vida, y el estado de la mochila (si tiene y si está vacía o no).
 * La función showSummaryBpck recorre la lista de mochilas y muestra el nombre de cada mochila y la cantidad de ítems que contiene.
 * La función showSummaryBpckinSquad recorre la lista de soldados y muestra un resumen de las mochilas que pertenecen a cada soldado. La información incluye el nombre de la mochila y la cantidad de ítems que contiene.
 * La función showSummaryItem recorre la lista de ítems y muestra el nombre, tipo, valor de efecto y usos de cada ítem.
 * La función showItemVector recorre el vector de punteros a ítems y muestra la información de cada ítem en la consola. Se muestra el nombre, tipo, usos y valor de efecto de cada ítem.
 *
 * @return Ninguna función retorna un valor.
 **/

void showSummarySquad(squad *squad_list)
{
    coutf(BLUE, "\n\nRESUMEN DE ESCUADRONES\n");
    coutf(BLUE, "----------------------------------------\n");
    while (squad_list != nullptr)
    {
        coutf(BLUE, "- Escuadron #" + to_string(squad_list->number) + " (" + to_string(countSoldier(squad_list->list_soldiers)) + " soldados).\n");
        squad_list = squad_list->next;
    }
    return;
};

void showSummarySoldier(soldier *soldier_list)
{
    coutf(BLUE, "\n\nRESUMEN DE SOLDADOS\n");
    coutf(BLUE, "----------------------------------------\n");
    while (soldier_list != nullptr)
    {
        coutf(BLUE, "- Soldado " + soldier_list->name + ": " + to_string(soldier_list->health) + " de vida y ");
        if (soldier_list->backpag == nullptr)
        {
            coutf(BLUE, "no tiene mochila.\n");
        }
        else
        {
            if (soldier_list->backpag->list_items == nullptr)
            {
                coutf(BLUE, "su mochila está vacía.\n");
            }
            else
            {
                coutf(BLUE, "su mochila tiene " + to_string(countItem(soldier_list->backpag->list_items)) + " items.\n");
            }
        }
        soldier_list = soldier_list->next;
    }
    return;
};

void showSummaryBpck(bpck *backpack_list)
{
    coutf(BLUE, "\n\nRESUMEN DE MOCHILAS\n");
    coutf(BLUE, "----------------------------------------\n");
    while (backpack_list != nullptr)
    {
        coutf(BLUE, "- Mochila de " + backpack_list->name + " (" + to_string(countItem(backpack_list->list_items)) + " items).\n");
        backpack_list = backpack_list->next;
    }
    return;
};

void showSummaryBpckinSquad(soldier *soldier_list)
{
    coutf(BLUE, "\n\nRESUMEN DE MOCHILAS EN EL ESCUADRON\n");
    coutf(BLUE, "----------------------------------------\n");

    while (soldier_list != nullptr)
    {
        if (soldier_list->backpag != nullptr)
        {
            coutf(BLUE, "- Mochila de " + soldier_list->name + " (" + to_string(countItem(soldier_list->backpag->list_items)) + " items).\n");
        }
        else
        {
            coutf(BLUE, "- El soldado " + soldier_list->name + " no tiene mochila.\n");
        }

        soldier_list = soldier_list->next;
    }

    return;
};

void showSummaryItem(item *item_list)
{
    coutf(BLUE, "\n\nRESUMEN DE ITEMS\n");
    coutf(BLUE, "----------------------------------------\n");
    int i = 1;
    while (item_list != nullptr)
    {
        coutf(BLUE, "- Item #" + to_string(i) + ": " + item_list->name + " (" + item_list->type_item + " ). Efecto: " + to_string(item_list->effect_value) + ". Usos: " + to_string(item_list->usages) + ".\n");
        item_list = item_list->next;
        i++;
    }
    return;
};

void showItemVector(vector<item *> pre_items)
{
    coutf(BLUE, "\n\nITEMS PREDETERMINADOS\n");
    coutf(BLUE, "------------------------------\n");

    for (size_t i = 0; i < pre_items.size(); ++i)
    {
        coutf(BLUE, "ÍTEM #" + to_string(i + 1) + ":\n");
        coutf(BLUE, "Nombre: " + pre_items[i]->name + "\n");
        coutf(BLUE, "Tipo: " + pre_items[i]->type_item + "\n");
        coutf(BLUE, "Usos: " + to_string(pre_items[i]->usages) + "\n");
        coutf(BLUE, "Valor de efecto: " + to_string(pre_items[i]->effect_value) + "\n");
        coutf(BLUE, "------------------------------\n");
    }
    return;
};

#endif // FZZ_EXTRA_H