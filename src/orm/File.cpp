#include "../../include/orm/File.h"
#include "../../include/orm/Wrapper.h"
#include "../../include/orm/utils.hpp"

int File::AddFile(SQLWrapper &db, int owner_id, const std::string &file_name, const std::string &file_path) {
    db << "INSERT INTO file (owner, path, name) values ('"
       << owner_id << "', "
       << file_name << ", '"
       << file_path << "') returning id;";
    db.exec();
    return db.get_int(0);
}

void File::DeleteFile(SQLWrapper &db, int file_id) {
    db << "DELETE FROM file WHERE id = " << file_id << ";";
    db.exec();
}

File File::GetFiles(SQLWrapper &db, int user_id) {
    if (check_existence("file", "id", user_id)) {
        throw std::length_error("ERROR: FIELD file.user_id NOT FOUND ");
    }
    db << "SELECT * FROM deadline WHERE group_id = " << user_id << ";";
    db.exec();
    File result(
            db.get_int(0),
            db.get_int(1),
            db.get_str(2),
            db.get_str(3));
    return result;
}
