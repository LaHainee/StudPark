#ifndef C___SHARE_H
#define C___SHARE_H

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
    static void AddShare(int recipient_id, int owner_id, int file_id);
    void DeleteShare(int id);
    static Share GetList(int owner_id);
private:
    int id;
    int recipient;
    int owner;
    int file;
};

#endif //C___SHARE_H
