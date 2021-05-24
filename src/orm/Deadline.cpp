#include "Deadline.h"
#include "Wrapper.h"

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

std::vector<Deadline> Deadline::GetDeadlines(SQLWrapper &db, int group_id) {
    db << "SELECT deadline.id, name, subject_id, time_deadline FROM deadline INNER JOIN subject ON subject.id = deadline.subject_id WHERE subject.group_id = " << group_id << ";";
    db.exec();
    int i = 0;
    std::vector<Deadline> result;
    while (db.count_tuples() > i) {
        Deadline request(
                db.get_int(0, i),
                db.get_str(1, i),
                db.get_str(2,i),
                db.get_int(3, i));
        result.push_back(request);
        i++;
    }
    return result;
}