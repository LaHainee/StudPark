#include "Wrapper.h"
#include "Attendance.h"
#include "utils.hpp"

int Attendance::AddAttendance(SQLWrapper &db, int user_id, int subject_id, time_t date_pass) {
    db << "INSERT INTO attendance (user_id, subject_id, date_pass) values ('"
       << user_id << "', "
       << subject_id << ", to_timestamp("
       << date_pass << ")) returning id;";
    db.exec();

    return db.get_int(0);
}

void Attendance::DeleteAttendance(SQLWrapper &db, int Attendance_id) {
    db << "DELETE FROM attendance WHERE id = " << Attendance_id << ";";
    db.exec();
}

Attendance Attendance::GetAttendance(SQLWrapper &db, int user_id, int subject_id) {
    if (check_existence("attendance", "id", user_id)) {
        throw std::length_error("ERROR: FIELD attendance.id NOT FOUND ");
    }
    if (check_existence("subject", "id", user_id)) {
        throw std::length_error("ERROR: FIELD subject.id NOT FOUND ");
    }
    db << "SELECT * FROM attendance WHERE user_id = " << user_id << "AND subject_id = " << subject_id << ";";
    db.exec();
    Attendance result(
                   db.get_int(0),
                   db.get_int(1),
                   db.get_int(2),
                   db.get_time_t(3));
    return result;
}
