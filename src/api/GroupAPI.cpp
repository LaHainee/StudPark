#include <Deadline.h>
#include "GroupAPI.h"
#include "Utils.h"

std::string GroupAPI::Create(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db) {
    Student admin;
    try {
        admin = Student::GetStudentBySession(db, data.find("session")->second);
    } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
    }
    int group;
    if (admin.role != Student::Roles::LEADER) {
        throw std::invalid_argument("Not enough privileges");
    }
    std::string joinCode = randomString(8);
    try {
        group = Group::AddGroup(db,
                                data.find("user_faculty")->second,
                                std::stoi(data.find("user_number_department")->second),
                                std::stoi(data.find("user_semester")->second),
                                std::stoi(data.find("user_group_number")->second),
                                data.find("education_level")->second,
                                joinCode,
                                time(nullptr)
                                );
    } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
    }

    std::string password = randomString(10);
    try {
        Student::AddStudentRegistration(db, data.find("head_f_name")->second, data.find("head_s_name")->second,
                                  data.find("head_patronymic")->second, data.find("head_user_login")->second,
                                  sha256(password), group, Student::LEADER);
    } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
    }

    return password;  // Render template "Group created, head password is: <pwd>
}
std::string GroupAPI::Get(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db) {
    return "";  // Delete
}
std::string GroupAPI::Update(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db) {
    return "";  // Delete
}
std::string GroupAPI::Delete(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db) {
    return "";  // For superuser only
}

std::string GroupAPI::ExportContacts(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db) {
    Student admin;
    try {
        admin = Student::GetStudentBySession(db, data.find("session")->second);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        throw std::invalid_argument("Session not found");
    }
    if (admin.role != Student::Roles::LEADER) {
        throw std::invalid_argument("Not enough privileges");
    }
    std::cout << admin.group_id << std::endl;

    std::vector<Student> members = Group::GetMembers(db, admin.group_id);

    std::string csv;
    csv += "№,ФИО,Email\n";
    size_t counter = 1;
    for (auto &s : members) {
        csv += std::to_string(counter++) + "," + s.second_name + " " + s.first_name + " " + s.patronymic + "," + s.login + "\n";
    }

    return csv;  // Should return a link to file
}

int GroupAPI::AddSubject(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db) {
    std::string session = data.find("session")->second;
    Student admin = getStudentBySession(session, db);
    if (admin.role == Student::Roles::LEADER) {
        try {
            Subject::AddSubject(db, data.find("subject")->second, admin.group_id);
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    } else {
        throw std::invalid_argument("Not enough privileges");
    }
    return 200;
}

Student GroupAPI::getStudentBySession(std::string &session, SQLWrapper &db) {
    Student st;
    try {
        st = Student::GetStudentBySession(db, session);
    } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
    }
    return st;
}

int GroupAPI::AddDeadline(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db) {
    std::string session = data.find("session")->second;
    Student admin = getStudentBySession(session, db);
    std::string time = data.find("time")->second;
    std::string deadlineName = data.find("name")->second;
    if (admin.role == Student::Roles::LEADER) {
        try {
            Deadline::AddDeadline(db, deadlineName, std::stoi(data.find("subject")->second), time);
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        // Сразу же ставим уведомления за неделю и за сутки до мероприятия для всей группы (на почту)
        std::vector<Student> students = Group::GetMembers(db, admin.group_id);
        struct std::tm tm{};
        std::cout << time << std::endl;
        std::istringstream ss(time);
        ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
        time_t schedTime = mktime(&tm);
        for (auto &student : students) {
            SendMail::AddInQueue(db, student.login, deadlineName, deadlineName, schedTime - WEEK);
            SendMail::AddInQueue(db, student.login, deadlineName, deadlineName, schedTime - DAY);
        }
    } else {
        throw std::invalid_argument("Not enough privileges");
    }
    return 200;
}
