#include "ClientTypes.h"

using namespace std;

string ClientTypes::getClientType() {
    string clientType;
    clientType.append( "Typ klienta: ");
    return clientType;
}

ClientBasic::ClientBasic() {
}

ClientBasic::~ClientBasic() {
}

int ClientBasic::getAmountOfVehicles() {
    return 1;
}

string ClientBasic::getClientType() {
    return ClientTypes::getClientType().append("Basic");
}

double ClientBasic::getDiscount(double turnover) {
    return 1.0;
}

ClientStandard::ClientStandard() {
}

ClientStandard::~ClientStandard() {
}

int ClientStandard::getAmountOfVehicles() {
    return 4;
}

string ClientStandard::getClientType() {
    return ClientTypes::getClientType().append("Standard");
}

double ClientStandard::getDiscount(double turnover) {
    if (turnover <= 1000.0) return 1.0;
    if (turnover > 1000.0 && turnover <= 3000.0) return 0.95;
    if (turnover > 3000.0) return 0.9;
}

ClientPremium::ClientPremium() {
}

ClientPremium::~ClientPremium() {
}

int ClientPremium::getAmountOfVehicles() {
    return 10;
}

string ClientPremium::getClientType() {
    return ClientTypes::getClientType().append("Premium");
}

double ClientPremium::getDiscount(double turnover) {
    if (turnover >= 5000.0) return 0.5;
    return turnover / 10000.0 + 1.0;
}