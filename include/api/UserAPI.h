#include "API.h"
#include "openssl/sha.h"
#include "Utils.h"
#include "Session.h"
#include "Contact.h"
#include <map>
#include <string>
#include <regex>

class UserAPI : API {
public:
    UserAPI() = default;
    std::string Create(const std::unordered_map<std::string, std::string> &data) override;
    std::string Get(const std::unordered_map<std::string, std::string> &data)    override;
    std::string Update(const std::unordered_map<std::string, std::string> &data) override;
    std::string Delete(const std::unordered_map<std::string, std::string> &data) override;
    std::pair<std::string, std::string> Authenticate(const std::unordered_map<std::string, std::string> &data);
    std::string Authorize(const std::unordered_map<std::string, std::string> &data);
    std::string Login();
    std::string Logout(const std::unordered_map<std::string, std::string> &data);
    int AddContact(const std::unordered_map<std::string, std::string> &data);
    std::string SignupPage();
    std::string Profile(const std::unordered_map<std::string, std::string> &data);
    std::string SettingsPage(const std::unordered_map<std::string, std::string> &data);
private:
    bool emailIsValid(std::string &email);
    bool passwordMeetsRequirements(std::string &password);
};
