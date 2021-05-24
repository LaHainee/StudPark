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
#include "Subject.h"

using namespace inja;
using json = nlohmann::json;

class TemplateEngine {
public:
    std::string RenderTemplate(const json& data, const std::string& templateToParse);
    std::string RenderPosts(SQLWrapper &wrapper, int groupId, bool isLeader);
    std::string RenderProfile(SQLWrapper &wrapper, const std::vector<Contact> &contacts,
                                              const Student &student);
    std::string RenderSettings(SQLWrapper &wrapper, const std::vector<Contact> &contacts,
                                               const Student &student);
    std::string RenderErrors(const std::string &error);
    std::string RenderGroupList(SQLWrapper &wrapper, int groupId);
    std::string RenderSubjectsList(SQLWrapper &wrapper, int groupId);
private:
    Environment env;
};

#endif //CODECARCASS_TEMPLATE_ENGINE_H
