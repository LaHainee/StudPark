//
// Created by matroskin on 01.05.2021.
//

#ifndef SERVER_CONNECTION_H
#define SERVER_CONNECTION_H

#include <array>
#include <iostream>
#include <memory>
#include "boost/asio.hpp"
#include "boost/bind.hpp"
#include "boost/logic/tribool.hpp"
#include "Connection.h"

#include "Transportation.h"


class ConnectionManager;
class Connection: public std::enable_shared_from_this<Connection> {
public:
    Connection(const Connection&) = delete;
    Connection& operator=(const Connection&) = delete;
    explicit Connection(boost::asio::io_service& service, ConnectionManager& manager);

    void start();
    void stop() { socket_.close();}

    boost::asio::ip::tcp::socket& socket() { return this->socket_;};s
private:
    boost::asio::ip::tcp::socket socket_;
    ConnectionManager& manager_;
    Transportation transportation_;

    std::array<char, 8192> buffer_;

    void doRead(const boost::system::error_code& e, std::size_t bytes_transferred);
    void doWrite(const boost::system::error_code& e);

};

#endif //SERVER_CONNECTION_H
