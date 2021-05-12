#include "Deadline.h"
#include "Wrapper.h"
#include "utils.hpp"

int Deadline::AddDeadline(SQLWrapper &db, const std::string &name, int subject_id, const std::string &date_deadline_user) {
    db << "INSERT INTO deadline (name, subject_id, time_deadline) values ('"
    << name << "', "
    << subject_id
    << ", '" << date_deadline_user << "') returning id;";
    db.exec();
    return db.get_int(0);
}

void Deadline::DeleteDeadline(SQLWrapper &db, int deadline_id) {
    db << "DELETE FROM deadline WHERE id = " << deadline_id<< ";";
    db.exec();
}

Deadline Deadline::GetDeadlines(SQLWrapper &db, int group_id, int subject_id) {
    if (check_existence("deadline", "id", group_id)) {
        throw std::length_error("ERROR: FIELD deadline.group_id NOT FOUND ");
    }
    if (check_existence("deadline", "id", subject_id)) {
        throw std::length_error("ERROR: FIELD deadline.subject_id NOT FOUND ");
    }
    db << "SELECT * FROM deadline WHERE group_id = " << group_id << "AND subject_id = " << subject_id << ";";
    db.exec();
    Deadline result(
                   db.get_int(0),
                   db.get_time_t(1),
                   db.get_int(2),
                   db.get_int(3));
    return result;
}
