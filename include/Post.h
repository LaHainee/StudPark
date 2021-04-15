#ifndef C___POST_H
#define C___POST_H

class Post {
public:
    explicit Post(
            int _id,
            const std::string &head,
            const std::string &body,
            int user_id,
            time_t _created,
            const std::string &file_name = "",
            const std::string &_path = "") :
            id(_id),
            post_head(head),
            post_body(body),
            owner(user_id),
            created(_created) {};
    static Post GetPost(int post_id);
    int* GetComments();
    int* GetAttachmentPost();
    static void AddPost(const std::string &head, const std::string &body, int user_id, time_t created);
    void Delete();
private:
    int id;
    std::string post_head;
    std::string post_body;
    int owner;
    time_t created;
};

#endif //C___POST_H
