#include "template_engine.h"


int main() {
    json data;
    TemplateEngine te;

    data["posts"] = {
            {
                    {"title", "Информация по домашнему заданию по схемотехнике"},
                    {"text", "Для выполнения домашнего задания требуются теоретические знания по теме \"Триггеры\"."},
                    {"author", "Староста РК6-62 Варенцова Ольга"},
                    {"image", "../templates/img/mush.jpg"}
            },
            {
                    {"title", "Информация по домашнему заданию по схемотехнике"},
                    {"text", "Для выполнения домашнего задания требуются теоретические знания по теме \"Триггеры\"."},
                    {"author", "Заместитель cтаросты РК6-62 Павленко Антон"},
                    {"image", "../templates/img/putin.jpg"}
            }
    };
    /*data["user"] = "Ершов Виталий";
    data["information"] = {
            {
                    {"label", "ФИО"},
                    {"data", "Ершов Виталий Алексеевич"}
            },
            {
                    {"label", "Группа"},
                    {"data", "РК6-62Б"}
            },
            {
                    {"label", "Вариант"},
                    {"data", "№5"},
            },
            {
                    {"label", "День рождения"},
                    {"data", "10.01.2001"},
            },
    };*/
    std::cout << te.RenderTemplate(data, "../templates/admin_panel.html") << std::endl;
    return 0;
}

