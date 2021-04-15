#ifndef REQUEST_H
#define REQUEST_H
#include <vector>
#include <iostream>

class Request {
public:
    std::string ParseCookie();
    int ErrorChecking();
    enum ResponseTypes{
        WEBPAGE,
        DOWNLOAD
    };
private:
    std::vector <std::string> cookie_out;
    std::vector <std::string> cookie_in;
    // API::Response Response_api
};

#endif
