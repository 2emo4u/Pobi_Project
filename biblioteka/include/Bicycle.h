#ifndef BICYCLE_H
#define BICYCLE_H

#include "Vehicle.h"

using namespace std;

class Bicycle : public Vehicle {
private:

public:
    Bicycle(const std::string &id, const string marka, const int baseRentPrice);

    virtual ~Bicycle();

    virtual string vehicleinfo() override;
};


#endif /* BICYCLE_H */
