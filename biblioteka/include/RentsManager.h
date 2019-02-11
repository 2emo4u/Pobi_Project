#ifndef RENTSMANAGER_H
#define RENTSMANAGER_H

#include <memory>

class RentsRepository;
class ClientRepository;
class VehicleRepository;
class Rent;
class Client;
#include "Vehicle.h"

using namespace std;

typedef shared_ptr < RentsRepository > RentsRepositoryPtr;
typedef shared_ptr < ClientRepository > ClientRepositoryPtr;
typedef shared_ptr < VehicleRepository > VehicleRepositoryPtr;
typedef shared_ptr < Rent > RentPtr;
typedef shared_ptr < Client > ClientPtr;
typedef shared_ptr < Vehicle > VehiclePtr;

class RentsManager {
private:
    RentsRepositoryPtr rentsRepository;
    ClientRepositoryPtr clientRepository;
    VehicleRepositoryPtr vehicleRepository;
    RentPtr rent;
    ClientPtr client;
    VehiclePtr vehicle;


public:
    RentsManager(RentsRepositoryPtr, ClientRepositoryPtr, VehicleRepositoryPtr);

    virtual ~RentsManager();

    void RentVehicle(int c_index, int v_index);

    void returnVehicle(int v_index);

    string getAllClientRents(int c_index);

    string checkClientRentBallance(int c_index);

    void changeClientType();
};


#endif /* RENTSMANAGER_HPP */
