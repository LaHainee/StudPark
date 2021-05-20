//
// Created by matroskin on 01.05.2021.
//

#ifndef SERVER_CONNECTIONMANAGER_H
#define SERVER_CONNECTIONMANAGER_H

#include <set>
#include <memory>
#include "boost/noncopyable.hpp"
#include "Connection.h"

class ConnectionManager: private boost::noncopyable {
public:
    ConnectionManager();

    void start(std::shared_ptr<Connection> connection);
    void stop(std::shared_ptr<Connection> connection);
    void stopAll();

    size_t connectionsNumber();
private:
    std::set<std::shared_ptr<Connection>> connections_;
};

#endif //SERVER_CONNECTIONMANAGER_H
