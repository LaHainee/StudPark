#ifndef SERVER_HANDLER_H
#define SERVER_HANDLER_H

#include <string>
#include <iostream>
#include "Response.h"
#include "Request.h"

#include "FilesAPI.h"
#include "GroupAPI.h"
#include "PostAPI.h"
#include "UserAPI.h"

class Transportation {
public:
    Transportation() = default;
    void userTransportation(Request request, Response& response);

private:
    UserAPI userApi;
    FilesAPI filesApi;
    GroupAPI groupApi;
    PostAPI postApi;
    SQLWrapper sqlWrapper;
};





#endif //SERVER_HANDLER_H