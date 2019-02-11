#include <algorithm>
#include "ClientRepository.h"

using namespace std;

ClientRepository::ClientRepository(){};

ClientRepository::~ClientRepository(){};

bool ClientRepository::createClient(ClientPtr client) {
    if(find(clientslist.begin(), clientslist.end(), client ) == clientslist.end()) {
        clientslist.push_back(client);
        return true;
    }
    return false;
}

bool ClientRepository::removeClient(ClientPtr client) {
    auto it = find(clientslist.begin(), clientslist.end(), client);
    if(it != clientslist.end()) {
        clientslist.erase(it);
        return true;
    }
    return false;
}

void ClientRepository::changeClientType(ClientPtr client, enum types type) {
    client->changeClientType(type);
}

ClientPtr ClientRepository::getClient(int index) const {
    if(index >= 0 && index < clientslist.size()) {
        return clientslist[index];
    }
    return nullptr;
}

