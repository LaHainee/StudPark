//
// Created by matroskin on 01.05.2021.
//

#ifndef SERVER_HANDLER_H
#define SERVER_HANDLER_H

#include <string>
#include "Response.h"
#include "Request.h"
#include "UserAPI.h"
#include "FilesAPI.h"
#include "GroupAPI.h"
#include "PostAPI.h"
#include "Utils.h"

class Transportation {
public:
    Transportation() = default;
    void choosePermission(Request request, Response& response, const std::string str);
    Response loginTransportation(Request request);

    std::shared_ptr<User> authorizationHandler(Request request);
private:
    UserAPI userApi();
    FilesAPI filesApi();
    GroupAPI groupApi();
    PostAPI postApi();

    void userTransportation(Request request, Response& response, const std::string str);
    void filesTransportation(Request request, Response& response, const std::string str);
    void groupTransportation(Request request, Response& response, const std::string str);
    void postTransportation(Request request, Response& response, const std::string str);

};

#endif //SERVER_HANDLER_H
