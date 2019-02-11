#include <boost/date_time/local_time/local_time.hpp>
#include "RentsManager.h"
#include "Rent.h"
#include "Client.h"
#include "Vehicle.h"
#include "RentsRepository.h"
#include "ClientRepository.h"
#include "VehicleRepository.h"

using namespace boost::local_time;
using namespace boost::posix_time;
using namespace std;

typedef shared_ptr < local_date_time > local_date_timePtr;

RentsManager::RentsManager(RentsRepositoryPtr rentsRepository, ClientRepositoryPtr clientRepository,
                           VehicleRepositoryPtr vehicleRepository)
        :rentsRepository{move(rentsRepository)}, clientRepository{move(clientRepository)},
         vehicleRepository{move(vehicleRepository)} {}

RentsManager::~RentsManager(){};

void RentsManager::RentVehicle(int c_index, int v_index) {
    client = clientRepository->getClient(c_index);
    vehicle = vehicleRepository->getVehicle(v_index);
    time_zone_ptr tz(new posix_time_zone("CET"));
    ptime pTime = second_clock::local_time() - hours(25);
    local_date_timePtr date_time = make_shared < local_date_time > (pTime, tz);
    rent = make_shared < Rent > (client, vehicle, date_time);
    if(!vehicle->getHire() && client->getAmountVehicles() > 0) {
        vehicle->getHire() == false;
        client->addVehicleRent(rent);
        vehicle->setHire(true);
        client->setTurnover(vehicle->getPrice());
        rentsRepository->createRent(rent);
    }
    else
        cout<<"Brak mozliwosci wypozyczenia \n";
}

void RentsManager::returnVehicle(int v_index) {
    vehicle = vehicleRepository->getVehicle(v_index);
    rent = rentsRepository->getRentForRentedVehicle(vehicle);
    time_zone_ptr tz(new posix_time_zone("CET"));
    ptime pTime = second_clock::local_time() + hours(8);
    local_date_timePtr date_time = make_shared < local_date_time > (pTime, tz);
    rent->setReturnDateTime(date_time);
    client->removeVehicleRent(rent);
    vehicle->setHire(false);
    rentsRepository->removeRent(rent);
    rentsRepository->createArchiveRent(rent);
    changeClientType();
}

string RentsManager::getAllClientRents(int c_index){
    string getAllClientRents;
    getAllClientRents.append( rentsRepository->getAllClientRents( clientRepository->getClient(c_index) ) ).append( "\n");
    return getAllClientRents;
}

string RentsManager::checkClientRentBallance(int c_index) {
    client = clientRepository->getClient(c_index);
    string checkClientRentBallance;
    checkClientRentBallance.append( "Bilans klienta wynosi: " ).append( to_string( client->getTurnover() ) )
            .append( "\n");
    return checkClientRentBallance;
}

void RentsManager::changeClientType() {
    if(client->getTurnover() >= 10000.0)
        clientRepository->changeClientType(client, Standard);
    if(client->getTurnover() >= 15000.0)
        clientRepository->changeClientType(client, Premium);
}
