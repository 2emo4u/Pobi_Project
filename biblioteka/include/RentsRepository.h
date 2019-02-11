#ifndef RENTSREPOSITORY_H
#define RENTSREPOSITORY_H

#include <string>
#include <list>
#include <memory>

#include "Rent.h"
#include "Client.h"
#include "Vehicle.h"

using namespace std;

typedef shared_ptr < Rent > RentPtr;
typedef shared_ptr < Client > ClientPtr;
typedef shared_ptr < Vehicle > VehiclePtr;

class RentsRepository{
private:
    list < RentPtr > rentsrepository;
    list < RentPtr > archiverentsrepository;

public:
    RentsRepository();

    virtual ~RentsRepository();

    string getClientForRentedVehicle(VehiclePtr vehicle);

    RentPtr getRentForRentedVehicle(VehiclePtr vehicle);

    bool createRent(RentPtr rental);

    bool removeRent(RentPtr rental);

    string rentReport() const;

    bool createArchiveRent(RentPtr rental);

    string rentArchiveReport() const;

    string getAllClientRents(ClientPtr client) const;

};


#endif /* RENTSREPOSITORY_H */
