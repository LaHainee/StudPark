#include "../../include/orm/Post.h"
#include "../../include/orm/Wrapper.h"
#include "../../include/orm/utils.hpp"
#include <iostream>

Post Post::GetPost(SQLWrapper &db, int post_id) {
    if (check_existence("post", "id", post_id)) {
        throw std::length_error("ERROR: FIELD NOT FOUND ");
    }
    db << "SELECT * FROM post WHERE id = " << post_id << ";";
    db.exec();
    Post result(db.get_int(0),
                db.get_str(1),
                db.get_str(2),
                db.get_int(3),
                db.get_bool(4),
                db.get_time_t(5));
    return result;
}

int Post::AddPost(SQLWrapper &db, const std::string &head, const std::string &body, int user_id, time_t created) {
    db << "INSERT INTO post (post_head, post_body, owner, deleted, created) values ('"
       << head << "', '"
       << body << "', '"
       << user_id<< "', '"
       << false << "', to_timestamp("<< created << ")) returning id;";
    db.exec();

    return db.get_int(0);
}

void Post::DeletePost(SQLWrapper &db, int id) {
    if (check_existence("post", "id", id)) {
        throw std::length_error("ERROR: FIELD NOT FOUND ");
    }
    db << "UPDATE post SET deleted = true WHERE id = " << id << ";";
    db.exec();
}
