#ifndef SERVER_H
#define SERVER_H
#include "Connection.h"

class Server {
public:
    void StartServer();
    void StopServer();

private:
    Connection connection;
};

#endif
