#ifndef CODECARCASS_TEMPLATE_ENGINE_H
#define CODECARCASS_TEMPLATE_ENGINE_H

#include <algorithm>
#include <iostream>

#include "Post.h"
#include "Student.h"
#include "inja.hpp"
#include "Wrapper.h"
#include "Contact.h"
#include "Student.h"
#include "Group.h"

using namespace inja;
using json = nlohmann::json;

class TemplateEngine {
public:
    std::string RenderTemplate(const json& data, const std::string& templateToParse);
    std::string RenderPosts(SQLWrapper &wrapper, int groupId, bool isLeader, bool isAuthenticated, const std::string &user);
    std::string RenderProfile(SQLWrapper &wrapper, const std::vector<Contact> &contacts,
                                              const Student &student, bool isAuthenticated, const std::string &user);
    std::string RenderSettings(SQLWrapper &wrapper, const std::vector<Contact> &contacts,
                                               const Student &student, bool isAuthenticated, const std::string &user);
    std::string RenderErrors(const std::string &error, bool isAuthenticated, const std::string &user);
    std::string RenderGroupList(SQLWrapper &wrapper, int groupId, bool isAuthenticated, const std::string &user);
    std::string RenderLoginPage(bool isAuthenticated, const std::string &user);
    std::string RenderAdminPage(bool isAuthenticated, const std::string &user);
    std::string RenderSignupPage(bool isAuthenticated, const std::string &user);
private:
    Environment env;
};

#endif //CODECARCASS_TEMPLATE_ENGINE_H
