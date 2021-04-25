#ifndef CODECARCASS_TEMPLATE_ENGINE_H
#define CODECARCASS_TEMPLATE_ENGINE_H

#include <iostream>
#include "inja.hpp"

using namespace inja;
using json = nlohmann::json;


class TemplateEngine {
public:
    std::string RenderTemplate(json data, std::string templateToParse) {
        env.set_expression("{{", "}}");
        env.set_statement("{%", "%}");
        Template temp = env.parse_template(templateToParse);
        env.write(temp, data, "../created_templates/profile.html");
        return "Created template";
    }
private:
    Environment env;
};

#endif //CODECARCASS_TEMPLATE_ENGINE_H
