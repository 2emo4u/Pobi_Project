#ifndef CAR_H
#define CAR_H

#include "MotorVehicle.h"

using namespace std;

enum seg{A, B, C, D, E};

class Car : public MotorVehicle {
private:
    seg segment;

public:
    Car(const std::string &id, const string marka, const int baseRentPrice, const int engineDisplacement, enum seg segment);

    virtual ~Car();

    char getSegment();

    double getPrice() override;

    double segmentMultipler();

    std::string vehicleinfo() override;
};


#endif /* CAR_H */
