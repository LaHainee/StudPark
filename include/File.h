#ifndef C___FILE_H
#define C___FILE_H
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
    static void AddFile(int owner_id, const std::string &file_name, const std::string &file_path);
    void DeleteFile(int user_id);
    std::map<std::string, std::string> GetFiles(int user_id);
private:
    int id;
    int owner;
    std::string name;
    std::string path;
};

#endif //C___FILE_H
