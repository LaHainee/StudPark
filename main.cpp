#include <string>
#include "boost/asio.hpp"
#include "server.h"

int main(int argc, char* argv[]) {
    SQLWrapper db;
    Server server(std::string(std::getenv("HOST_SERV")), std::string(std::getenv("PORT_SERV")), db);
    server.startServer();

    return 0;
}
