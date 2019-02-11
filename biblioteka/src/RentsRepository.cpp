#include "RentsRepository.h"
#include "Rent.h"
#include "Client.h"
#include "Vehicle.h"

#include <iostream>

using  namespace std;

RentsRepository::RentsRepository(){};

RentsRepository::~RentsRepository(){};


string RentsRepository::getClientForRentedVehicle(VehiclePtr vehicle) {
    ClientPtr clientTmp;
    for (const auto &sent:rentsrepository) {
        if (sent->getVehicle() == vehicle) {
            clientTmp = sent->getClient();
            return clientTmp->clientinfo();
        }
    }
    return "Pojazd nie byl do tej pory wypozyczany.";
}


RentPtr RentsRepository::getRentForRentedVehicle(VehiclePtr vehicle) {
    for (const auto &rent:rentsrepository) {
        if (rent->getVehicle() == vehicle) {
            return rent;
        }
    }
    return nullptr;
}

bool RentsRepository::createRent(RentPtr rental) {
    for (const auto &rent:rentsrepository)
        if (rent == rental)
            return false;
    rentsrepository.push_back(rental);
    return true;
}

bool RentsRepository::removeRent(RentPtr rental) {
    for (const auto &rent:rentsrepository) {
        if (rent == rental) {
            rentsrepository.remove(rental);
            return true;
        }
    }
    return false;
}

string RentsRepository::rentReport() const{
    string rentReport;
    if (rentsrepository.empty()) rentReport.append( "Wypozyczalnia dopiero otwarta, nikt nic nie wypozyczyl\n" );
    else {
        for (const auto &rent:rentsrepository) {
            rentReport.append( rent->totalinfo() ).append( "\n\n" );
        }
    }
    return rentReport;
}

bool RentsRepository::createArchiveRent(RentPtr rental) {
    for (const auto &rent:archiverentsrepository)
        if (rent == rental)
            return false;
    archiverentsrepository.push_back(rental);
    return true;
}

string RentsRepository::rentArchiveReport() const {
    string rentArchiveReport;
    cout<<"++++Archiwalne wypozyczenia++++"<<endl;
    if (archiverentsrepository.empty()) rentArchiveReport.append( "Nikt jeszcze nic nie wypozyczyl\n" );
    else {
        for (const auto &rent:archiverentsrepository) {
            rentArchiveReport.append("\n").append( rent->totalinfo() ).append( "\n\n" );
        }
    }
    return rentArchiveReport;
}

string RentsRepository::getAllClientRents(ClientPtr client) const {
    string getAllClientRents;
    VehiclePtr vehicleTmp;
    for (const auto &rent:archiverentsrepository) {
        if (rent->getClient()->getPersonalID() == client->getPersonalID())  {
            vehicleTmp = rent->getVehicle();
            getAllClientRents.append("Pojazdy wypozyczone przez klienta\n").append( vehicleTmp->vehicleinfo() ).append( "\n\n" );
        }
    }
    return getAllClientRents;
}