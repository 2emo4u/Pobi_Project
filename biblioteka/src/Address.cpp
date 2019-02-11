#include "Address.h"

using namespace std;

Address::Address()
        :street("ulica"), number("numer") {}

Address::~Address(){}

string Address::getStreet() const {
    return street;
}

void Address::setStreet(const string &myStreet) {
    street = myStreet;
}

string Address::getNumber() const {
    return number;
}

void Address::setNumber(const string &streetNumber) {
    number = streetNumber;
}
