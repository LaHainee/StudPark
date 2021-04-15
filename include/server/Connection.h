#ifndef CONNECTION_H
#define CONNECTION_H
#include "Request.h"
#include "Response.h"

class Connection {
public:
    void CallAPI();
    int SendResponse();

private:
    int ListenSocket();
    int WriteSocket();
    Request request;
    Response response;
};

#endif
