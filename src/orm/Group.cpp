#include "../../include/orm/Group.h"
#include "../../include/orm/Wrapper.h"
#include "../../include/orm/utils.hpp"
#include "../../include/orm/Student.h"

int Group::AddGroup(SQLWrapper &db, const std::string &user_faculty, int user_number_departament, int user_semester,
        int user_group_number, const std::string &education_level, const std::string &join_code, time_t start_week) {

    db << "INSERT INTO \"group\" (faculty, number_departament, semester,"
          " group_number, education_level, start_week, join_code) values ('"
            << user_faculty << "', "
            << user_number_departament << ", "
            << user_semester << ", "
            << user_group_number << ", '"
            << education_level << "', to_timestamp("<< start_week << "), '"
            << join_code << "') returning id;";
    db.exec();

    return db.get_int(0);
}

// TODO(A1i5k): May be delete
//void Group::DeleteGroup(SQLWrapper &db, int group_id) {
//    if (check_existence("\"group\"", "id", group_id)) {
//        throw std::length_error("ERROR: FIELD NOT FOUND ");
//    }
//    db << "UPDATE \"group\" SET deleted = true WHERE id = " << group_id << "; SELECT setval('id', 0);";
//    db << "UPDATE \"group\" SET id = "<< group_id << " WHERE id = " << group_id << "; SELECT setval('group_id_seq', 1) FROM \"group\" ;";
//    db.exec();
//}

Group Group::GetGroupById(SQLWrapper &db, int group_id) {
    if (check_existence("\"group\"", "id", group_id)) {
        throw std::length_error("ERROR: FIELD group.id NOT FOUND ");
    }

    db << "SELECT * FROM \"group\" WHERE id = '" << group_id << "';";
    db.exec();
    Group result(
            db.get_int(0),
            db.get_str(1),
            db.get_int(2),
            db.get_int(3),
            db.get_int(4),
            db.get_str(5),
            db.get_str(6),
            db.get_time_t(7));
    return result;
}

std::vector<Student> Group::GetMembers(SQLWrapper &db, int group_id) {
    if (check_existence("\"group\"", "id", group_id)) {
        throw std::length_error("ERROR: FIELD group.id NOT FOUND ");
    }

    db << "SELECT * FROM student WHERE group_id = '" << group_id << "' ORDER BY second_name;";
    db.exec();
    int i = 0;
    std::vector<Student> result;
    while (db.count_tuples() > i) {
        Student request(db.get_str(0, i),
                       db.get_str(1, i),
                       db.get_str(2, i),
                       db.get_bool(3, i),
                       db.get_str(4, i),
                       db.get_str(5, i),
                       db.get_str(6, i),
                       db.get_str(7, i),
                       db.get_int(8, i),
                       db.get_int(9, i),
                       db.get_str(10, i),
                       db.get_str(11, i),
                       db.get_bool(12, i),
                       db.get_int(13, i),
                       db.get_int(14, i),
                       db.get_time_t(15, i),
                       db.get_int(16, i),
                        db.get_bool(17, i));
        result.push_back(request);
        i++;
    }
    return result;
}

int Group::GetGroupByJoinCode(SQLWrapper &db, const std::string &join_code) {
    db << "SELECT id FROM \"group\" WHERE join_code = '" << join_code << "';";
    db.exec();
    return db.get_int(0);
}

std::vector<Student> Group::GetPostNotificationSubscribers(SQLWrapper &db, int id) {
    if (check_existence("\"group\"", "id", id)) {
        throw std::length_error("ERROR: FIELD group.id NOT FOUND ");
    }

    db << "SELECT * FROM student WHERE group_id = '" << id << "' AND notification = 'true';";
    db.exec();
    int i = 0;
    std::vector<Student> result;
    while (db.count_tuples() > i) {
        Student request(db.get_str(0, i),
                        db.get_str(1, i),
                        db.get_str(2, i),
                        db.get_bool(3, i),
                        db.get_str(4, i),
                        db.get_str(5, i),
                        db.get_str(6, i),
                        db.get_str(7, i),
                        db.get_int(8, i),
                        db.get_int(9, i),
                        db.get_str(10, i),
                        db.get_str(11, i),
                        db.get_bool(12, i),
                        db.get_int(13, i),
                        db.get_int(14, i),
                        db.get_time_t(15, i),
                        db.get_int(16, i),
                        db.get_bool(17, i));
        result.push_back(request);
        i++;
    }
    return result;
}
