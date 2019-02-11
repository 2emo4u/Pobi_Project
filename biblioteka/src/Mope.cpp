#include "Mope.h"
#include <string>

using namespace std;

Mope::Mope(const string &id, const string marka, const int baseRentPrice, const int engineDisplacement)
        :MotorVehicle{id, marka, baseRentPrice, engineDisplacement} {}

Mope::~Mope() {}

string Mope::vehicleinfo() {
    string vehicleinfo;
    vehicleinfo.append("Typ: Motorower\n").append(MotorVehicle::vehicleinfo());
    return vehicleinfo;
}