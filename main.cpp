#include <iostream>
#include "Sources/outools.h"
#include "Sources/struct.h"
#include "F00-Main-Menu/main_menu.h"
#include "F06-Import/F01_import_soldiers.h"
#include "F06-Import/F02_import_items.h"
#include "F06-Import/F03_import_zombies.h"
#include "F06-Import/F04_import_stations.h"
using namespace std;

int main()
{

    squad *squad_list = nullptr;
    soldier *fallen_soldiers_list = nullptr;
    bpck *backpack_list = nullptr;
    Zgroup *zgroups_list = nullptr;
    zombie *fallen_zombie_list = nullptr;
    station *station_list = nullptr;
    vector<item *> pre_items;

    // Lectura de archivos e importación de datos
    import_Items(pre_items);

    main_menu(&squad_list, &backpack_list, &station_list, &fallen_soldiers_list, pre_items, &zgroups_list, &fallen_zombie_list);

    return 0;
}