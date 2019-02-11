#ifndef CLIENT_H
#define CLIENT_H


#include <string>
#include <list>
#include <memory>
#include "Address.h"
#include "ClientTypes.h"

using namespace std;

class Rent;

typedef shared_ptr < ClientTypes > ClientTypesPtr;
typedef shared_ptr < Rent > RentPtr;

enum types {Basic, Standard, Premium};

class Client {
private:
    string firstname;
    string lastname;
    const std::string personalID;
    types typ;
    double turnover;
    int amountVehicles;
    Address registeredAddress;
    ClientTypesPtr clientType;
    list < RentPtr > rentslist;

public:
    Client();

    Client(const std::string &firstname, const std::string &lastname, const std::string &personalID,
           const std::string &street, const std::string &number,
           enum types typ);

    virtual ~Client();

    string getFirstname() const;

    void setFirstname(const string &fname);

    string getLastname() const;

    void setLastname(const string &lname);

    string getPersonalID() const;

    double getRabate() const;

    int getAmountVehicles() const;

    double getTurnover() const;

    void setTurnover(double tover);

    void setRegisteredAddress(const string &street, const string &streetNumber);

    string clientinfo();

    string RentsInfo();

    bool addVehicleRent(RentPtr vehicleRent);

    bool removeVehicleRent(RentPtr vehicleRent);

    void changeClientType(types typ);
};


#endif /* CLIENT_H */
