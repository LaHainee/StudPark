#ifndef PROJECT_DEADLINE_H
#define PROJECT_DEADLINE_H

#include <iostream>
#include "Wrapper.h"

class Deadline {
public:
    explicit Deadline(
            int deadlines_id,
            const std::string &_name,
            int subject_id,
            time_t date_deadline_user) :
            id(deadlines_id),
            name(_name),
            subject(subject_id),
            date_deadline(date_deadline_user){}
    static int AddDeadline(SQLWrapper &db, const std::string &name, int subject_id, time_t date_deadline_user);
    static void DeleteDeadline(SQLWrapper &db, int deadline_id);
    static Deadline GetDeadlines(SQLWrapper &db, int subject_id);

    int id;
    std::string name;
    int subject;
    time_t date_deadline;
};

#endif //PROJECT_DEADLINE_H

