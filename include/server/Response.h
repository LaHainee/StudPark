#ifndef RESPONSE_H
#define RESPONSE_H
#include "iostream"

class Response {
public:
    int ErrorChecking();
    enum ResponseTypes{
        WEBPAGE,
        DOWNLOAD
    };
private:
    // API::Response Response_api
};

#endif
