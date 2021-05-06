#include "../Utils.cpp"
#include "UserAPI.h"
#include "User.h"

std::string UserAPI::Create(const std::map<std::string, std::string> &data, SQLWrapper &db) {
    User::AddUser();
    return sha256(data.find("password")->second);
}

std::string UserAPI::Get(const std::map<std::string, std::string> &data, SQLWrapper &db) {
    return "";
}
std::string UserAPI::Update(const std::map<std::string, std::string> &data, SQLWrapper &db) {
    return "";
}
std::string UserAPI::Delete(const std::map<std::string, std::string> &data, SQLWrapper &db) {
    return "";
}


/*
 * const std::string &f_name, const std::string &s_name, const std::string &user_patronymic,
                   char user_form_educational, bool user_hostel, const std::string &user_stud_card,
                   const std::string &user_avatar, const std::string &user_status,
                   const std::string &user_record_book, int user_role, int user_role_university,
                   const std::string &user_login, const std::string &user_password, int group_id
 */