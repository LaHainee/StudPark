#include "../../include/api/API.h"

API::API() {
    logger = new Logger();
}

API::~API() {
    delete logger;
}

API::Response::Response(std::string &b, int t, int s) :
    body(std::move(b)), 
    type(t), 
    status(s) {}