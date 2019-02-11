#include "Rent.h"
#include <boost/uuid/uuid_generators.hpp>  //generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators
#include "Client.h"
#include "Vehicle.h"


using namespace std;
using namespace boost::local_time;
using namespace boost::posix_time;
using namespace boost::uuids;


Rent::Rent(ClientPtr client, VehiclePtr vehicle, local_date_timePtr rentalDateTime)
        :client{client}, vehicle{vehicle},
         id{random_generator()()}, rentalDateTime{rentalDateTime} {
    returnDateTime.reset();
}

Rent::~Rent(){};

ClientPtr Rent::getClient() const {
    return this->client;
}

VehiclePtr Rent::getVehicle() const {
    return this->vehicle;
}

void Rent::setReturnDateTime(local_date_timePtr koniec) {
    returnDateTime = koniec;
}

int Rent::rentDuration() const {
    if (returnDateTime) {
        local_time_period period(*rentalDateTime, *returnDateTime);
        int rentDuration = period.length().hours() / 24;
        if (period.length().hours() % 24 > 0) rentDuration++;
        return rentDuration;
    }
    else return 0;
}

string Rent::rentinfo() const {
    string rentinfo;
    rentinfo.append( "Wypozyczony pojazd: " ).append( "\n" ).append( vehicle->vehicleinfo() ).append( "\n" )
            .append( "Identyfikator wypozyczenia: " ).append( to_string(id) ).append( "\n" )
            .append( "Data wypozyczenia: " ).append( rentalDateTime->to_string() ).append( "\n" )
            .append( "Czas wypozyczenia: " ).append( to_string( rentDuration() ) );
    if (returnDateTime) {   //jesli wypozyczenie sie zakonczylo
        rentinfo.append( "\n" ).append( "Data zwrotu pojazdu: " ).append( returnDateTime->to_string() ).append( "\n" )
                .append( "Sumaryczny koszt wypozyczenia: " ).append( to_string( getRentalPrice() ) );
    }
    else return rentinfo;
}

string Rent::totalinfo() const {
    string totalinfo;
    totalinfo.append( client->clientinfo() ).append( "\n" ).append( rentinfo() );
    return totalinfo;
}

double Rent::getRentalPrice() const {
    return rentDuration() *  vehicle->getPrice() *  client->getRabate();
}