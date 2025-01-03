#ifndef F06_MANAGEROUTES_STATIONS_H
#define F06_MANAGEROUTES_STATIONS_H

// Include necessary headers
#include <vector>
#include <string>

// Function declarations
void addStation(const std::string &stationName);
void removeStation(const std::string &stationName);
std::vector<std::string> getStations();

#endif // F06_MANAGEROUTES_STATIONS_H