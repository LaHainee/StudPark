#ifndef PROJECT_DEADLINE_H
#define PROJECT_DEADLINE_H

#include <iostream>
#include "Wrapper.h"

class Deadline {
public:
    explicit Deadline(
            int deadlines_id,
            int user_id,
            int subject_id,
            time_t date_deadline_user) :
            id(deadlines_id),
            user(user_id),
            subject(subject_id),
            date_deadline(date_deadline_user){}
    static int AddDeadline(SQLWrapper &db, const std::string &name, int subject_id, const std::string &date_deadline_user);
    static void DeleteDeadline(SQLWrapper &db, int deadline_id);
    static Deadline GetDeadlines(SQLWrapper &db, int group_id, int subject_id);

    int id;
    time_t date_deadline;
    int subject;
    int user;
};

#endif //PROJECT_DEADLINE_H

