#ifndef CODECARCASS_TEMPLATE_ENGINE_H
#define CODECARCASS_TEMPLATE_ENGINE_H

#include <iostream>
#include "inja.hpp"

using namespace inja;
using json = nlohmann::json;

class TemplateEngine {
public:
    std::string RenderTemplate(json data) {
        std::cout << "Шаблон успешно отрисован" << std::endl;
        std::string page = "HTML page";
        return page;
    }
};

#endif //CODECARCASS_TEMPLATE_ENGINE_H
