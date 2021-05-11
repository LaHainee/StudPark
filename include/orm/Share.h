#ifndef PROJECT_SHARE_H
#define PROJECT_SHARE_H

#include <string>
#include "Wrapper.h"

class Share {
public:
    explicit Share(
            int share_id,
            int recipient_id,
            int owner_id,
            int file_id,
            bool _deleted) :
            id(share_id),
            recipient(recipient_id),
            owner(owner_id),
            deleted(_deleted),
            file(file_id) {}
    static int AddShare(SQLWrapper &db, int recipient_id, int owner_id, int file_id);
    static void DeleteShare(SQLWrapper &db, int id);
    static Share GetList(SQLWrapper &db, int owner_id);

    int id;
    int recipient;
    int owner;
    bool deleted;
    int file;
};

#endif //PROJECT_SHARE_H
