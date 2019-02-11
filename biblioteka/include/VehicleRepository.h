#ifndef VEHICLEREPOSITORY_H
#define VEHICLEREPOSITORY_H

#include <string>
#include <vector>
#include <memory>

using namespace std;

class Vehicle;

typedef shared_ptr < Vehicle > VehiclePtr;

class VehicleRepository {
private:
    vector < VehiclePtr > vehicleslist;

public:
    VehicleRepository();

    virtual ~VehicleRepository();

    bool addVehicle(VehiclePtr vehicle);

    bool removeVehicle(VehiclePtr vehicle);

    VehiclePtr getVehicle(int index);

    string vehicleReport();
};


#endif /* VEHICLEREPOSITORY_H */
