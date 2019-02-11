#include "Vehicle.h"

using namespace std;

Vehicle::Vehicle(const string &id, const string marka, const int baseRentPrice)
        :id(id), marka (marka),baseRentPrice(baseRentPrice), hire{false} {}

Vehicle::~Vehicle() {}

bool Vehicle::getHire() {
    return hire;
}

void Vehicle::setHire(bool hiring) {
    hire = hiring;
}

double Vehicle::getPrice() {
    return baseRentPrice;
}

void Vehicle::setPrice(double price) {
    baseRentPrice = price;
}

string Vehicle::vehicleinfo() {
    string vehicleinfo;
    vehicleinfo.append("Numer rejestracyjny: ").append(id).append("\n")
            .append("Marka pojazdu: ").append(marka).append("\n")
            .append("Cena: ").append(to_string(baseRentPrice));
    return vehicleinfo;
}