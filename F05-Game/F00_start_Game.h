#ifndef F00_START_GAME_H
#define F00_START_GAME_H
#include "../Sources/outools.h"
#include "../Sources/struct.h"
#include "../F03-Stations/F07_manageSquads&Groups_stations/F07.4_travelSquad_Station.h"

void start_Game(squad **squad_list, station **station_list, Zgroup **zgroup_list, soldier **fallen_soldier_list, zombie **fallen_zombie_list, bpck **backpack_list)
{

    while (isSquadListEmpty(*squad_list) == false)
    {
        travelSquad_Stations(squad_list, station_list, zgroup_list, fallen_soldier_list, fallen_zombie_list, backpack_list);
        coutf(YELLOW, "\n\nSIGAMOS CON EL JUEGO\n");
        PAUSE_TERMINAL;
        CLEAR_SCREEN;
    }

    coutf(YELLOW, "\n\nEL JUEGO ACABO\n");
    return;
}

#endif // F00_START_GAME_H