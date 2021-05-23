#include "Transportation.h"

void Transportation::userTransportation(Request request, Response& response) {
    response.setStatus(status::NotFound);
    std::unordered_map<std::string, std::string> data_in;
    if (request.method() == "GET") {
        if (request.path() == "/") {

        } else if (request.path() == "/UserAPI/Get") {

        } else if (request.path() == "/FilesAPI/Get") {
            data_in["session"] = request.data("session");
            data_in["id"] = request.data("id");
            response = Response(filesApi.Get(data_in, sqlWrapper));
        }  else if (request.path() == "/FilesAPI/List") {

        }else if (request.path() == "/GroupAPI/Get") {

        }else if (request.path() == "/GroupAPI/ExportContacts") {
            data_in["session"] = request.data("session");
            response = Response(groupApi.ExportContacts(data_in, sqlWrapper));

        }else if (request.path() == "/PostAPI/Get") {
//            response = Response("<a> /PostAPI/Get  --> OK </a>");

        }else if (request.path() == "/userAPI/Get") {

        }else if (request.path() == "/userAPI/Logout") {
            data_in["session"] = request.data("session");
            response = Response(userApi.Logout(data_in, sqlWrapper));
        }
        else if(request.method() == "POST")
        {
            if (request.path() == "/") {
            }else if (request.path() == "/FilesAPI/Create") {
                data_in["session"] = request.dataPost("session");
                data_in["filepath"] = request.dataPost("filepath");
                response = Response(filesApi.Create(data_in, sqlWrapper));
            }else if (request.path() == "/FilesAPI/Update") {

            }else if (request.path() == "/FilesAPI/Delete") {

            }else if (request.path() == "/FilesAPI/Share") {


            }else if (request.path() == "/GroupAPI/Create") {
                data_in["session"] = request.dataPost("session");
                data_in["user_faculty"] = request.dataPost("user_faculty");
                data_in["user_number_department"] = request.dataPost("user_number_department");
                data_in["user_semester"] = request.dataPost("user_semester");
                data_in["user_group_number"] = request.dataPost("user_group_number");
                data_in["education_level"] = request.dataPost("education_level");
                data_in["head_f_name"] = request.dataPost("head_f_name");
                data_in["head_s_name"] = request.dataPost("head_s_name");
                data_in["head_patronymic"] = request.dataPost("head_patronymic");
                data_in["head_user_login"] = request.dataPost("head_user_login");
                data_in["head_password"] = request.dataPost("head_password");

                response = Response(groupApi.Create(data_in, sqlWrapper));
            }else if (request.path() == "/GroupAPI/Update") {

            }else if (request.path() == "/GroupAPI/Delete") {

            }else if (request.path() == "/GroupAPI/AddSubject") {
                data_in["session"] = request.dataPost("session");
                data_in["subject"] = request.dataPost("subject");
                response = Response(groupApi.AddSubject(data_in, sqlWrapper));
            }else if (request.path() == "/GroupAPI/AddDeadline") {
                data_in["session"] = request.dataPost("session");
                data_in["name"] = request.dataPost("name");
                data_in["subject"] = request.dataPost("subject");
                data_in["time"] = request.dataPost("time");
                response = Response(groupApi.AddDeadline(data_in, sqlWrapper));

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

            }else if (request.path() == "/UserAPI/Create") {
                data_in["s_name"] = request.dataPost("s_name");
                data_in["f_name"] = request.dataPost("f_name");
                data_in["user_patronymic"] = request.dataPost("user_patronymic");
                data_in["user_login"] = request.dataPost("user_login");
                data_in["password"] = request.dataPost("password");
                data_in["join_code"] = request.dataPost("join_code");
                response = Response(userApi.Create(data_in, sqlWrapper));
            }else if (request.path() == "/UserAPI/Update") {

            }else if (request.path() == "/UserAPI/Delete") {

            }else if (request.path() == "/UserAPI/Authenticate") {
                data_in["login"] = request.dataPost("login");
                data_in["password"] = request.dataPost("password");
                response = Response(userApi.Authenticate(data_in, sqlWrapper));
            }else if (request.path() == "/UserAPI/AddContact") {
                data_in["session"] = request.dataPost("session");
                data_in["type"] = request.dataPost("type");
                data_in["url"] = request.dataPost("url");
                data_in["stealth"] = request.dataPost("stealth");
                response = Response(userApi.AddContact(data_in, sqlWrapper));

            }
        }
    }


}