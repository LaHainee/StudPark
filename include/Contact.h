#ifndef C___CONTACT_H
#define C___CONTACT_H

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
    static Contact GetContacts(int user_id);
    static void AddContacts(const std::string &user_type_contacts, const std::string &user_url, bool user_stealth);
    void DeleteContacts(int id);
private:
    int user;
    std::string type_contacts;
    std::string url;
    bool stealth;
};

#endif //C___CONTACT_H
