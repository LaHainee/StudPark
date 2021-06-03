#include <gtest/gtest.h>
#include "template_engine.h"

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(create_template, test1) {
    TemplateEngine template_engine;
    /*json data = "";
    std::string test_template = template_engine.RenderTemplate(data);*/
}
