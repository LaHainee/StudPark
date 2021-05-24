#include "Transportation.h"

void Transportation::userTransportation(Request request, Response& response) {
    response.setStatus(status::NotFound);
    std::unordered_map<std::string, std::string> data_in;

    if (request.method() == "GET" && request.path() == "/") {
        response.setStatus(302);
        if (!request.cookie("session").empty()) {
            std::cout << "Redirecting to feed" << std::endl;
            response.setHeader("Location", "/feed");
        } else {
            response.setHeader("Location", "/login");
        }
        return;
    }

    if (request.method() == "GET") {
        if (request.path() == "/UserAPI/Get") {

        } else if (request.path() == "/login") {
            response = Response(userApi.Login());
        } else if (request.path() == "/feed") {
            std::unordered_map<std::string, std::string> data = request.getData();
            data["session"] = request.cookie("session");
            response = Response(postApi.Feed(data, sqlWrapper));
        } else if (request.path() == "/FilesAPI/Get") {
            data_in["session"] = request.data("session");
            data_in["id"] = request.data("id");
            response = Response(filesApi.Get(data_in, sqlWrapper));
        } else if (request.path() == "/FilesAPI/List") {

        } else if (request.path() == "/GroupAPI/Get") {

        } else if (request.path() == "/GroupAPI/ExportContacts") {
            data_in["session"] = request.data("session");
            response = Response(groupApi.ExportContacts(data_in, sqlWrapper));

        } else if (request.path() == "/PostAPI/Get") {

        } else if (request.path() == "/userAPI/Get") {

        } else if (request.path() == "/userAPI/Logout") {
            data_in["session"] = request.data("session");
            response = Response(userApi.Logout(data_in, sqlWrapper));
        } else if (request.path() == "/GroupAPI/Create") {
            std::unordered_map <std::string, std::string> data = request.getData();
            data["session"] = request.cookie("session");
            response = Response(groupApi.CreatePage(data, sqlWrapper));
        } else if (request.path() == "/signup") {
            response = Response(userApi.SignupPage());
        } else if (request.path() == "/GroupAPI/GetDeadlines") {
            std::unordered_map <std::string, std::string> data = request.getData();
            data["session"] = request.cookie("session");
            response = Response(groupApi.GetDeadlines(data, sqlWrapper));
        } else if (request.path() == "/GroupAPI/GetSubjects") {
            std::unordered_map <std::string, std::string> data = request.getData();
            data["session"] = request.cookie("session");
            response = Response(groupApi.GetSubjects(data, sqlWrapper));
        }
    }
    else if(request.method() == "POST") {
        std::cout << "POST";
        if (request.path() == "/") {
        }else if (request.path() == "/FilesAPI/Create") {
            data_in["session"] = request.dataPost("session");
            data_in["filepath"] = request.dataPost("filepath");
            response = Response(filesApi.Create(data_in, sqlWrapper));
        }else if (request.path() == "/FilesAPI/Update") {

        }else if (request.path() == "/FilesAPI/Delete") {

        }else if (request.path() == "/FilesAPI/Share") {

        }else if (request.path() == "/GroupAPI/Create") {
            std::unordered_map<std::string, std::string> data = request.getData();
            data["session"] = request.cookie("session");
            response = Response(groupApi.Create(data, sqlWrapper));
        }else if (request.path() == "/GroupAPI/Update") {

        }else if (request.path() == "/GroupAPI/Delete") {

        }else if (request.path() == "/GroupAPI/AddSubject") {
            std::unordered_map<std::string, std::string> data = request.getData();
            data["session"] = request.cookie("session");
            response = Response(groupApi.AddSubject(data, sqlWrapper));
        }else if (request.path() == "/GroupAPI/AddDeadline") {
            std::unordered_map<std::string, std::string> data = request.getData();
            data["session"] = request.cookie("session");
            std::cout << "DATA SIZE " << data.size() << std::endl;
            response = Response(groupApi.AddDeadline(data, sqlWrapper));
        }else if (request.path() == "/PostAPI/Create") {
            data_in["session"] = request.dataPost("session");
            data_in["head"] = request.dataPost("head");
            data_in["body"] = request.dataPost("body");
            response = Response(postApi.Create(data_in, sqlWrapper));
        }else if (request.path() == "/PostAPI/Update") {

        }else if (request.path() == "/PostAPI/Delete") {
            data_in["session"] = request.dataPost("session");
            data_in["id"] = request.dataPost("id");
            response = Response(postApi.Delete(data_in, sqlWrapper));
        }else if (request.path() == "/PostAPI/AddPostComment") {
            data_in["session"] = request.dataPost("session");
            data_in["post"] = request.dataPost("post");
            data_in["text"] = request.dataPost("text");
            response = Response(postApi.AddPostComment(data_in, sqlWrapper));
        }else if (request.path() == "/PostAPI/DeletePostComment") {
            data_in["session"] = request.dataPost("session");
            data_in["id"] = request.dataPost("id");
            response = Response(postApi.DeletePostComment(data_in, sqlWrapper));

        }else if (request.path() == "/signup") {
            std::string data = userApi.Create(request.getData(), sqlWrapper);
            if (data.empty()) {
                response.setStatus(302);
                response.setHeader("Location", "/login");
            } else {
                response = Response(data);
            }
        }else if (request.path() == "/UserAPI/Update") {

        }else if (request.path() == "/UserAPI/Delete") {

        }else if (request.path() == "/UserAPI/Authenticate") {
            std::pair<std::string, std::string> auth = userApi.Authenticate(request.getData(), sqlWrapper);
            response = Response(auth.second);
            response.setStatus(302);
            response.setHeader("Location", "/feed");
            response.setCookie("session", auth.first);
        }else if (request.path() == "/UserAPI/AddContact") {
            data_in["session"] = request.dataPost("session");
            data_in["type"] = request.dataPost("type");
            data_in["url"] = request.dataPost("url");
            data_in["stealth"] = request.dataPost("stealth");
            response = Response(userApi.AddContact(data_in, sqlWrapper));
        }
    }
}
