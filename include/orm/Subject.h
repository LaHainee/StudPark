#ifndef PROJECT_SUBJECT_H
#define PROJECT_SUBJECT_H

class Subject {
public:
    explicit Subject(
            int id_subject,
            const std::string &_subject,
            int _group_id) :
            id(id_subject),
            subject(_subject),
            group_id(_group_id) {}
    static void AddSubject(SQLWrapper &db, const std::string &subject, int group_id);
    void DeleteSubject(SQLWrapper &db, int subject_id);
    static Subject ListSubject(SQLWrapper &db, int group_id);

    int id;
    std::string subject;
    int group_id;
};

#endif //PROJECT_SUBJECT_H
