#include "API.h"
#include "Wrapper.h"
#include "openssl/sha.h"

#include <map>
#include <string>

using json = nlohmann::json;

class UserAPI : API {
public:
    UserAPI() = default;
    std::string Create(const std::map<std::string, std::string> &data, SQLWrapper &db) override;
    std::string Get(const std::map<std::string, std::string> &data, SQLWrapper &db) override;
    std::string Update(const std::map<std::string, std::string> &data, SQLWrapper &db) override;
    std::string Delete(const std::map<std::string, std::string> &data, SQLWrapper &db) override;
};