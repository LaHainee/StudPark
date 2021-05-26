#ifndef PROJECT_DEADLINE_H
#define PROJECT_DEADLINE_H

#include <iostream>
#include "Wrapper.h"

class Deadline {
public:
    explicit Deadline(
            int deadlines_id,
            const std::string &_name,
            const std::string &date_deadline_user,
            int subject_id,
            int _group_id) :
            id(deadlines_id),
            name(_name),
            date_deadline(date_deadline_user),
            subject(subject_id),
            group_id(_group_id) {}
    static int AddDeadline(SQLWrapper &db, const std::string &name, int subject_id, const std::string &date_deadline_user);
    static void DeleteDeadline(SQLWrapper &db, int deadline_id);
    static std::vector<Deadline> GetDeadlines(SQLWrapper &db, int group_id);
    static Deadline GetDeadlineById(SQLWrapper &db, int deadline_id);

    int id;
    std::string name;
    std::string date_deadline;
    int subject;
    int group_id;
};

#endif // PROJECT_DEADLINE_H
