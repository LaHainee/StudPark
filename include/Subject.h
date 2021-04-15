#ifndef C___SUBJECT_H
#define C___SUBJECT_H

class Subject {
public:
    explicit Subject(
            int id_subject,
            const std::string &_subject,
            int _group_id) :
            id(id_subject),
            subject(_subject),
            group_id(_group_id) {}
    static void AddSubject(const std::string &subject, int group_id);
    void DeleteSubject(int subject_id);
    static Subject ListSubject(int group_id);
private:
    int id;
    std::string subject;
    int group_id;
};

#endif //C___SUBJECT_H
