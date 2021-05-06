#include "../../include/orm/Group.h"
#include "../../include/orm/Wrapper.h"
#include "../../include/orm/utils.hpp"

int Group::AddGroup(SQLWrapper &db, const std::string &user_faculty, int user_number_departament, int user_course,
        int user_group_number, const std::string &education_level, time_t start_week) {

    db << "INSERT INTO \"group\" (faculty, number_departament, course,"
          " group_number, education_level, start_week) values ('"
            << user_faculty << "', "
            << user_number_departament << ", "
            << user_course << ", "
            << user_group_number << ", '"
            << education_level << "', to_timestamp("<< start_week << ")) returning id;";
    db.exec();

    return db.get_int(0);
}

// TODO(A1i5k): May be delete
//void Group::DeleteGroup(SQLWrapper &db, int group_id) {
//    if (check_existence("\"group\"", "id", group_id)) {
//        throw std::length_error("ERROR: FIELD NOT FOUND ");
//    }
//    db << "UPDATE \"group\" SET deleted = true WHERE id = " << group_id << ";";
//    db.exec();
//}

Group Group::GetGroup(SQLWrapper &db, int group_id) {
    db << "SELECT * FROM \"group\" WHERE id = '" << group_id << "';";
    db.exec();
    Group result(
            db.get_int(0),
            db.get_str(1),
            db.get_int(2),
            db.get_int(3),
            db.get_int(4),
            db.get_str(5),
            db.get_time_t(6));
    return result;
}

std::vector<int> Group::GetMembers(SQLWrapper &db, int group_id) {
    db << "SELECT id FROM student WHERE group_id = '" << group_id << "';";
    db.exec();
    int i = 0;
    std::vector<int> result;
    while (db.count_tuples() > i) {
        result.push_back(db.get_int(0, i));
        i++;
    }
    return result;
}
