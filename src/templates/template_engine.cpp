#include "template_engine.h"

std::string TemplateEngine::RenderTemplate(const json& data, const std::string& templateToParse) {
    env.set_expression("{{", "}}");
    env.set_statement("{%", "%}");
    Template temp = env.parse_template("templates/" + templateToParse);
    std::string result = env.render(temp, data);
    return result;
}

std::string TemplateEngine::RenderProfile(SQLWrapper &wrapper, const std::vector<Contact> &contacts,
                                          const Student& student, bool isAuthenticated=false, std::string user="") {
    json data {
            {"isAuthenticated", isAuthenticated},
            {"user", user},
            {"student", student.second_name + " " + student.first_name + " " + student.patronymic},
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
    return RenderTemplate(data, "profile.html");
}

std::string TemplateEngine::RenderSettings(SQLWrapper &wrapper, const std::vector<Contact> &contacts,
                                           const Student &student, bool isAuthenticated=false, std::string user="") {
    json data {
            {"isAuthenticated", isAuthenticated},
            {"user", user},
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
    return RenderTemplate(data, "settings.html"); 
}

std::string TemplateEngine::RenderGroupList(SQLWrapper &wrapper, int groupId, bool isAuthenticated=false, std::string user="") {
    std::vector<Student> students = Group::GetMembers(wrapper, groupId);
    json data {
        {"isAuthenticated", isAuthenticated},
        {"user", user},
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
    return RenderTemplate(data, "group_list.html");
}

std::string TemplateEngine::RenderErrors(const std::string &error, bool isAuthenticated=false, std::string user="") {
    json data {
        {"isAuthenticated", isAuthenticated},
        {"user", user},
        {"error", error}
    };
    return RenderTemplate(data, "errors.html");
}

std::string TemplateEngine::RenderLoginPage(bool isAuthenticated=false, std::string user="") {
    json data{
        {"isAuthenticated", isAuthenticated},
        {"user", user},
    };
    return RenderTemplate(data, "login.html");
}

std::string TemplateEngine::RenderAdminPage(bool isAuthenticated=false, std::string user="") {
    json data{
        {"isAuthenticated", isAuthenticated},
        {"user", user},
    };
    return RenderTemplate(data, "admin_panel.html");
}

std::string TemplateEngine::RenderSignupPage(bool isAuthenticated=false, std::string user="") {
    json data{
        {"isAuthenticated", isAuthenticated},
        {"user", user},
    };
    return RenderTemplate(data, "registration.html");
}

std::string TemplateEngine::RenderPosts(
        SQLWrapper &wrapper, int groupId, bool isLeader, bool isAuthenticated=false, std::string user="") {
    json data {
            {"isLeader", isLeader},
            {"isAuthenticated", isAuthenticated},
            {"user", user},
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
    return RenderTemplate(data, "main.html");
}
