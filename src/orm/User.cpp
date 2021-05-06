#include "../../include/orm/Wrapper.h"
#include <iostream>
#include "../../include/orm/utils.hpp"
#include "../../include/orm/User.h"


int User::AddUserRegistration(SQLWrapper &db, const std::string &f_name, const std::string &s_name,
                               const std::string &user_patronymic, const std::string &user_login,
                               const std::string &user_password, int group_id, int user_role) {
    if (SearchLogin(db, user_login)) {
        return REPEAT_LOGIN;
    }
    if (check_existence("\"group\"", "id", group_id)) {
        throw std::length_error("ERROR: FIELD NOT FOUND ");
    }

    db << "INSERT INTO student (first_name, second_name, patronymic,"
          " role, login, password, deleted, group_id, date_registration) values ('"
    << f_name << "', '"
    << s_name << "', '"
    << user_patronymic << "', '"
    << user_role << "', '"
    << user_login << "', '"
    << user_password << "', "
    << "false" << ", '"
    << group_id <<
    "', to_timestamp(" << time(nullptr) << ")) returning id;";
    db.exec();

    return db.get_int(0);
}

void User::DeleteUser(SQLWrapper &db, int user_id) {
    if (check_existence("student", "id", user_id)) {
        throw std::length_error("ERROR: FIELD NOT FOUND ");
    }
    db << "UPDATE student SET deleted = true WHERE id = " << user_id << ";";
    db.exec();
}

User User::GetUser(SQLWrapper &db,int user_id) {
    if (check_existence("student", "id", user_id)) {
        throw std::length_error("ERROR: FIELD NOT FOUND ");
    }
    db << "SELECT * FROM student WHERE id = " << user_id << ";";
    db.exec();
    User result(db.get_str(0),
                db.get_str(1),
                db.get_str(2),
                db.get_str(3),
                db.get_bool(4),
                db.get_str(5),
                db.get_str(6),
                db.get_str(7),
                db.get_str(8),
                db.get_int(9),
                db.get_int(10),
                db.get_str(11),
                db.get_str(12),
                db.get_bool(13),
                db.get_int(14),
                db.get_int(15),
                db.get_time_t(16));
    return result;
}

bool User::SearchLogin(SQLWrapper &db, const std::string& login) {
    db << "SELECT login FROM student WHERE login = '" << login << "';";
    db.exec();
    return db.count_tuples() > 0;
}

void User::UpdateUserExtra(SQLWrapper &db, int user_id, char user_form_educational, bool user_hostel,
                          const std::string &user_stud_card, const std::string &user_avatar,
                          const std::string &user_status, const std::string &user_record_book,
                          int user_role_university) {
    if (check_existence("student", "id", user_id)) {
        throw std::length_error("ERROR: FIELD NOT FOUND ");
    }

    db << "UPDATE student SET form_educational = '" << user_form_educational
    << "', hostel = '" << user_hostel
    << "', stud_card = '" << user_stud_card
    << "', avatar = '" << user_avatar
    << "', status = '"<< user_status
    <<"', record_book = '" << user_record_book
    <<"', role_university = " << user_role_university << " WHERE id = " << user_id << ";";
    db.exec();
}
