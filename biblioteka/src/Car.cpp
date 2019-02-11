#include "Car.h"

using namespace std;

Car::Car(const string &id, const string marka, const int baseRentPrice, const int engineDisplacement, enum seg segment)
        :MotorVehicle{id, marka, baseRentPrice, engineDisplacement}, segment{segment} {}

Car::~Car() {}

double Car::getPrice() {
    return MotorVehicle::getPrice() * segmentMultipler();
}

double Car::segmentMultipler() {
    switch (segment) {
        case A:
            return 1.0;
        case B:
            return 1.1;
        case C:
            return 1.2;
        case D:
            return 1.3;
        case E:
            return 1.5;
        default:
            break;
    }
}

string Car::vehicleinfo() {
    string vehicleinfo;
    vehicleinfo.append( "Typ: Samochod\n" ).append( "Segment: " ).append( 1, (65 + segment) ).append( "\n" )
            .append(MotorVehicle::vehicleinfo());
    return vehicleinfo;
}
