#ifndef C___COMMENT_H
#define C___COMMENT_H

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
    static Comment GetComment(int post_id);
    static void AddComment(int post_id, int author_id, const std::string &body_comment, time_t created);
    void DeleteComment(int post_id);
private:
    int id;
    int post_id;
    int author_id;
    std::string text;
    time_t created;
};

#endif //C___COMMENT_H
