#include <iostream>
#include "Client.h"
#include "RentsRepository.h"
#include "ClientRepository.h"
#include "VehicleRepository.h"
#include "Interface.h"
#include "RentsManager.h"
#include <memory>

using namespace std;

int main()
{
    shared_ptr < RentsRepository > rentsRepository = make_shared < RentsRepository > ();
    shared_ptr < ClientRepository > clientRepository = make_shared < ClientRepository > ();
    shared_ptr < VehicleRepository > vehicleRepository = make_shared < VehicleRepository > ();
    Interface interfejs(rentsRepository, clientRepository, vehicleRepository);


    return 0;
}