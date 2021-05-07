#include "../../include/orm/Wrapper.h"
#include <iostream>
#include "../../include/orm/utils.hpp"
#include "../../include/orm/Student.h"


int Student::AddStudentRegistration(SQLWrapper &db, const std::string &f_name, const std::string &s_name,
                                 const std::string &user_patronymic, const std::string &user_login,
                                 const std::string &user_password, int group_id, int user_role) {
    if (SearchLogin(db, user_login)) {
        return REPEAT_LOGIN;
    }
    if (check_existence("\"group\"", "id", group_id)) {
        throw std::length_error("ERROR: FIELD group.id NOT FOUND ");
    }

    db << "INSERT INTO student (first_name, second_name, patronymic,"
          " role, login, password, group_id, date_registration) values ('"
    << f_name << "', '"
    << s_name << "', '"
    << user_patronymic << "', '"
    << user_role << "', '"
    << user_login << "', '"
    << user_password << "', '"
    << group_id <<
    "', to_timestamp(" << time(nullptr) << ")) returning id;";
    db.exec();

    return db.get_int(0);
}

void Student::DeleteStudent(SQLWrapper &db, int user_id) {
    if (check_existence("student", "id", user_id)) {
        throw std::length_error("ERROR: FIELD student.id NOT FOUND ");
    }
    db << "UPDATE student SET deleted = true WHERE id = " << user_id << ";";
    db.exec();
}

Student Student::GetStudentById(SQLWrapper &db, int user_id) {
    if (check_existence("student", "id", user_id)) {
        throw std::length_error("ERROR: FIELD student.id NOT FOUND ");
    }
    db << "SELECT * FROM student WHERE id = " << user_id << ";";
    db.exec();
    Student result(db.get_str(0),
                   db.get_str(1),
                   db.get_str(2),
                   db.get_bool(3),
                   db.get_str(4),
                   db.get_str(5),
                   db.get_str(6),
                   db.get_str(7),
                   db.get_int(8),
                   db.get_int(9),
                   db.get_str(10),
                   db.get_str(11),
                   db.get_bool(12),
                   db.get_int(13),
                   db.get_int(14),
                   db.get_time_t(15),
                   db.get_int(16));
    return result;
}

bool Student::SearchLogin(SQLWrapper &db, const std::string& login) {
    db << "SELECT login FROM student WHERE login = '" << login << "';";
    db.exec();
    return db.count_tuples() > 0;
}

void Student::UpdateStudentExtra(SQLWrapper &db, int user_id, bool user_hostel,
                              const std::string &user_stud_card, const std::string &user_avatar,
                              const std::string &user_status, const std::string &user_record_book,
                              int user_role_university, int user_form_educational) {
    if (check_existence("student", "id", user_id)) {
        throw std::length_error("ERROR: FIELD student.id NOT FOUND ");
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

Student Student::GetStudentBySession(SQLWrapper &db, const std::string &session) {
    if (check_existence("session", "user_session", session)) {
        throw std::length_error("ERROR: FIELD session.user_session NOT FOUND ");
    }
    db << "SELECT * FROM student WHERE id = (SELECT user_id FROM session WHERE user_session = '" << session << "');";
    db.exec();
    Student result(db.get_str(0),
                   db.get_str(1),
                   db.get_str(2),
                   db.get_bool(3),
                   db.get_str(4),
                   db.get_str(5),
                   db.get_str(6),
                   db.get_str(7),
                   db.get_int(8),
                   db.get_int(9),
                   db.get_str(10),
                   db.get_str(11),
                   db.get_bool(12),
                   db.get_int(13),
                   db.get_int(14),
                   db.get_time_t(15),
                   db.get_int(16));
    return result;
}

int Student::GetIdByLoginPassword(SQLWrapper &db, const std::string &login, const std::string &password) {
    db << "SELECT id FROM student WHERE login = '" << login << "' AND password = '" << password << "';";
    db.exec();
    return db.get_int(0);
}
