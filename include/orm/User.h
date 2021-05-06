#ifndef PROJECT_USER_H
#define PROJECT_USER_H

#include <iostream>
#include "Wrapper.h"

class User {
public:
    explicit User(
        const std::string &f_name,
        const std::string &s_name,
        const std::string &user_patronymic,
        const std::string &user_form_educational,
        bool user_hostel,
        const std::string &user_stud_card,
        const std::string &user_avatar,
        const std::string &user_status,
        const std::string &user_record_book,
        int user_role,
        int user_role_university,
        const std::string &user_login,
        const std::string &user_password,
        time_t date_reg,
        bool status_delete,
        int user_id,
        int _group_id) :
        id(user_id),
        first_name(f_name),
        second_name(s_name),
        patronymic(user_patronymic),
        form_educational(user_form_educational),
        hostel(user_hostel),
        stud_card(user_stud_card),
        avatar(user_avatar),
        record_book(user_record_book),
        role(user_role),
        role_university(user_role_university),
        login(user_login),
        password(user_password),
        date_registration(date_reg),
        deleted(status_delete),
        status(user_status),
        group_id(_group_id){}
    static int AddUserRegistration(SQLWrapper &db, const std::string &f_name, const std::string &s_name,
            const std::string &user_patronymic, int user_role, const std::string &user_login,
            const std::string &user_password, int group_id);
    static void UpdateUserExta(SQLWrapper &db, int user_id, char user_form_educational, bool user_hostel,
            const std::string &user_stud_card,
            const std::string &user_avatar, const std::string &user_status,
            const std::string &user_record_book, int user_role_university);
    static void DeleteUser(SQLWrapper &db, int user_id);
    static User GetUser(SQLWrapper &db, int user_id);
    static void UpdateUser(SQLWrapper &db, int user_id, const std::string &f_name, const std::string &s_name,
                           const std::string &user_patronymic,  char user_form_educational, bool user_hostel,
                           const std::string &user_stud_card, const std::string &user_avatar,
                           const std::string &user_status, const std::string &user_record_book,
                           int user_role, int user_role_university, const std::string &user_login,
                           const std::string &user_password, time_t user_date_admission, time_t date_reg, int group_id);
    enum {
        REPEAT_LOGIN = -1
    };

    std::string first_name;
    std::string second_name;
    std::string patronymic;
    std::string form_educational;
    bool hostel;
    std::string stud_card;
    std::string avatar;
    std::string record_book;
    int role;
    int role_university;
    std::string login;
    std::string password;
    time_t date_registration;
    std::string status;
    bool deleted;
    int id;
    int group_id;
private:
    static bool SearchLogin(SQLWrapper &db, const std::string& login);
};

#endif //PROJECT_USER_H
