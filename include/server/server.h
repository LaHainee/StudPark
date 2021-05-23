#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

#include "boost/asio.hpp"
#include <string>
#include "ConnectionManager.h"

namespace async = boost::asio;
namespace net   = async::ip;

class Server: private boost::asio::noncopyable {
public:
    Server(const std::string& addr, const std::string& port);
    void startServer();
    void stopServer();

private:
    void accept(const boost::system::error_code& error);
    void stop();

    ConnectionManager manager_;

    async::io_service service_;
    net::tcp::acceptor acceptor_;

    std::shared_ptr<Connection> connection_;
};

#endif //SERVER_SERVER_H
