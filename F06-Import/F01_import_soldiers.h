#ifndef F01_IMPORT_SOLDIER_H
#define F01_IMPORT_SOLDIER_H
#include "../Sources/outools.h"
#include "../Sources/struct.h"
#include "../F01-Soldiers/F01_add_squad.h"
#include "../F01-Soldiers/F04_manageBpck_squad/F04.1_add_bpck.h"
#include "../F01-Soldiers/F04_manageBpck_squad/F04.4_add_item.h"
#include "../F01-Soldiers/F03_manageSoldiers_squad/F03.1_add_soldier.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>

void import_Soldiers(squad **squad_list, vector<item *> &items, bpck **backpack_list)
{
    string root = "C:/Soldado.zmb";
    ifstream file(root);
    string line;

    if (!file.is_open())
    {
        cerr << "Error al abrir el archivo: " << root << endl;
        return;
    }
    else
    {
        cout << "Archivo abierto correctamente: " << root << endl;
    }

    getline(file, line); // Leer el número de soldados

    int soldier_count = stoi(line);
    if (soldier_count <= 0)
    {
        cerr << "Cantidad de soldados no válida: " << soldier_count << endl;
        file.close();
        return;
    }

    int squad_number;
    squad *current_squad = nullptr;
    int soldiers_in_squad = 0;

    while (getline(file, line))
    {
        if (line.empty() || line == "---")
            continue; // Si la línea está vacía o es un separador, pasar a la siguiente

        // Leer el nombre del soldado
        string soldier_name = line;

        // Leer la vida del soldado
        if (!getline(file, line))
            break;
        int soldier_health = stoi(line);

        // Crear el nuevo soldado
        soldier *new_soldier = new soldier;
        new_soldier->name = soldier_name;
        new_soldier->health = soldier_health;
        new_soldier->next = nullptr;
        new_soldier->opponent = nullptr;

        // Crear una mochila y asignar 3 ítems no repetidos al soldado
        bpck *new_bpck = create_Bpck(soldier_name);
        add_Bpck(new_soldier, backpack_list, new_bpck); // Añadir la mochila a la lista de mochilas

        for (int i = 0; i < 3; ++i)
        {
            int random_item_index;
            do
            {
                random_item_index = generateRandomNumber(0, items.size() - 1);
            } while (existsItem(new_bpck->list_items, items[random_item_index]->name, items[random_item_index]->effect_value, items[random_item_index]->usages));

            item *selected_item = items[random_item_index];
            item *new_item = create_Item(selected_item->name, selected_item->type_item, selected_item->effect_value, selected_item->usages);
            add_Item(&(new_bpck->list_items), new_item);
        }

        // Crear un nuevo escuadrón si no hay uno actual o si el escuadrón actual está lleno
        if (current_squad == nullptr || soldiers_in_squad == 2)
        {
            do
            {
                squad_number = generateRandomNumber(1, 10000);
            } while (existsSquad(*squad_list, squad_number) == true);

            current_squad = create_Squad(squad_number);
            add_Squad(squad_list, current_squad);
            soldiers_in_squad = 0;
        }

        // Añadir el soldado al escuadrón actual
        add_Soldier(&(current_squad->list_soldiers), new_soldier);
        soldiers_in_squad++;
    }

    file.close();
    return;
}

#endif // F01_IMPORT_SOLDIER_H