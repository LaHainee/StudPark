#ifndef C___ATTACHMENTPOST_H
#define C___ATTACHMENTPOST_H

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
    static AttachmentPost GetAttachmentPost(int post_id);
    static void AddAttachmentPost(int user_id, int type, const std::string &file_name, const std::string &path);
    void DeleteAttachmentPost(int post_id);
private:
    int id;
    int post_id;
    int type;
    std::string name;
    std::string path;
};

#endif //C___ATTACHMENTPOST_H
