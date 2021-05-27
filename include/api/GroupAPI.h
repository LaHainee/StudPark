#include <map>
#include <string>
#include "API.h"
#include "Group.h"
#include "Student.h"
#include "Subject.h"
#include "Wrapper.h"
#include "SendMail.h"
#include <boost/locale.hpp>


using json = nlohmann::json;

#define WEEK 604800
#define DAY  86400

class GroupAPI : API {
public:
    GroupAPI() = default;

    std::string Create(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db) override;
    std::string Get(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db) override;
    std::string Update(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db) override;
    std::string Delete(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db) override;

    std::string ExportGroupList(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db);
    std::string AddSubject(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db);
    std::string AddSubjectPage(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db);
    std::string AddDeadline(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db);
    std::string CreatePage(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db);
    std::string GetDeadlines(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db);
    std::string DeleteDeadline(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db);
    std::string GetSubjects(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db);
    std::string GetSubjectsPage(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db);
    std::string DeleteSubject(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db);
private:
    Student getStudentBySession(std::string &session, SQLWrapper &db);
};
