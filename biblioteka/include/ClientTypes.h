#ifndef CLIENTTYPES_H
#define CLIENTTYPES_H

#include <string>

using namespace std;

class ClientTypes {
private:
    int vehiclesAmount;

public:
    virtual int getAmountOfVehicles() = 0;

    virtual std::string getClientType();

    virtual double getDiscount(double turnover) = 0;

};

class ClientBasic : public ClientTypes {
private:

public:
    ClientBasic();

    virtual ~ClientBasic();

    virtual int getAmountOfVehicles() override;

    virtual std::string getClientType() override;

    virtual double getDiscount(double turnover) override;
};

class ClientStandard : public ClientTypes {
private:

public:
    ClientStandard();

    virtual ~ClientStandard();

    virtual int getAmountOfVehicles() override;

    virtual std::string getClientType() override;

    virtual double getDiscount(double turnover) override;
};

class ClientPremium  : public ClientTypes {
private:

public:
    ClientPremium();

    virtual ~ClientPremium();

    virtual int getAmountOfVehicles() override;

    virtual std::string getClientType() override;

    virtual double getDiscount(double turnover) override;
};


#endif /* CLIENTTYPES_HPP */
