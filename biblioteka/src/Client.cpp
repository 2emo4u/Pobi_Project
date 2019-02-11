#include "Client.h"
#include "Rent.h"

using namespace std;

Client::Client()
        :firstname{"Imie"}, lastname{"Nazwisko"}, personalID{"PESEL"}, turnover{0.0} {
    changeClientType(Basic);
}

Client::Client(const string &firstname, const string &lastname, const string &personalID,
               const string &street, const string &number, enum types typ)
        :firstname{firstname}, lastname{lastname}, personalID{personalID}, typ{typ}, turnover{0.0} {
    registeredAddress.setStreet(street);
    registeredAddress.setNumber(number);
    changeClientType(typ);
}

Client::~Client() {}

string Client::getFirstname() const {
    return firstname;
}

void Client::setFirstname(const string &fname) {
    firstname = fname;
}

string Client::getLastname() const {
    return lastname;
}

void Client::setLastname(const string &lname) {
    lastname = lname;
}

string Client::getPersonalID() const {
    return personalID;
}

double Client::getRabate() const {
    return clientType->getDiscount(turnover);
}

int Client::getAmountVehicles() const {
    return amountVehicles;
}

double Client::getTurnover() const {
    return turnover;
}

void Client::setTurnover(double tover) {
    turnover += tover;
}

void Client::setRegisteredAddress(const string &myStreet, const string &streetNumber) {
    registeredAddress.setStreet(myStreet);
    registeredAddress.setNumber(streetNumber);
}


string Client::clientinfo() {
    string clientinfo;
    clientinfo.append( firstname ).append( " " ).append( lastname ).append( " " ).append( personalID ).append( " " )
            .append( registeredAddress.getStreet() ).append( " " ).append( registeredAddress.getNumber() ).append( "\n" )
            .append( clientType->getClientType() );
    return clientinfo;
}

string Client::RentsInfo(){
    string rents;
    rents.append("Dane dla ").append(clientinfo()).append(":\n")
            .append("-------------------------------------\n");
    if (rentslist.size() == 0) {
        rents.append("Klient nic nie wypozycza\n");
    }
    else {
        for (RentPtr rent:rentslist) {
            rents.append(rent->rentinfo()).append("\n")
            .append("------------\n");
        }
    }
    return rents;
}

bool Client::addVehicleRent(RentPtr vehicleRent) {
    for (RentPtr rent:rentslist) {
        if (rent == vehicleRent) {
            return false;
        }
    }
    rentslist.push_back(vehicleRent);
    amountVehicles--;
    return true;
}

bool Client::removeVehicleRent(RentPtr vehicleRent) {
    list < RentPtr >::iterator it;
    for (it = rentslist.begin(); it != rentslist.end(); ++it) {
        if (*it == vehicleRent) {
            rentslist.remove (vehicleRent);
            amountVehicles++;
            return true;
        }
    }
    return false;
}

void Client::changeClientType(types typ) {
    if (typ == Basic) clientType = make_shared < ClientBasic > ();
    if (typ == Standard) clientType = make_shared < ClientStandard > ();
    if (typ == Premium) clientType = make_shared < ClientPremium > ();
    amountVehicles = clientType->getAmountOfVehicles();
}

