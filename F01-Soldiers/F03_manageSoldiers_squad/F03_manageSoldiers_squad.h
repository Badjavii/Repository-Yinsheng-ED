#ifndef F03_EDIT_SQUAD_H
#define F03_EDIT_SQUAD_H
#include "../../Sources/outools.h"
#include "../../Sources/struct.h"
#include "../FZZ_extra.h"
#include "../../F02-Zombies/FSS_extra.h"
#include "F03.1_add_soldier.h"
#include "F03.2_delete_soldier.h"
#include "F03.3_kill_soldier.h"
#include "F03.4_useDefensive_item.h"
#include "F03.5_useSurvival_item.h"
#include "F03.6_hurt_soldier.h"
#include "F03.7_useAttack_item.h"
#include "F03.8_show_soldiers.h"
#include "../../F02-Zombies/F02_consult_zgroup.h"

void manageSoldiers_Squad(squad **squad_list, squad *target_squad, soldier **fallen_soldier_list, bpck **backpack_list, Zgroup **zgroup_list, zombie **fallen_zombie_list)
{
    squad *current_squad = target_squad;
    int op = -1, x, y;
    string chain, chain2;

    while (op)
    {
        CLEAR_SCREEN;
        coutf(BLUE, "\t\tMENU DE EDICIÓN DE ESCUADRON #" + to_string(current_squad->number) + "\n\n");
        coutf(BLUE, "1. Agregar soldado\n");
        coutf(BLUE, "2. Eliminar soldado\n");
        coutf(BLUE, "3. Matar a un soldado\n");
        coutf(BLUE, "4. Usar item de defensa de un soldado\n");
        coutf(BLUE, "5. Usar item de supervivencia de un soldado\n");
        coutf(BLUE, "6. Herir a un soldado\n");
        coutf(BLUE, "7. Usar item de ataque de un soldado contra un zombie\n");
        coutf(BLUE, "8. Mostrar soldados vivos del escuadron\n\n");
        coutf(BLUE, "0. REGRESAR\n\n");

        cinv("int", op); // Usar cinv para obtener y validar la entrada del usuario

        switch (op)
        {
        case 1:
            coutf(BLUE, "\nIngresa el nombre del soldado\n");
            cinv("string", chain);

            if (existsSoldier(current_squad->list_soldiers, chain) == true)
            {
                coutf(RED, "\nYa existe un soldado con ese nombre en el escuadron. Intentalo de nuevo.");
                break;
            }

            if (existsSoldierInSquad(*squad_list, chain) == true)
            {
                coutf(RED, "\nYa existe un soldado con ese nombre. Intentalo de nuevo.");
                break;
            }

            do
            {
                coutf(BLUE, "\nIngresa el numero (1-100) de la salud del soldado\n");
                cinv("int", x);
            } while ((x > 100) || (x < 1));

            add_Soldier(&(current_squad->list_soldiers), create_Soldier(chain, x));
            break;
        case 2:
            if (isSoldierListEmpty(current_squad->list_soldiers) == true)
            {
                coutf(RED, "\nNo hay soldados para eliminar.");
                break;
            }

            showSummarySoldier(current_squad->list_soldiers);

            coutf(YELLOW, "\nIngrese el nombre del soldado que quiere eliminar:\n");
            cinv("string", chain);

            if (existsSoldier(current_squad->list_soldiers, chain) == false)
            {
                coutf(RED, "\nNo existe el soldado" + chain + ".");
                break;
            }

            delete_Soldier(&(current_squad->list_soldiers), chain, backpack_list);
            break;
        case 3:
            coutf(YELLOW, "\nNOTA: Matar a un soldado implica que sus items serán heredados por otro soldado aleatorio y luego será eliminado.");

            if (isSoldierListEmpty(current_squad->list_soldiers) == true)
            {
                coutf(RED, "\nNo hay soldados para matar.");
                break;
            }

            showSummarySoldier(current_squad->list_soldiers);

            coutf(YELLOW, "\nIngrese el nombre del soldado que quieres matar:\n");
            cinv("string", chain);

            if (existsSoldier(current_squad->list_soldiers, chain) == false)
            {
                coutf(RED, "\nNo existe el soldado " + chain + ".");
                break;
            }

            kill_Soldier(squad_list, current_squad, chain, fallen_soldier_list, backpack_list);
            break;
        case 4:
            coutf(YELLOW, "\nNOTA: Usar un item defensiva implica que se ingresará un valor de daño el cual se buscara reducir usando un item defensivo de un soldado seleccionado.");
            coutf(YELLOW, "\nNOTA: La selección del item defensiva se hará de forma automatica por el criterio del item defensivo mas eficiente para reducir el daño que el usuario ingreso.");

            if (isSoldierListEmpty(current_squad->list_soldiers) == true)
            {
                coutf(RED, "\nNo hay soldados. No se puede hacer nada.");
                break;
            }

            if (countBpckinSquad(current_squad->list_soldiers) == 0)
            {
                coutf(RED, "\nNo hay mochilas en ningun soldado de este escuadron, por tanto, no se puede hacer nada.");
                break;
            }

            coutf(YELLOW, "\nIngrese el valor de daño que desea reducir:\n");
            cinv("int", x);

            showSummaryBpckinSquad(current_squad->list_soldiers);

            coutf(YELLOW, "\nIngrese el nombre del soldado al que pertenece la mochila:\n");
            cinv("string", chain);

            if (existsSoldier(current_squad->list_soldiers, chain) == false)
            {
                coutf(RED, "\nNo existe el soldado" + chain + ".");
                break;
            }

            if (existsBpck(*backpack_list, chain) == false)
            {
                coutf(RED, "\nNo existe ninguna mochila con el nombre de " + chain + ".");
                break;
            }

            y = useDefensive_item(chain, &(searchSoldier(current_squad->list_soldiers, chain)->backpag->list_items), x);

            if (x == y)
            {
                coutf(RED, "\nNo hay ningun item defensivo en la mochila de " + chain + ".");
                break;
            }
            break;
        case 5:
            coutf(YELLOW, "\nNOTA: Usar un item de supervivencia implica que se ingresará un soldado el cual tiene la vida menor a 100 y se curará con un item de supervivencia de su mochila.");
            coutf(YELLOW, "\nNOTA: La selección del item de supervivencia se hará de forma automatica por el criterio del item de supervivencia mas eficiente para curar al soldado que el usuario ingreso.");
            coutf(YELLOW, "\nNOTA: En caso de que en la mochila del soldado no haya ningun item de supervivencia, no se hará nada.");

            if (isSoldierListEmpty(current_squad->list_soldiers) == true)
            {
                coutf(RED, "\nNo hay soldados. No se puede hacer nada.");
                break;
            }

            if (countBpckinSquad(current_squad->list_soldiers) == 0)
            {
                coutf(RED, "\nNo hay mochilas en ningun soldado de este escuadron, por tanto, no se puede hacer nada.");
                break;
            }

            showSummarySoldier(current_squad->list_soldiers);

            coutf(YELLOW, "\nIngrese el nombre del soldado que quiere curar:\n");
            cinv("string", chain);

            if (existsSoldier(current_squad->list_soldiers, chain) == false)
            {
                coutf(RED, "\nNo existe el soldado" + chain + ".");
                break;
            }

            if (existsBpck(*backpack_list, chain) == false)
            {
                coutf(RED, "\nEl soldado " + chain + " no tiene mochila y no se puede hacer nada.");
                break;
            }

            if (searchSoldier(current_squad->list_soldiers, chain)->health == 100)
            {
                coutf(RED, "\nEl soldado " + chain + " esta a 100 de vida y no se puede curar más.");
                break;
            }

            useSurvival_item(&(current_squad->list_soldiers), chain);
            break;
        case 6:
            coutf(YELLOW, "\nNOTA: Herir a un soldado implica que se ingresará un valor de daño el cual va a reducir la vida de un soldado seleccionado por el usuario.");
            coutf(YELLOW, "\nSin embargo, se revisará si el soldado tiene algun item defensivo con el que pueda reducir el daño que recibirá.");
            coutf(YELLOW, "\nPor otra parte, si el daño que recibe el soldado deja su salud en 0, entonces el soldado morirá dejandole asi sus items a otro soldado.");

            if (isSoldierListEmpty(current_squad->list_soldiers) == true)
            {
                coutf(RED, "\nNo hay soldados. No se puede hacer nada.");
                break;
            }

            coutf(YELLOW, "\nIngrese el valor de daño con el que deseas herir al soldado:\n");
            cinv("int", x);

            showSummaryBpckinSquad(current_squad->list_soldiers);

            coutf(YELLOW, "\nIngrese el nombre del soldado al que pertenece la mochila:\n");
            cinv("string", chain);

            if (existsSoldier(current_squad->list_soldiers, chain) == false)
            {
                coutf(RED, "\nNo existe el soldado" + chain + ".");
                break;
            }

            if (existsBpck(*backpack_list, chain) == false)
            {
                coutf(RED, "\nNo existe ninguna mochila con el nombre de " + chain + ".");
                break;
            }

            hurt_Soldier(squad_list, current_squad, chain, x, fallen_soldier_list, backpack_list);
            break;
        case 7:
            coutf(YELLOW, "\nNOTA: Usar un item de ataque implica que se ingresará a un soldado para que ataque a un zombie seleccionado con un item de ataque de su mochila.");
            coutf(YELLOW, "\nNOTA: La selección del item de ataque se hará de forma automatica por el criterio del item de ataque mas eficiente para atacar al zombie que el usuario ingreso.");
            coutf(YELLOW, "\nNOTA: En caso de que en la mochila del soldado no haya ningun item de ataque, no se hará nada.");

            if (isSoldierListEmpty(current_squad->list_soldiers) == true)
            {
                coutf(RED, "\nNo hay soldados. No se puede hacer nada.");
                break;
            }

            if (countBpckinSquad(current_squad->list_soldiers) == 0)
            {
                coutf(RED, "\nNo hay mochilas en ningun soldado de este escuadron, por tanto, no se puede hacer nada.");
                break;
            }

            if (isZgroupListEmpty(*zgroup_list) == true)
            {
                coutf(RED, "\nNo hay grupos, por tanto, no hay zombies. No se puede hacer nada.");
                break;
            }

            showSummarySoldier(current_squad->list_soldiers);

            coutf(YELLOW, "\nIngrese el nombre del soldado que quieres que ataque a un zombie:\n");
            cinv("string", chain);

            if (existsSoldier(current_squad->list_soldiers, chain) == false)
            {
                coutf(RED, "\nNo existe el soldado" + chain + ".");
                break;
            }

            consult_Zgroup(*zgroup_list);

            coutf(YELLOW, "\nIngrese el ID del zombie que recibirá el daño:\n");
            cinv("int", x);

            if (existsZombieInGroup(*zgroup_list, x) == false)
            {
                coutf(RED, "\nNo existe el zombie de ID " + to_string(x) + "  y no se puede hacer nada.");
                break;
            }

            useAttack_item(&(searchBpck(*backpack_list, chain)->list_items), chain, x, searchZgroupWithZombie(*zgroup_list, x), zgroup_list, fallen_zombie_list);
            break;
        case 8:
            show_soldiers(current_squad->list_soldiers);
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

#endif // F03_EDIT_SQUAD_H