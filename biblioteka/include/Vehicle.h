#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

using namespace std;

class Vehicle {
private:
    const string id;
    string marka;
    int baseRentPrice;
    bool hire;

public:
    Vehicle(const string &id, const string marka, const int baseRentPrice);

    virtual ~Vehicle();

    bool getHire();

    void setHire(bool hiring);

    virtual double getPrice();

    void setPrice(double price);

    virtual string vehicleinfo();
};


#endif /* VEHICLE_H */
