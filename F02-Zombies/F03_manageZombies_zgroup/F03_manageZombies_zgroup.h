#ifndef F03_MANAGEZOMBIES_ZGROUP_H
#define F03_MANAGEZOMBIES_ZGROUP_H
#include <vector>
#include "../../Sources/outools.h"
#include "../../Sources/struct.h"
#include "F03.1_add_zombie.h"
#include "F03.2_delete_zombie.h"
#include "F03.3_show_zombies.h"
#include "F03.4_kill_zombie.h"
#include "F03.5_hurt_zombie.h"
#include "F03.6_useDamage_zombie.h"
#include "../FSS_extra.h"
#include "../../F01-Soldiers/FZZ_extra.h"
#include "../../F01-Soldiers/F02_consult_squad.h"

void manageZombies_Zgroup(Zgroup **zgroup_list, Zgroup *target_zgroup, zombie **fallen_zombie_list, squad **squad_list, soldier **fallen_soldier_list, bpck **backpack_list, vector<zombie *> type_Zombies)
{
    Zgroup *current_zgroup = target_zgroup;
    int op = -1, x, y, z;
    string chain, chain2;

    while (op)
    {
        CLEAR_SCREEN;
        coutf(BLUE, "\t\tMENU DE EDICIÓN DE GRUPO #" + to_string(current_zgroup->number) + "\n\n");
        coutf(BLUE, "1. Agregar zombie\n");
        coutf(BLUE, "2. Eliminar zombie\n");
        coutf(BLUE, "3. Mostrar zombies\n");
        coutf(BLUE, "4. Matar a un zombie\n");
        coutf(BLUE, "5. Herir a un zombie\n");
        coutf(BLUE, "6. Atacar a un soldado\n\n");
        coutf(BLUE, "0. REGRESAR\n\n");

        cinv("int", op); // Usar cinv para obtener y validar la entrada del usuario

        switch (op)
        {
        case 1:
            coutf(BLUE, "\nIngresa el ID del zombie\n");
            cinv("int", x);

            if (existsZombie(current_zgroup->list_zombies, x) == true)
            {
                coutf(RED, "\nYa existe un zombie con ese ID en el grupo. Intentalo de nuevo.");
                break;
            }

            if (existsZombieInGroup(*zgroup_list, x) == true)
            {
                coutf(RED, "\nYa existe un soldado con ese ID. Intentalo de nuevo.");
                break;
            }

            coutf(BLUE, "\nDeseas incluir un tipo de zombie predeterminado o crear un nuevo tipo de zombie?");
            coutf(BLUE, "\nNOTA: El tipo del zombie se relaciona con sus valores de daño y de vida.");

            do
            {
                coutf(BLUE, "\n1. Tipo Predeterminado  |  2. Tipo Nuevo\n");
                cinv("int", y);
            } while ((y != 1) && (y != 2));

            if (y == 1)
            {
                showZombieTypes(type_Zombies);

                do
                {
                    coutf(BLUE, "\nIngresa el numero del tipo de zombie predeterminado\n");
                    cinv("int", y);
                } while ((y > type_Zombies.size()) || (y < 1));

                y--;

                add_Zombie(&(current_zgroup->list_zombies), create_Zombie(x, type_Zombies[y]->type, type_Zombies[y]->health, type_Zombies[y]->damage));
                break;
            }

            do
            {
                coutf(BLUE, "\nIngresa el numero (1-100) de la salud del zombie\n");
                cinv("int", y);
            } while ((y > 100) || (y < 1));

            coutf(BLUE, "\nIngresa el tipo del zombie (ejemplo: tanque, canibal, etc)\n");
            cinv("string", chain);

            coutf(BLUE, "\nIngresa el valor de daño que tendrá el zombie\n");
            cinv("int", z);

            add_Zombie(&(current_zgroup->list_zombies), create_Zombie(x, chain, y, z));
            break;
        case 2:
            if (isZombieListEmpty(current_zgroup->list_zombies) == true)
            {
                coutf(RED, "\nNo hay zombies para eliminar.");
                break;
            }

            showSummaryZombie(current_zgroup->list_zombies);

            coutf(YELLOW, "\nIngrese el ID del zombie que quiere eliminar:\n");
            cinv("int", x);

            if (existsZombie(current_zgroup->list_zombies, x) == false)
            {
                coutf(RED, "\nNo existe el zombie con el ID " + to_string(x) + ".");
                break;
            }

            delete_Zombie(&(current_zgroup->list_zombies), x);
            break;
        case 3:
            show_zombies(current_zgroup->list_zombies);
            break;
        case 4:
            coutf(YELLOW, "\nNOTA: Matar a un zombie implica será guardado en una lista de zombies caidos y luego será eliminado.");

            if (isZombieListEmpty(current_zgroup->list_zombies) == true)
            {
                coutf(RED, "\nNo hay zombies para matar.");
                break;
            }

            showSummaryZombie(current_zgroup->list_zombies);

            coutf(YELLOW, "\nIngrese el ID del zombie que quieres matar:\n");
            cinv("int", x);

            if (existsZombie(current_zgroup->list_zombies, x) == false)
            {
                coutf(RED, "\nNo existe el zombie con el ID " + to_string(x) + ".");
                break;
            }

            kill_Zombie(zgroup_list, current_zgroup, x, fallen_zombie_list);
            break;
        case 5:
            coutf(YELLOW, "\nNOTA: Herir a un zombie implica que se ingresará un valor de daño el cual va a reducir la vida de un zombie seleccionado por el usuario.");
            coutf(YELLOW, "\nSi el daño que recibe el zombie deja su salud en 0, entonces el zombie morirá.");

            if (isZombieListEmpty(current_zgroup->list_zombies) == true)
            {
                coutf(RED, "\nNo hay zombies. No se puede hacer nada.");
                break;
            }

            showSummaryZombie(current_zgroup->list_zombies);

            coutf(YELLOW, "\nIngrese el ID del zombie que quiere herir:\n");
            cinv("int", x);

            if (existsZombie(current_zgroup->list_zombies, x) == false)
            {
                coutf(RED, "\nNo existe el zombie con ID " + to_string(x) + ".");
                break;
            }

            coutf(YELLOW, "\nIngrese el valor de daño con el que quieres al zombie:\n");
            cinv("int", y);

            hurt_Zombie(zgroup_list, current_zgroup, x, y, fallen_zombie_list);
            break;
        case 6:
            coutf(YELLOW, "\nNOTA: Atacar a un zombie implica que se seleccionará a un zombie que atacará a un soldado seleccionado.");

            if (isZombieListEmpty(current_zgroup->list_zombies) == true)
            {
                coutf(RED, "\nNo hay zombie. No se puede hacer nada.");
                break;
            }

            if (isSquadListEmpty(*squad_list) == true)
            {
                coutf(RED, "\nNo hay escuadrones y, por tanto, no hay soldados. No se puede hacer nada.");
                break;
            }

            showSummaryZombie(current_zgroup->list_zombies);

            coutf(YELLOW, "\nIngrese el ID del zombie que quieres que ataque:\n");
            cinv("int", x);

            if (existsZombie(current_zgroup->list_zombies, x) == false)
            {
                coutf(RED, "\nNo existe el zombie con el ID " + to_string(x) + ".");
                break;
            }

            consult_Squads(*squad_list);

            coutf(YELLOW, "\nIngrese el nombre del soldado que será atacado por el zombie:\n");
            cinv("string", chain);

            if (existsSoldierInSquad(*squad_list, chain) == false)
            {
                coutf(RED, "\nNo existe el soldado " + chain + ".");
                break;
            }

            useDamage_Zombie(squad_list, chain, x, current_zgroup, fallen_soldier_list, backpack_list);
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

#endif // F03_MANAGEZOMBIES_ZGROUP_H