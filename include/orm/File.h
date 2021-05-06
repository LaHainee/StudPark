#ifndef PROJECT_FILE_H
#define PROJECT_FILE_H
#include "map"

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
    static void AddFile(SQLWrapper &db, int owner_id, const std::string &file_name, const std::string &file_path);
    void DeleteFile(SQLWrapper &db, int user_id);
    std::map<std::string, std::string> GetFiles(SQLWrapper &db, int user_id);

    int id;
    int owner;
    std::string name;
    std::string path;
};

#endif //PROJECT_FILE_H
