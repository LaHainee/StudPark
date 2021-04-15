#ifndef C___ATTENDANCE_H
#define C___ATTENDANCE_H

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
    static void AddAttendance(int user_id, int subject_id, time_t date_pass);
    void DeleteAttendance(int Attendance_id);
    static Attendance GetAttendance(int user_id, int subject_id);
private:
    int id;
    time_t date_pass;
    int subject;
    int user;
};

#endif //C___ATTENDANCE_H
