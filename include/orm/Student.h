#ifndef PROJECT_USER_H
#define PROJECT_USER_H

#include <iostream>
#include "Wrapper.h"

class Student {
public:
    enum Roles {
        STUDENT = 0,
        ADMIN = 2,
        LEADER = 1
    };
    enum RolesUniversity {
        STUDYING = 0,
        EXPELLED = 1,
        GRADUATED = 2,
        GAP = 3
    };
    enum FormEducational {
        FREE = 0,
        target= 1,
        PAY = 2
    };
    enum ERROR {
        REPEAT_LOGIN = -1
    };
    explicit Student(
        const std::string &f_name,
        const std::string &s_name,
        const std::string &user_patronymic,
        bool user_hostel,
        const std::string &user_stud_card,
        const std::string &user_avatar,
        const std::string &user_status,
        const std::string &user_record_book,
        int user_role,
        int user_role_university,
        const std::string &user_login,
        const std::string &user_password,
        bool status_delete,
        int user_id,
        int _group_id,
        time_t date_reg,
        int user_form_educational,
        bool _notification):
        id(user_id),
        first_name(f_name),
        second_name(s_name),
        patronymic(user_patronymic),
        hostel(user_hostel),
        stud_card(user_stud_card),
        avatar(user_avatar),
        record_book(user_record_book),
        role(user_role),
        role_university(user_role_university),
        login(user_login),
        password(user_password),
        deleted(status_delete),
        status(user_status),
        group_id(_group_id),
        date_registration(date_reg),
        form_educational(user_form_educational),
        notification(_notification){}
    static int AddStudentRegistration(SQLWrapper &db, const std::string &f_name, const std::string &s_name,
            const std::string &user_patronymic, const std::string &user_login,
            const std::string &user_password, int group_id, int user_role = STUDENT);
    static void UpdateStudentExtra(SQLWrapper &db, int user_id, bool user_hostel,
            const std::string &user_stud_card,
            const std::string &user_avatar, const std::string &user_status,
            const std::string &user_record_book, int user_role_university, int user_form_educational, bool notification);
    static void DeleteStudent(SQLWrapper &db, int user_id);
    static Student GetStudentById(SQLWrapper &db, int user_id);
    static Student GetStudentBySession(SQLWrapper &db, const std::string &session);
    static int GetIdByLoginPassword(SQLWrapper &db, const std::string &login, const std::string &password);
    static void UpdateStudent(SQLWrapper &db, int user_id, const std::string &f_name, const std::string &s_name,
                           const std::string &user_patronymic,  char user_form_educational, bool user_hostel,
                           const std::string &user_stud_card, const std::string &user_avatar,
                           const std::string &user_status, const std::string &user_record_book,
                           int user_role, int user_role_university, const std::string &user_login,
                           const std::string &user_password, time_t user_date_admission, time_t date_reg, int group_id);

    std::string first_name;
    std::string second_name;
    std::string patronymic;
    bool hostel;
    std::string stud_card;
    std::string avatar;
    std::string record_book;
    int role;
    int role_university;
    std::string login;
    std::string password;
    std::string status;
    bool deleted;
    int id;
    int group_id;
    time_t date_registration;
    int form_educational;
    bool notification;
private:
    static bool SearchLogin(SQLWrapper &db, const std::string& login);
};

#endif //PROJECT_USER_H
