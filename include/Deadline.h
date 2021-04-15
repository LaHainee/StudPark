#ifndef C___DEADLINE_H
#define C___DEADLINE_H

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
    static void AddDeadline(int user_id, int subject_id, time_t date_deadline_user);
    void DeleteDeadline(int deadline_id);
    static Deadline GetDeadlines(int group_id, int subject_id);
private:
    int id;
    time_t date_deadline;
    int subject;
    int user;
};

#endif //C___DEADLINE_H

