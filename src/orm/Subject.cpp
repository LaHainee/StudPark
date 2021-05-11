#include "../../include/orm/Subject.h"
#include "../../include/orm/Wrapper.h"
#include "../../include/orm/utils.hpp"

int Subject::AddSubject(SQLWrapper &db, const std::string &subject, int group_id) {

    db << "INSERT INTO subject (subject, group_id) values ('"
    << subject << "', "
    << group_id
    << ") returning id;";
    db.exec();
    return db.get_int(0);
}

void Subject::DeleteSubject(SQLWrapper &db, int subject_id) {
    db << "DELETE FROM subject WHERE id = " << subject_id << ";";
    db.exec();

}

Subject Subject::ListSubject(SQLWrapper &db, int group_id) {
    if (check_existence("subject", "group_id", group_id)) {
        throw std::length_error("ERROR: FIELD subject.group_id NOT FOUND ");
    }
    db << "SELECT * FROM subject WHERE group_id) = " << group_id << ";";
    db.exec();
    Subject result(
                   db.get_int(0),
                   db.get_str(1),
                   db.get_int(2));
    return result;
}

