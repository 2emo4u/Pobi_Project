#include "MotorVehicle.h"
#include "Vehicle.h"

using namespace std;

MotorVehicle::MotorVehicle(const string &id, const string marka, const int baseRentPrice, const int engineDisplacement)
        :Vehicle{id, marka, baseRentPrice}, engineDisplacement{engineDisplacement} {}

MotorVehicle::~MotorVehicle() {}

double MotorVehicle::getMultipler() {
    if (engineDisplacement < 1000) return 1.0;
    else if(engineDisplacement>=1000&&engineDisplacement<=1250)
        return 1.1;
    else if(engineDisplacement>1250&&engineDisplacement<1500)
        return 1.2;
    else if(engineDisplacement>=1500&&engineDisplacement<1750)
        return 1.3;
    else if(engineDisplacement>=1750&&engineDisplacement<2000)
        return 1.4;
    else if(engineDisplacement>=2000)
        return 1.5;
}

double MotorVehicle::getPrice() {
    return Vehicle::getPrice() * getMultipler();
}

string MotorVehicle::vehicleinfo() {
    string vehicleinfo;
    vehicleinfo.append("Pojemnosc silnika: ").append(to_string(engineDisplacement)).append("\n")
            .append(Vehicle::vehicleinfo());
    return vehicleinfo;
}