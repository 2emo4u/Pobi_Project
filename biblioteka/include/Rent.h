#ifndef RENT_H
#define RENT_H

#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/date_time/local_time/local_time.hpp>
#include <string>
#include <memory>
#include <ctime>
#include "Rent.h"
#include "Vehicle.h"

using namespace std;

class Client;

typedef shared_ptr < Client > ClientPtr;
typedef shared_ptr < Vehicle > VehiclePtr;
typedef shared_ptr < boost::local_time::local_date_time > local_date_timePtr;

class Rent {
private:
    ClientPtr client;
    VehiclePtr vehicle;
    local_date_timePtr rentalDateTime;
    local_date_timePtr returnDateTime;
    boost::uuids::uuid id;

public:
    Rent(ClientPtr, VehiclePtr, local_date_timePtr rentalDateTime);

    virtual ~Rent();

    ClientPtr getClient() const;

    VehiclePtr getVehicle() const;

    void setReturnDateTime(local_date_timePtr koniec);

    int rentDuration() const;

    string rentinfo() const;

    string totalinfo() const;

    double getRentalPrice() const;
};


#endif /* RENT_H */
