#ifndef INTERFACE_H
#define INTERFACE_H

#include <memory>

class RentsRepository;
class ClientRepository;
class VehicleRepository;

typedef std::shared_ptr < RentsRepository > RentsRepositoryPtr;
typedef std::shared_ptr < ClientRepository > ClientRepositoryPtr;
typedef std::shared_ptr < VehicleRepository > VehicleRepositoryPtr;

class Interface{
private:          
    RentsRepositoryPtr rentsRepository;
    ClientRepositoryPtr clientRepository;
    VehicleRepositoryPtr vehicleRepository;

public:
    Interface(RentsRepositoryPtr, ClientRepositoryPtr, VehicleRepositoryPtr);
    virtual ~Interface();
};

#endif /*INTERFACE_H*/
