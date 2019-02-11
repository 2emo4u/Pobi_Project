#include "VehicleRepository.h"
#include "Vehicle.h"
#include <algorithm>

using namespace std;

VehicleRepository::VehicleRepository() {};

VehicleRepository::~VehicleRepository(){};

bool VehicleRepository::addVehicle(VehiclePtr vehicle) {
    if(find(vehicleslist.begin(), vehicleslist.end(), vehicle)  == vehicleslist.end()){
        vehicleslist.push_back(vehicle);
        return true;
    }
    return false;
}

bool VehicleRepository::removeVehicle(VehiclePtr vehicle) {
    auto it = find(vehicleslist.begin(), vehicleslist.end(), vehicle);
    if(it != vehicleslist.end()) {
        vehicleslist.erase(it);
        return true;
    }
    return false;
}

VehiclePtr VehicleRepository::getVehicle(int index) {
    if(index >= 0 && index < vehicleslist.size()) {
        return vehicleslist[index];
    }
    return nullptr;
}

string VehicleRepository::vehicleReport() {
    string vehicleReport;
    if(vehicleslist.empty()) vehicleReport.append("Brak pojazdow w repozytorium\n");
    for(const auto &vehicle:vehicleslist) {
        vehicleReport.append(vehicle->vehicleinfo()).append("\n");
    }
    return vehicleReport;
}