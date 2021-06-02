#ifndef SERVER_HANDLER_H
#define SERVER_HANDLER_H

#include <string>
#include <iostream>
#include "Response.h"
#include "Request.h"

#include "GroupAPI.h"
#include "PostAPI.h"
#include "UserAPI.h"

class Transportation {
public:
    Transportation() = default;
    void userTransportation(Request request, Response& response);

private:
    SQLWrapper sqlWrapper;
    UserAPI userApi(sqlWrapper);
    GroupAPI groupApi(sqlWrapper);
    PostAPI postApi(sqlWrapper);

};





#endif //SERVER_HANDLER_H