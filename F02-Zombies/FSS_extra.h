#ifndef FSS_EXTRA_H
#define FSS_EXTRA_H
#include "../Sources/outools.h"
#include "../Sources/struct.h"

//******************* LISTAS VACIAS ******************************/

/**
 * @brief isZgroupListEmpty Verifica si la lista de grupos está vacía.
 * @brief isZombieListEmpty Verifica si la lista de zombies está vacía.
 *
 * @param zgroup_list Es un puntero a la lista de grupos.
 * @param zombie_list Es un puntero a la lista de zombies.
 *
 * @return Todas las funciones retornan true si las listas están vacías, de lo contrario retornan false.
 **/

bool isZgroupListEmpty(Zgroup *zgroup_list)
{
    return (zgroup_list == nullptr);
};

bool isZombieListEmpty(zombie *zombie_list)
{
    return (zombie_list == nullptr);
};

//******************* EXISTE EN LISTA ******************************/

/**
 * @brief existsZgroup Verifica si un grupo existe en la lista.
 * @brief existsZombie Verifica si un zombie existe en la lista.
 * @brief existsZombieInGroup Verifica si un zombie con un ID especificado existe en cualquier grupo de zombies.
 *
 * @param zgroup_list Es un puntero a la lista de escuadrones.
 * @param zombie_list Es un puntero a la lista de zombies.
 *
 * @param number Es el número del grupo a buscar.
 * @param id Es el id del zombie a buscar.
 *
 * @return La función existsZgroup retorna true si el grupo existe, de lo contrario retorna false.
 * @return La función existsZombie retorna true si el zombie existe, de lo contrario retorna false.
 * @return La función existsZombieInGroup retorna true si el zombie existe en algún grupo, false en caso contrario.
 **/

bool existsZgroup(Zgroup *zgroup_list, int number)
{
    while (zgroup_list != nullptr)
    {
        if (zgroup_list->number == number)
            return true;
        zgroup_list = zgroup_list->next;
    }
    return false;
};

bool existsZombie(zombie *zombie_list, int id)
{
    while (zombie_list != nullptr)
    {
        if (zombie_list->id == id)
            return true;
        zombie_list = zombie_list->next;
    }
    return false;
};

bool existsZombieInGroup(Zgroup *zgroup_list, int id)
{
    while (zgroup_list != nullptr)
    {
        zombie *current_zombie = zgroup_list->list_zombies;
        while (current_zombie != nullptr)
        {
            if (current_zombie->id == id)
            {
                return true;
            }
            current_zombie = current_zombie->next;
        }
        zgroup_list = zgroup_list->next;
    }
    return false;
};

//******************* BUSCAR DENTRO DE LISTA ******************************/

/**
 * @brief searchZgroup Busca un grupo en la lista.
 * @brief searchZombie Busca un zombie en la lista.
 * @brief Busca el grupo de zombies al que pertenece un zombie.
 *
 * @param zgroup_list Es un puntero a la lista de escuadrones.
 * @param zombie_list Es un puntero a la lista de zombies.
 *
 * @param number Es el número del grupo a buscar.
 * @param id Es el nombre del zombie a buscar.

 *
 * @return La función searchZgroup retorna un puntero al grupo si lo encuentra, de lo contrario retorna nullptr.
 * @return La función searchZombie retorna un puntero al zombie si lo encuentra, de lo contrario retorna nullptr.
 * @return La función searchZgroupWithZombie retorna un puntero al grupo al que pertenece el zombie, o nullptr si no se encuentra.
 **/

Zgroup *searchZgroup(Zgroup *zgroup_list, int number)
{
    while (zgroup_list != nullptr)
    {
        if (zgroup_list->number == number)
            return zgroup_list;
        zgroup_list = zgroup_list->next;
    }
    return nullptr;
};

zombie *searchZombie(zombie *zombie_list, int id)
{
    while (zombie_list != nullptr)
    {
        if (zombie_list->id == id)
            return zombie_list;
        zombie_list = zombie_list->next;
    }
    return nullptr;
};

Zgroup *searchZgroupWithZombie(Zgroup *zgroup_list, int id)
{
    while (zgroup_list != nullptr)
    {
        if (existsZombie(zgroup_list->list_zombies, id) == true)
        {
            return zgroup_list;
        }
        zgroup_list = zgroup_list->next;
    }
    return nullptr;
};

//******************* CONTAR DENTRO DE LISTA ******************************/

/**
 * @brief countZgroup Cuenta el número de grupos en la lista.
 * @brief countZombie Cuenta el número de zombies en la lista.
 *
 * @param zgroup_list Es un puntero a la lista de grupos.
 * @param zombie_list Es un puntero a la lista de zombies.
 *
 * @return La función countZgroup retorna el número de grupos en la lista.
 * @return La función countZombie retorna el número de zombies en la lista.
 **/

int countZgroup(Zgroup *zgroup_list)
{
    int i = 0;
    while (zgroup_list != nullptr)
    {
        i++;
        zgroup_list = zgroup_list->next;
    }
    return i;
};

int countZombie(zombie *zombie_list)
{
    int i = 0;
    while (zombie_list != nullptr)
    {
        i++;
        zombie_list = zombie_list->next;
    }
    return i;
};

//******************* MOSTRAR DENTRO DE LISTA ******************************/

/**
 * @brief showSummaryZgroup Muestra un resumen de los grupos en la lista.
 * @brief showSummaryZombie Muestra un resumen de los zombies en la lista.
 *
 * @param zgroup_list Es un puntero a la lista de grupos.
 * @param soldier_list Es un puntero a la lista de zombies.
 *
 * @details La función showSummaryZgroup recorre la lista de grupos y muestra el número del grupo y la cantidad de zombies en cada uno.
 * La función showSummaryZombie recorre la lista de zombies y muestra el nombre, la vida, y el estado de la mochila (si tiene y si está vacía o no).
 *
 * @return Ninguna función retorna un valor.
 **/

void showSummaryZgroup(Zgroup *zgroup_list)
{
    coutf(BLUE, "\n\nRESUMEN DE GRUPOS\n");
    coutf(BLUE, "=============================\n");
    while (zgroup_list != nullptr)
    {
        coutf(BLUE, "- Grupo #" + to_string(zgroup_list->number) + " (" + to_string(countZombie(zgroup_list->list_zombies)) + " zombies).\n");
        zgroup_list = zgroup_list->next;
    }
    return;
};

void showSummaryZombie(zombie *soldier_list)
{
    coutf(BLUE, "\n\nRESUMEN DE ZOMBIES\n");
    coutf(BLUE, "=============================\n");
    while (soldier_list != nullptr)
    {
        coutf(BLUE, "- Zombie no." + to_string(soldier_list->id) + ": " + to_string(soldier_list->health) + " de vida y " + to_string(soldier_list->damage) + " de daño.\n");
        soldier_list = soldier_list->next;
    }
    return;
};

/**
 * @brief Muestra los tipos de zombies que hay en el vector.
 *
 * @param types_Zombies Vector de punteros a zombies.
 * @details La función recorre el vector y muestra la información de cada tipo de zombie.
 */
void showZombieTypes(const vector<zombie *> &types_Zombies)
{
    coutf(BLUE, "\n\nTIPOS DE ZOMBIES PREDETERMINADOS\n");
    coutf(BLUE, "------------------------------\n");

    for (size_t i = 0; i < types_Zombies.size(); ++i)
    {
        coutf(BLUE, "ZOMBIE #" + to_string(i + 1) + ":\n");
        coutf(BLUE, "Tipo: " + types_Zombies[i]->type + "\n");
        coutf(BLUE, "Daño: " + to_string(types_Zombies[i]->damage) + "\n");
        coutf(BLUE, "Vida: " + to_string(types_Zombies[i]->health) + "\n");
        coutf(BLUE, "------------------------------\n");
    }
    return;
}

#endif // FSS_EXTRA_H