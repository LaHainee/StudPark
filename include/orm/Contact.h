#ifndef PROJECT_CONTACT_H
#define PROJECT_CONTACT_H

#include <iostream>
#include "Wrapper.h"

class Contact {
public:
    explicit Contact(
            int _id,
            int user_id,
            const std::string &user_type_contacts,
            const std::string &user_url,
            bool user_stealth) :
            id(_id),
            user(user_id),
            type_contacts(user_type_contacts),
            url(user_url),
            stealth(user_stealth) {}
    static Contact GetContacts(SQLWrapper &db, int user_id);
    static int AddContact(SQLWrapper &db, const int contact_type, const std::string &user_url, const int stealth, const int user_id);
    static void DeleteContacts(SQLWrapper &db, int id);

    int id;
    int user;
    std::string type_contacts;
    std::string url;
    bool stealth;
};

#endif //PROJECT_CONTACT_H
