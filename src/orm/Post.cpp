#include "../../include/orm/Post.h"
#include "../../include/orm/Wrapper.h"
#include "../../include/orm/utils.hpp"
#include <iostream>

Post Post::GetPost(SQLWrapper &db, int post_id) {
    if (check_existence("post", "id", post_id)) {
        throw std::length_error("ERROR: FIELD post.id NOT FOUND ");
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
    if (check_existence("student", "id", user_id)) {
        throw std::length_error("ERROR: FIELD student.id student.NOT FOUND ");
    }

    db << "INSERT INTO post (post_head, post_body, owner, created) values ('"
       << head << "', '"
       << body << "', '"
       << user_id<< "', "
       << "to_timestamp("<< created << ")) returning id;";
    db.exec();

    return db.get_int(0);
}

void Post::DeletePost(SQLWrapper &db, int id) {
    if (check_existence("post", "id", id)) {
        throw std::length_error("ERROR: FIELD post.id NOT FOUND ");
    }
    db << "UPDATE post SET deleted = true WHERE id = " << id << "; UPDATE comment SET deleted = true WHERE post_id = " << id;
    db.exec();
}

std::vector<Post> Post::GetPostsByIdGroup(SQLWrapper &db, int id) {
    if (check_existence("\"group\"", "id", id)) {
        throw std::length_error("ERROR: FIELD group.id NOT FOUND ");
    }
    if (check_existence("student", "group_id", id)) {
        throw std::length_error("ERROR: FIELD student.group_id NOT FOUND ");
    }
    db << "SELECT post.* FROM public.post join (select group_id, id from public.student) temp"
          " on post.owner=temp.id join (select id from public.group where id = " << id
    << ") temp1 on temp.group_id=temp1.id;";
    db.exec();
    std::vector<Post> result;
    int i = 0;
    while (db.count_tuples() > i) {
        Post request(db.get_int(0, i),
                     db.get_str(1, i),
                     db.get_str(2, i),
                     db.get_int(3, i),
                     db.get_bool(4, i),
                     db.get_time_t(5, i));
        result.push_back(request);
        i++;
    }
    return result;
}
