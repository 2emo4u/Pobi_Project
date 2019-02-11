#ifndef MOPE_HPP
#define MOPE_HPP

#include "MotorVehicle.h"

using namespace std;

class Mope : public MotorVehicle {
private:

public:
    Mope(const string &id, const string marka, const int baseRentPrice, const int engineDisplacement);

    virtual ~Mope();

    virtual std::string vehicleinfo() override;
};


#endif /* MOPE_H */
