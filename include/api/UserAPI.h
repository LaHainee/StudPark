#include "API.h"
#include "Wrapper.h"
#include "openssl/sha.h"
#include "Utils.h"
#include "Session.h"
#include "Contact.h"
#include <map>
#include <string>
#include <regex>

using json = nlohmann::json;

class UserAPI : API {
public:
    UserAPI() = default;
    std::string Create(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db) override;
    std::string Get(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db)    override;
    std::string Update(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db) override;
    std::string Delete(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db) override;
    std::pair<std::string, std::string> Authenticate(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db);
    std::string Authorize(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db);
    std::string Login();
    std::string Logout(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db);
    int AddContact(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db);
    std::string SignupPage();
private:
    bool emailIsValid(std::string &email);
    bool passwordMeetsRequirements(std::string &password);
};
