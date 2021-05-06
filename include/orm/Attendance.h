#ifndef PROJECT_ATTENDANCE_H
#define PROJECT_ATTENDANCE_H

class Attendance {
public:
    explicit Attendance(
            int id_attendance,
            int user_id,
            int subject_id,
            time_t date_pass_user) :
            id(id_attendance),
            user(user_id),
            subject(subject_id),
            date_pass(date_pass_user){}
    static void AddAttendance(SQLWrapper &db, int user_id, int subject_id, time_t date_pass);
    void DeleteAttendance(SQLWrapper &db, int Attendance_id);
    static Attendance GetAttendance(SQLWrapper &db, int user_id, int subject_id);

    int id;
    time_t date_pass;
    int subject;
    int user;
};

#endif //PROJECT_ATTENDANCE_H
