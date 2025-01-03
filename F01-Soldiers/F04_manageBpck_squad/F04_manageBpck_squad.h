#ifndef F04_MANAGEBPCK_SQUAD_H
#define F04_MANAGEBPCK_SQUAD_H
#include "../../Sources/outools.h"
#include "../../Sources/struct.h"
#include "../FZZ_extra.h"
#include "F04.1_add_bpck.h"
#include "F04.2_delete_bpck.h"
#include "F04.3_consult_bpck.h"
#include "F04.4_add_item.h"
#include "F04.5_delete_item.h"
#include "F04.6_empty_items.h"
#include "F04.7_swap_items.h"
#include "F04.8_inherit_items.h"

void manageBpck_Squad(bpck **backpack_list, squad *object_squad, vector<item *> pre_items)
{
    squad *current_squad = object_squad;
    int op = -1, x, y;
    string chain, chain2;

    while (op)
    {
        CLEAR_SCREEN;
        coutf(BLUE, "\t\tMENU DE GESTION DE EQUIPAMENTO ESCUADRON #" + to_string(current_squad->number) + "\n\n");
        coutf(BLUE, "1. Crear mochila\n");
        coutf(BLUE, "2. Eliminar mochila\n");
        coutf(BLUE, "3. Consultar equipamento\n");
        coutf(BLUE, "4. Agregar item\n");
        coutf(BLUE, "5. Eliminar item\n");
        coutf(BLUE, "6. Vaciar items de una mochila a otra\n");
        coutf(BLUE, "7. Intercambiar los items entre dos mochilas\n");
        coutf(BLUE, "8. Heredar una mochila\n\n");
        coutf(BLUE, "0. REGRESAR\n\n");

        cinv("int", op); // Usar cinv para obtener y validar la entrada del usuario

        switch (op)
        {
        case 1:
            if (isSoldierListEmpty(current_squad->list_soldiers) == true)
            {
                coutf(RED, "\nNo hay soldados en este escuadron. Se necesitan soldados para crear mochilas.");
                break;
            }

            showSummarySoldier(current_squad->list_soldiers);

            coutf(BLUE, "\nIngresa el nombre del soldado al que pertenece la nueva mochila\n");
            cinv("string", chain);

            if (existsSoldier(current_squad->list_soldiers, chain) == false)
            {
                coutf(RED, "\nNo hay un soldado con el nombre " + chain + ".");
                break;
            }

            if (existsBpck(*backpack_list, chain) == true)
            {
                coutf(RED, "\nYa existe una mochila del soldado " + chain + ".");
                break;
            }

            add_Bpck((searchSoldier(current_squad->list_soldiers, chain)), backpack_list, create_Bpck(chain));
            coutf(YELLOW, "\nLa mochila se creó con exito.");
            break;
        case 2:
            if (isBpckListEmpty(*backpack_list) == true)
            {
                coutf(RED, "\nNo hay mochilas para eliminar.");
                break;
            }

            showSummarySoldier(current_squad->list_soldiers);

            coutf(BLUE, "\nIngresa el nombre del soldado al que pertenece la mochila a eliminar\n");
            cinv("string", chain);

            if (existsSoldier(current_squad->list_soldiers, chain) == false)
            {
                coutf(RED, "\nNo hay un soldado con el nombre " + chain + ", por tanto, no hay mochila para eliminar.");
                break;
            }

            if (existsBpck(*backpack_list, chain) == false)
            {
                coutf(RED, "\nEl solado " + chain + " no tiene mochila para eliminar.");
                break;
            }

            delete_Bpck(searchSoldier(current_squad->list_soldiers, chain), backpack_list);
            coutf(YELLOW, "\nLa mochila se eliminó con exito.");
            break;
        case 3:
            consult_Bpck(*backpack_list, current_squad->list_soldiers);
            break;

        case 4:

            if (isBpckListEmpty(*backpack_list) == true)
            {
                coutf(RED, "\nNo hay mochilas. Se necesitan mochilas para crear items.");
                break;
            }

            showSummaryBpckinSquad(current_squad->list_soldiers);

            coutf(BLUE, "\nIngresa el nombre del soldado al que pertenece la mochila.\n");
            cinv("string", chain);

            if (existsSoldier(current_squad->list_soldiers, chain) == false)
            {
                coutf(RED, "\nNo hay un soldado con el nombre " + chain + ".");
                break;
            }

            if (existsBpck(*backpack_list, chain) == false)
            {
                coutf(RED, "\nNo existe una mochila del soldado " + chain + ".");
                break;
            }

            if (countItem((searchBpck(*backpack_list, chain))->list_items) >= 3)
            {
                coutf(RED, "\nLa mochila está a su máxima capacidad.");
                break;
            }

            coutf(BLUE, "\nDeseas incluir un item predeterminado o crear un nuevo item?");
            do
            {
                coutf(BLUE, "\n1. Item Predeterminado  |  2. Item Nuevo\n");
                cinv("int", x);
            } while ((x != 1) && (x != 2));

            if (x == 1)
            {
                showItemVector(pre_items);

                do
                {
                    coutf(BLUE, "\nIngresa el numero del item predeterminado\n");
                    cinv("int", x);
                } while ((x > pre_items.size()) || (x < 1));

                x--;

                if (existsItem((*backpack_list)->list_items, pre_items[x]->name, pre_items[x]->effect_value, pre_items[x]->usages) == true)
                {
                    coutf(RED, "\nEl item ya existe en la mochila.");
                    break;
                }

                add_Item(&((searchBpck(*backpack_list, chain))->list_items), create_Item(pre_items[x]->name, pre_items[x]->type_item, pre_items[x]->effect_value, pre_items[x]->usages));
                coutf(YELLOW, "\nEl item se creó con exito.");
                break;
            }

            coutf(BLUE, "\nIngresa el nombre del nuevo item\n");
            cinv("string", chain);

            coutf(BLUE, "\nIngresa el numero del tipo de item \n");
            do
            {
                coutf(BLUE, "\n1. Ataque  |  2. Defensa  |  3. Supervivencia\n");
                cinv("int", x);
            } while ((x != 3) && (x != 2) && (x != 1));

            if (x == 1)
                chain2 = "Ataque";
            else if (x == 2)
                chain2 = "Defensa";
            else
                chain2 = "Supervivencia";

            coutf(BLUE, "\nIngresa el numero del valor de efecto del nuevo item\n");
            cinv("int", x);

            coutf(BLUE, "\nIngresa el numero de usos del nuevo item\n");
            cinv("int", y);

            add_Item(&((searchBpck(*backpack_list, chain))->list_items), create_Item(chain, chain2, x, y));
            coutf(YELLOW, "\nEl item se creó con exito.");
            break;

        case 5:
            if (isBpckListEmpty(*backpack_list) == true)
            {
                coutf(RED, "\nNo hay mochilas, por tanto, no hay items para eliminar.");
                break;
            }

            showSummarySoldier(current_squad->list_soldiers);

            coutf(BLUE, "\nIngresa el nombre del soldado al que pertenece la mochila a donde se eliminará el item\n");
            cinv("string", chain);

            if (existsSoldier(current_squad->list_soldiers, chain) == false)
            {
                coutf(RED, "\nNo hay un soldado con el nombre " + chain + ", por tanto, no hay mochila y no se puede eliminar ningun item.");
                break;
            }

            if (existsBpck(*backpack_list, chain) == false)
            {
                coutf(RED, "\nEl solado " + chain + " no tiene mochila, por tanto, no se puede eliminar ningun item.");
                break;
            }

            showSummaryItem((searchBpck(*backpack_list, chain))->list_items);

            coutf(BLUE, "\nIngresa el nombre del item a eliminar\n");
            cinv("string", chain2);

            coutf(BLUE, "\nIngresa el valor de efecto del item a eliminar\n");
            cinv("int", x);

            coutf(BLUE, "\nIngresa el valor de usos del item a eliminar\n");
            cinv("int", y);

            if (existsItem((searchBpck(*backpack_list, chain))->list_items, chain2, x, y) == false)
            {
                coutf(RED, "\nEn la mochila de " + chain + " no existe el item " + chain2 + " con " + to_string(x) + " de valor de efecto y " + to_string(y) + " usos.");
                break;
            }

            delete_Item(&((searchBpck(*backpack_list, chain))->list_items), chain2, y, x);
            coutf(YELLOW, "\nEl item se eliminó con exito.");
            break;
        case 6:
            coutf(YELLOW, "\nNOTA: Vaciar items de una mochila a otra implica que todos los items que se encuentran en una mochila pasaran a otra dejando a la mochila original completamente vacía.");

            if (isBpckListEmpty(*backpack_list) == true)
            {
                coutf(RED, "\nNo hay mochilas, por tanto, no se pueden vaciar mochilas.");
                break;
            }

            if (countBpck(*backpack_list) < 2)
            {
                coutf(RED, "\nNo hay mochilas suficientes, por tanto, no se pueden vaciar mochilas.");
                break;
            }

            showSummaryBpckinSquad(current_squad->list_soldiers);

            coutf(BLUE, "\nIngresa el nombre de la mochila que vas a vaciar\n");
            cinv("string", chain);

            if (existsSoldier(current_squad->list_soldiers, chain) == false)
            {
                coutf(RED, "\nNo hay un soldado con el nombre " + chain + ", por tanto, no hay mochila.");
                break;
            }

            if (existsBpck(*backpack_list, chain) == false)
            {
                coutf(RED, "\nEl solado " + chain + " no tiene mochila, por tanto, no se puede hacer nada.");
                break;
            }

            coutf(BLUE, "\nIngresa el nombre de la mochila donde se guardaran todos los items\n");
            cinv("string", chain2);

            if (existsSoldier(current_squad->list_soldiers, chain2) == false)
            {
                coutf(RED, "\nNo hay un soldado con el nombre " + chain2 + ", por tanto, no hay mochila.");
                break;
            }

            if (existsBpck(*backpack_list, chain2) == false)
            {
                coutf(RED, "\nEl solado " + chain2 + " no tiene mochila, por tanto, no se puede hacer nada.");
                break;
            }

            empty_Items(&((searchBpck(*backpack_list, chain))->list_items), &((searchBpck(*backpack_list, chain2))->list_items));
            break;
        case 7:
            coutf(YELLOW, "\nNOTA: Intercambiar los items entre dos mochilas implica que la lista de items que se encuentran en una mochila se intercambiara por la lista de items de otra mochila.");

            if (isBpckListEmpty(*backpack_list) == true)
            {
                coutf(RED, "\nNo hay mochilas, por tanto, no se pueden intercambiar mochilas.");
                break;
            }

            if (countBpck(*backpack_list) < 2)
            {
                coutf(RED, "\nNo hay mochilas suficientes, por tanto, no se pueden intercambiar mochilas.");
                break;
            }

            showSummaryBpckinSquad(current_squad->list_soldiers);

            coutf(BLUE, "\nIngresa el nombre de la primera mochila\n");
            cinv("string", chain);

            if (existsSoldier(current_squad->list_soldiers, chain) == false)
            {
                coutf(RED, "\nNo hay un soldado con el nombre " + chain + ", por tanto, no hay mochila.");
                break;
            }

            if (existsBpck(*backpack_list, chain) == false)
            {
                coutf(RED, "\nEl solado " + chain + " no tiene mochila, por tanto, no se puede hacer nada.");
                break;
            }

            coutf(BLUE, "\nIngresa el nombre de la segunda mochila\n");
            cinv("string", chain2);

            if (existsSoldier(current_squad->list_soldiers, chain2) == false)
            {
                coutf(RED, "\nNo hay un soldado con el nombre " + chain2 + ", por tanto, no hay mochila.");
                break;
            }

            if (existsBpck(*backpack_list, chain2) == false)
            {
                coutf(RED, "\nEl solado " + chain2 + " no tiene mochila, por tanto, no se puede hacer nada.");
                break;
            }

            swap_Items(&((searchBpck(*backpack_list, chain))->list_items), &((searchBpck(*backpack_list, chain2))->list_items));
            break;
        case 8:
            coutf(YELLOW, "\nNOTA: Heredar una mochila implica que esa mochila va a morir (sera eliminada), pero antes de eso heredara sus items a alguna otra mochila si es que hay.");

            if (isBpckListEmpty(*backpack_list) == true)
            {
                coutf(RED, "\nNo hay mochilas, por tanto, no se pueden heredar mochilas.");
                break;
            }

            if (isSoldierListEmpty(current_squad->list_soldiers) == true)
            {
                coutf(RED, "\nNo hay soldados, por tanto, no se puede hacer nada.");
                break;
            }

            if (countBpckinSquad(current_squad->list_soldiers) == 0)
            {
                coutf(RED, "\nNo hay mochilas en este escuadron, por tanto, no se puede hacer nada.");
                break;
            }

            showSummaryBpckinSquad(current_squad->list_soldiers);

            coutf(BLUE, "\nIngresa el nombre de la mochila que va a heredar\n");
            cinv("string", chain);

            if (existsSoldier(current_squad->list_soldiers, chain) == false)
            {
                coutf(RED, "\nNo hay un soldado con el nombre " + chain + ", por tanto, no hay mochila.");
                break;
            }

            if (existsBpck(*backpack_list, chain) == false)
            {
                coutf(RED, "\nEl solado " + chain + " no tiene mochila, por tanto, no se puede hacer nada.");
                break;
            }

            if (countBpckinSquad(current_squad->list_soldiers) <= 1)
            {
                coutf(YELLOW, "\nNo hay otras mochilas para heredar asi que solo se elminará la mochila de " + chain + ".");
            }

            inherit_Items(current_squad, chain, backpack_list);
            break;
        case 0:
            return;
        default:
            coutf(RED, "Opción inválida. Inténtalo de nuevo.\n");
            break;
        }
        cout << "\n\n";
        PAUSE_TERMINAL;
    }
    return;
};

#endif // F04_MANAGEBPCK_SQUAD_H