#include "Server.h"
#include "thread"

void Server::StartServer() {
    // std::thread::hardware_concurrency() - количество ядер
    for (size_t i = 0; i < std::thread::hardware_concurrency(); ++i) {

    }
}

void Server::StopServer() {
    // stop boost.asio
}
