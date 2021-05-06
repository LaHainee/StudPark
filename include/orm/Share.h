#ifndef PROJECT_SHARE_H
#define PROJECT_SHARE_H

class Share {
public:
    explicit Share(
            int share_id,
            int recipient_id,
            int owner_id,
            int file_id) :
            id(share_id),
            recipient(recipient_id),
            owner(owner_id),
            file(file_id) {}
    static void AddShare(SQLWrapper &db, int recipient_id, int owner_id, int file_id);
    void DeleteShare(SQLWrapper &db, int id);
    static Share GetList(SQLWrapper &db, int owner_id);

    int id;
    int recipient;
    int owner;
    int file;
};

#endif //PROJECT_SHARE_H
