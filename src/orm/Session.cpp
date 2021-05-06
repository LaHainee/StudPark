#include "../../include/orm/Session.h"
#include "../../include/orm/Wrapper.h"

Session Session::GetById(SQLWrapper &db, int id) {
    db << "SELECT * FROM session WHERE id = '" << id << "';";
    db.exec();
    Session result(
            db.get_int(0),
            db.get_int(1),
            db.get_str(2),
            db.get_time_t(3));
    return result;
}

void Session::DeleteSession(SQLWrapper &db, int id) {
    db << "DELETE FROM session WHERE id = '" << id << "';";
    db.exec();
}

int Session::AddSession(SQLWrapper &db, int user_id, const std::string &session, time_t time_end) {

    db << "INSERT INTO session (user_id, user_session, time_end) values ('"
       << user_id << "', '"
       << session << "', to_timestamp(" << time_end << ")) returning id;";
    db.exec();

    return db.get_int(0);
}
