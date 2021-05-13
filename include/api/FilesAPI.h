#include "API.h"
#include "File.h"
#include "Share.h"
#include "Student.h"
#include "Utils.h"

#include <filesystem>
#include <map>
#include <string>

#define SALT_LENGTH 10

class FilesAPI : API {
  public:
    FilesAPI() = default;
    std::string Create(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db);
    std::string Get(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db);
    std::string Update(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db);
    std::string Delete(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db);
    int Share(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db);
    std::string List();  // Интерфейс "проводника". Листинг файлов. Пока без папок.
};
