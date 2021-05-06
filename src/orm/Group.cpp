#include "../../include/orm/Group.h"
#include "../../include/orm/Wrapper.h"
#include "../../include/orm/utils.hpp"

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
    std::cout << start_week;
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
        throw std::length_error("ERROR: FIELD NOT FOUND ");
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

std::vector<int> Group::GetMembers(SQLWrapper &db, int group_id) {
    if (check_existence("\"group\"", "id", group_id)) {
        throw std::length_error("ERROR: FIELD NOT FOUND ");
    }

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

int Group::GetGroupByJoinCode(SQLWrapper &db, const std::string &join_code) {
    db << "SELECT id FROM \"group\" WHERE join_code = '" << join_code << "';";
    db.exec();
    return db.get_int(0);
}
