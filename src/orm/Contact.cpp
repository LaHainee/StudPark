#include "Contact.h"
#include "Wrapper.h"
#include "utils.hpp"

int Contact::AddContact(SQLWrapper &db, const int contact_type, const std::string &user_url, const int stealth, const int user_id) {
    db << "INSERT INTO contacts (stealth, type, url, user_id) values ("
       << stealth << ", "
       << contact_type << ", '"
       << user_url << "', "
       << user_id << ") returning id;";
    db.exec();
    return db.get_int(0);
}

Contact Contact::GetContacts(SQLWrapper &db, int user_id) {
    if (check_existence("contacts", "user_id", user_id)) {
        throw std::length_error("ERROR: FIELD contacts.user_id NOT FOUND");
    }
    db << "SELECT * FROM contacts WHERE user_id = " << user_id << ";";
    db.exec();
    Contact result(
                   db.get_int(0),
                   db.get_int(1),
                   db.get_int(2),
                   db.get_str(3),
                   db.get_int(4));
    return result;
}

void Contact::DeleteContacts(SQLWrapper &db, int id) {
    db << "DELETE FROM contacts WHERE id = " << id << ";";
    db.exec();
}
