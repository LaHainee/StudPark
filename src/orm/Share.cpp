#include "../../include/orm/Share.h"
#include "../../include/orm/Wrapper.h"
#include "../../include/orm/utils.hpp"

int Share::AddShare(SQLWrapper &db, int recipient_id, int owner_id, int file_id) {
    db << "INSERT INTO share (recipient, owner, file_fk) values ('"
       << recipient_id << "', "
       << owner_id << ", "
       << file_id <<  ") returning id;";
    db.exec();

    return db.get_int(0);
}

void Share::DeleteShare(SQLWrapper &db, int id) {
    db << "UPDATE student SET deleted = true WHERE id = " << id << ";";
    db.exec();
}

Share Share::GetList(SQLWrapper &db, int owner_id) {
    if (check_existence("share", "owner_id", owner_id)) {
        throw std::length_error("ERROR: FIELD share.owner_id NOT FOUND ");
    }
    db << "SELECT * FROM share WHERE id = " << owner_id << ";";
    db.exec();
    Share result(
                   db.get_int(0),
                   db.get_int(1),
                   db.get_int(2),
                   db.get_bool(3),
                   db.get_int(4));
    return result;
}
