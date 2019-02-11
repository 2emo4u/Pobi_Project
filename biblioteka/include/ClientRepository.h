#ifndef CLIENTREPOSITORY_H
#define CLIENTREPOSITORY_H

#include <string>
#include <vector>
#include <memory>
#include "Client.h"

using namespace std;

typedef shared_ptr < Client > ClientPtr;

class ClientRepository {
private:
    vector < ClientPtr > clientslist;

public:
    ClientRepository();

    virtual ~ClientRepository();

    bool createClient(ClientPtr client);

    bool removeClient(ClientPtr client);

    void changeClientType(ClientPtr client, enum types type);

    ClientPtr getClient(int index) const;
};


#endif /* CLIENTREPOSITORY_HPP */
