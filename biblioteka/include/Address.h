#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

using namespace std;

class Address {
private:
    string street;
    string number;

public:
    Address();

    virtual ~Address();

    std::string getStreet() const;

    void setStreet(const string &myStreet);

    std::string getNumber() const;

    void setNumber(const string &streetNumber);
};


#endif /* ADDRESS_H */
