#include "../../include/orm/Wrapper.h"
#include "../../include/orm/AttachmentPost.h"
#include "../../include/orm/utils.hpp"
#include <iostream>

int AttachmentPost::AddAttachmentPost(SQLWrapper &db, int user_id, const std::string &file_name,
        const std::string &path, int type) {
    db << "INSERT INTO attachment_post (post_id, name, path, type) values ('"
       << user_id << "', "
       << file_name << ", "
       << path << ", "
       << type << "') returning id;";
    db.exec();

    return db.get_int(0);
}

std::vector<AttachmentPost> AttachmentPost::GetAttachmentPost(SQLWrapper &db, int post_id) {
    if (check_existence("attachment_post", "post_id", post_id)) {
        throw std::length_error("ERROR: FIELD attachment_post.post_id NOT FOUND ");
    }

    db << "SELECT * FROM attachment_post WHERE post_id = " << post_id << ";";
    db.exec();
    int i = 0;
    std::vector<AttachmentPost> result;
    while (db.count_tuples() > i) {
        AttachmentPost request(
                db.get_int(0, i),
                db.get_int(1, i),
                db.get_int(2, i),
                db.get_str(3, i),
                db.get_str(4, i));
        result.push_back(request);
        i++;
    }
    return result;
}

void AttachmentPost::DeleteAttachmentPost(SQLWrapper &db, int id_post) {
    db << "UPDATE attachment_post SET deleted = true WHERE post_id = " << id_post << ";";
    db.exec();
}
