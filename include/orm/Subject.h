#ifndef PROJECT_SUBJECT_H
#define PROJECT_SUBJECT_H

#include <iostream>
#include "Wrapper.h"

class Subject {
public:
    explicit Subject(
            int id_subject,
            int _group_id,
            const std::string &_subject) :
            id(id_subject),
            subject(_subject),
            group_id(_group_id) {}
    static int AddSubject(SQLWrapper &db, const std::string &subject, int group_id);
    static void DeleteSubject(SQLWrapper &db, int subject_id);
    static std::vector<Subject> ListSubject(SQLWrapper &db, int group_id);

    int id;
    int group_id;
    std::string subject;
};

#endif //PROJECT_SUBJECT_H
