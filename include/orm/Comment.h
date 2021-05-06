#ifndef PROJECT_COMMENT_H
#define PROJECT_COMMENT_H

class Comment {
public:
    explicit Comment(
            int comment_id,
            int post,
            int author,
            const std::string &body_comment,
            time_t _created) :
            id(comment_id),
            post_id(post),
            author_id(author),
            text(body_comment),
            created(_created) {};
    static Comment GetComment(SQLWrapper &db, int post_id);
    static void AddComment(SQLWrapper &db, int post_id, int author_id, const std::string &body_comment, time_t created);
    void DeleteComment(SQLWrapper &db, int post_id);

    int id;
    int post_id;
    int author_id;
    std::string text;
    time_t created;
};

#endif //PROJECT_COMMENT_H
