#include "UserAPI.h"
#include "Student.h"
#include "Group.h"

std::string UserAPI::Create(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db) {
    std::string password = data.find("password")->second;
    std::string password_enc = sha256(password);
    std::string email = data.find("user_login")->second;
    if (!emailIsValid(email)) {
        // Render template `error(email_is_invalid)`
    }
    if (!passwordMeetsRequirements(password)) {
        // Render template `error(wrong_password)`
        return "";
    }
    int groupID;
    try {
        groupID = Group::GetGroupByJoinCode(db, data.find("join_code")->second);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        // Render template `error(wrong_join_code)`
        return "";
    }

    int userID = Student::AddStudentRegistration(db, data.find("f_name")->second, data.find("s_name")->second,
                              data.find("user_patronymic")->second, email,
                              password, groupID);
    return std::string(std::to_string(userID));
}

std::string UserAPI::Get(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db) {
    return "";  // Render "User profile" page
}
std::string UserAPI::Update(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db) {
    return "";  // AJAX
}
std::string UserAPI::Delete(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db) {
    return "";  // Only for admin, AJAX
}

std::string UserAPI::Authenticate(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db) {
    int student = Student::GetIdByLoginPassword(db, data.find("login")->second, sha256(data.find("password")->second));
    std::string token = randomString(64);
    int session = Session::AddSession(db, student, token, time(nullptr));
    std::cout << "Created session " << session << std::endl;
    return token;  // Should be passed to server to Set-Cookie & Render template feed(student.group)
}

std::string UserAPI::Authorize(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db) {
    Student st = Student::GetStudentBySession(db, data.find("session")->second);
    return st.first_name;
}

std::string UserAPI::Logout(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db) {
    std::string session = data.find("session")->second;
    try {
        Student::GetStudentBySession(db, session);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return "Session not found";
    }

    Session::DeleteSession(db, session);

    return "OK";  // Render page login()
}

int UserAPI::AddContact(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db) {
    Student st = Student::GetStudentBySession(db, data.find("session")->second);
    try {
        Contact::AddContact(db, std::stoi(data.find("type")->second),
                            data.find("url")->second,
                            std::stoi(data.find("stealth")->second), st.id);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 200;  // AJAX
}

bool UserAPI::emailIsValid(std::string &email) {
    std::regex regexEmail("(?:[a-z0-9!#$%&'*+/=?^_`{|}~-]+(?:\\.[a-z0-9!#$%&'*+/=?^_`{|}~-]+)*|\"(?:[\x01-\x08\x0b\x0c\x0e-\x1f"
                "\x21\x23-\x5b\x5d-\x7f]|\\[\x01-\x09\x0b\x0c\x0e-\x7f])*\")@(?:(?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\\.)+"
                "[a-z0-9](?:[a-z0-9-]*[a-z0-9])?|\\[(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(?:25[0-5]|2[0-4]"
                "[0-9]|[01]?[0-9][0-9]?|[a-z0-9-]*[a-z0-9]:(?:[\x01-\x08\x0b\x0c\x0e-\x1f\x21-\x5a\x53-\x7f]|\\[\x01-"
                "\x09\x0b\x0c\x0e-\x7f])+)\\])");

    return std::regex_match(email, regexEmail);
}

bool UserAPI::passwordMeetsRequirements(std::string &password) {
    std::regex regexPassword("^(?=.*[A-Za-z])(?=.*\\d)[A-Za-z\\d]{8,}$");
    return std::regex_match(password, regexPassword);
}
