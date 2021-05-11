#ifndef PROJECT_FILE_H
#define PROJECT_FILE_H

#include <iostream>
#include "Wrapper.h"

class File {
public:
    explicit File(
            int file_id,
            int owner_id,
            const std::string &file_name,
            const std::string &file_path) :
            id(file_id),
            owner(owner_id),
            name(file_name),
            path(file_path) {}
    static int AddFile(SQLWrapper &db, int owner_id, const std::string &file_name, const std::string &file_path);
    static void DeleteFile(SQLWrapper &db, int user_id);
    static File GetFiles(SQLWrapper &db, int user_id);

    int id;
    int owner;
    std::string name;
    std::string path;
};

#endif //PROJECT_FILE_H
