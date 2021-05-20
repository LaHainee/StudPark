#include "Subject.h"
#include "Wrapper.h"
#include "utils_wrapper.hpp"

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

std::vector<Subject> Subject::ListSubject(SQLWrapper &db, int group_id) {
    if (check_existence(db, "subject", "group_id", group_id)) {
        throw std::length_error("ERROR: FIELD subject.group_id NOT FOUND");
    }
    db << "SELECT * FROM subject WHERE group_id = " << group_id << ";";
    db.exec();
    int i = 0;
    std::vector<Subject> result;
    while (db.count_tuples() > i) {
    Subject request(
                   db.get_int(0, i),
                   db.get_int(1, i),
                   db.get_str(2, i));
        result.push_back(request);
        i++;
    }
    return result;
}

