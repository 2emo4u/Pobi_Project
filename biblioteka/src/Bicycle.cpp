#include "Bicycle.h"

using namespace std;

Bicycle::Bicycle(const string &id, const string marka, const int baseRentPrice)
        :Vehicle{id, marka, baseRentPrice} {}

Bicycle::~Bicycle() {}

string Bicycle::vehicleinfo() {
    string vehicleinfo;
    vehicleinfo.append("Typ: Rower\n").append(Vehicle::vehicleinfo());
    return vehicleinfo;
}