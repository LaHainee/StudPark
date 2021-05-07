#include "../../include/orm/Session.h"
#include "../../include/orm/Wrapper.h"
#include "../../include/orm/utils.hpp"

void Session::DeleteSession(SQLWrapper &db, int id) {
    if (check_existence("session", "id", id)) {
        throw std::length_error("ERROR: FIELD session.id NOT FOUND ");
    }
    db << "DELETE FROM session WHERE id = '" << id << "';";
    db.exec();
}

int Session::AddSession(SQLWrapper &db, int user_id, const std::string &session, time_t time_end) {
    if (check_existence("student", "id", user_id)) {
        throw std::length_error("ERROR: FIELD student.id NOT FOUND ");
    }

    db << "INSERT INTO session (user_id, user_session, time_end) values ('"
       << user_id << "', '"
       << session << "', to_timestamp(" << time_end << ")) returning id;";
    db.exec();

    return db.get_int(0);
}
