#include "Share.h"
#include "Wrapper.h"
#include "utils.hpp"

int Share::AddShare(SQLWrapper &db, int recipient_id, int owner_id, int file_id) {
    db << "INSERT INTO share (recipient, owner, file_fk) values ('"
       << recipient_id << "', "
       << owner_id << ", "
       << file_id <<  ") returning id;";
    db.exec();

    return db.get_int(0);
}

void Share::DeleteShare(SQLWrapper &db, int id) {
    if (check_existence("share", "id", id)) {
        throw std::length_error("ERROR: FIELD share.id NOT FOUND");
    }
    db << "UPDATE share SET deleted = true WHERE id = " << id << ";";
    db.exec();
}

Share Share::GetList(SQLWrapper &db, int owner_id) {
    if (check_existence("share", "owner", owner_id)) {
        throw std::length_error("ERROR: FIELD share.owner NOT FOUND");
    }
    db << "SELECT * FROM share WHERE owner = " << owner_id << ";";
    db.exec();
    Share result(
                   db.get_int(0),
                   db.get_int(1),
                   db.get_int(2),
                   db.get_bool(3),
                   db.get_int(4));
    return result;
}
