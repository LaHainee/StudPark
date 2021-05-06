#ifndef PROJECT_CONTACT_H
#define PROJECT_CONTACT_H

class Contact {
public:
    explicit Contact(
            int user_id,
            const std::string &user_type_contacts,
            const std::string &user_url,
            bool user_stealth) :
            user(user_id),
            type_contacts(user_type_contacts),
            url(user_url),
            stealth(user_stealth) {}
    static Contact GetContacts(SQLWrapper &db, int user_id);
    static void AddContacts(SQLWrapper &db, const std::string &user_type_contacts, const std::string &user_url, bool user_stealth);
    void DeleteContacts(SQLWrapper &db, int id);

    int user;
    std::string type_contacts;
    std::string url;
    bool stealth;
};

#endif //PROJECT_CONTACT_H
