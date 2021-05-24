#include "template_engine.h"

std::string TemplateEngine::RenderTemplate(const json& data, const std::string& templateToParse) {
    env.set_expression("{{", "}}");
    env.set_statement("{%", "%}");
    Template temp = env.parse_template("../templates/" + templateToParse);
    env.write(temp, data, "../created_templates/" + templateToParse);
    return "Created";
}

std::string TemplateEngine::RenderPosts(SQLWrapper &wrapper, int groupId, bool isLeader) {
    json data {
            {"isLeader", isLeader},
            {"group_name", Group::GetGroupName(wrapper, groupId)},
            {"posts",
                {}
            }
    };
    std::vector<Post> posts = Post::GetPostsByIdGroup(wrapper, groupId);
    for (const auto& post : posts) {
        std::string author = (Student::GetStudentById(wrapper, post.owner).second_name + " " +
                Student::GetStudentById(wrapper, post.owner).first_name);
        data["posts"] += {
            {"title", post.post_head},
            {"text", post.post_body},
            {"author", author},
        };
    }
    std::cout << RenderTemplate(data, "main.html") << std::endl;
    return "Posts rendered\n";
}

std::string TemplateEngine::RenderProfile(SQLWrapper &wrapper, const std::vector<Contact> &contacts,
                                          const Student& student) {
    json data {
            {"user", student.second_name + " " + student.first_name + " " + student.patronymic},
            {"information", {
                {
                    {"label", "ФИО"},
                    {"data", student.second_name + " " + student.first_name + " " + student.patronymic}
                },
                {
                    {"label", "Группа"},
                    {"data", Group::GetGroupName(wrapper, student.group_id)},
                },
                {
                    {"label", "День рождения"},
                    {"data", student.birthday}
                },
                {
                    {"label", "Email"},
                    {"data", student.login},
                },
            }}
    };
    for (auto &contact : contacts) {
        data["information"] += {
                {"label", Contact::GetNameContact(contact.type_contacts)},
                {"data", "<a href=" + contact.url + ">" + contact.url + "</a>"}
        };
    }
    std::cout << RenderTemplate(data, "profile.html") << std::endl;
    return "Profile rendered\n";
}

std::string TemplateEngine::RenderSettings(SQLWrapper &wrapper, const std::vector<Contact> &contacts,
                                           const Student &student) {
    json data {
            {"user", student.second_name + " " + student.first_name + " " + student.patronymic},
            {"FIO", student.second_name + " " + student.first_name + " " + student.patronymic},
            {"birthday", student.birthday},
            {"contacts", {
            }}
    };
    std::vector<int> filledContacts;
    for (auto &contact : contacts) {
        data["contacts"] += {
                {"id", std::to_string(contact.type_contacts)},
                {"label", Contact::GetNameContact(contact.type_contacts)},
                {"data", contact.url}
        };
        filledContacts.push_back(contact.type_contacts);
    }
    int contactsAmount = 8;
    for (int index = 0; index < contactsAmount; ++index) {
        if (std::find(filledContacts.begin(), filledContacts.end(), index) == filledContacts.end()) {
            data["contacts"] += {
                    {"id", std::to_string(index)},
                    {"label", Contact::GetNameContact(index)},
                    {"data", ""}
            };
        }
    }

    std::cout << RenderTemplate(data, "settings.html") << std::endl;
    return "Settings rendered\n";
}

std::string TemplateEngine::RenderGroupList(SQLWrapper &wrapper, int groupId) {
    std::vector<Student> students = Group::GetMembers(wrapper, groupId);
    json data {
        {"group_name", Group::GetGroupName(wrapper, groupId)},
        {"students",
            {}
        }
    };
    int index = 1;
    for (auto &student : students) {
        std::vector<Contact> studentContacts = Contact::GetContacts(wrapper, student.id);
        std::string phoneNumber;
        std::string email;
        for (auto &contact : studentContacts) {
            if (contact.type_contacts == 7)
                phoneNumber = contact.url;
            if (contact.type_contacts == 8)
                email = contact.url;
        }
        data["students"] += {
                {"index", index},
                {"FIO", student.second_name + " " + student.first_name + " " + student.patronymic},
                {"birthday", student.birthday},
                {"phone", phoneNumber},
                {"email", email}
        };
        index += 1;
    }

    std::cout << RenderTemplate(data, "group_list.html") << std::endl;
    return "Group list rendered\n";
}

std::string TemplateEngine::RenderErrors(const std::string &error) {
    json data {
        {"error", error}
    };
    std::cout << RenderTemplate(data, "errors.html") << std::endl;
    return "Errors rendered\n";
}

std::string TemplateEngine::RenderSubjectsList(SQLWrapper &wrapper, int groupId) {
    json data {
        {"group_name", Group::GetGroupName(wrapper, groupId)},
        {"subjects",
            {}
        }
    };
    int index = 1;
    std::vector<Subject> subjects = Subject::ListSubject(wrapper, groupId);
    for (auto &subject : subjects) {
        data["subjects"] += {
            {"index", index},
            {"id", subject.id},
            {"name", subject.subject}
        };
        index += 2;
    }
    std::cout << RenderTemplate(data, "subjects_list.html") << std::endl;
    return "Subjects list rendered\n";
}

int main() {
    json data;
    TemplateEngine templateEngine;
    SQLWrapper wrapper;

    Student student = Student::GetStudentById(wrapper, 11);
    std::vector<Contact> contacts = Contact::GetContacts(wrapper, 11);
    std::vector<Post> posts = Post::GetPostsByIdGroup(wrapper, 3);


    // Рендеринг профиля
    //std::cout << templateEngine.RenderProfile(wrapper, contacts, student) << std::endl;
    // Рендеринг настроек
    // std::cout << templateEngine.RenderSettings(wrapper, contacts, student) << std::endl;
    // Рендеринг главной страницы
    std::cout << templateEngine.RenderPosts(wrapper, 3, false) << std::endl;
    // Рендеринг ошибок
    // std::cout << templateEngine.RenderErrors("Неправильный логин или пароль") << std::endl;
    // Рендеринг списка группы
    // std::cout << templateEngine.RenderGroupList(wrapper, 3);*/
    // Рендеринг списка дисциплин
    // std::cout << templateEngine.RenderSubjectsList(wrapper, 3);
    return 0;
}

