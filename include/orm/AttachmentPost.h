#ifndef PROJECT_ATTACHMENTPOST_H
#define PROJECT_ATTACHMENTPOST_H

class AttachmentPost {
public:
    explicit AttachmentPost(
            int _id,
            int _post_id,
            int _type = -1,
            const std::string &file_name = "",
            const std::string &_path = "") :
            id(_id),
            post_id(_post_id),
            type(_type),
            name(file_name),
            path(_path) {};
    static AttachmentPost GetAttachmentPost(SQLWrapper &db, int post_id);
    static void AddAttachmentPost(SQLWrapper &db, int user_id, int type, const std::string &file_name,
            const std::string &path);
    void DeleteAttachmentPost(SQLWrapper &db, int post_id);

    int id;
    int post_id;
    int type;
    std::string name;
    std::string path;
};

#endif //PROJECT_ATTACHMENTPOST_H
