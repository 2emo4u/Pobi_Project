#ifndef MOTORVEHICLE_H
#define MOTORVEHICLE_H

#include "Vehicle.h"

using namespace std;

class MotorVehicle : public Vehicle {
    const int engineDisplacement;

public:
    MotorVehicle(const string &id, const string marka, const int baseRentPrice, const int engineDisplacement);

    virtual ~MotorVehicle();

    double getMultipler();

    virtual double getPrice() override;

    virtual std::string vehicleinfo() override;
};


#endif /* MOTORVEHICLE_H */
