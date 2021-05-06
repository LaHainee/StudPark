#ifndef PROJECT_GROUP_H
#define PROJECT_GROUP_H


#include <ctime>
#include <string>
#include <vector>
#include "Wrapper.h"

class Group {
public:
    explicit Group(
        int id_group,
        const std::string &user_faculty,
        int user_number_departament,
        int user_semester,
        int user_group_number,
        const std::string &_education_level,
        time_t user_start_week
        ) :
        id(id_group),
        faculty(user_faculty),
        number_departament(user_number_departament),
        semester(user_semester),
        group_number(user_group_number),
        education_level(_education_level),
        start_week(user_start_week) {}
    static int AddGroup(SQLWrapper &db, const std::string &user_faculty, int user_number_departament, int user_semester,
            int user_group_number, const std::string &education_level, time_t start_week);
//    static void DeleteGroup(SQLWrapper &db,int group_id);
// TODO(A1i5k): May be delete
    static Group GetGroup(SQLWrapper &db, int group_id);
    static void UpdateGroup(SQLWrapper &db, int id_group, int user_number_departament, int user_semester,
                            int user_group_number, time_t user_start_week, const std::string &user_faculty);
    static std::vector<int> GetMembers(SQLWrapper &db, int group_id);

    int id;
    std::string faculty;
    int number_departament;
    int semester;
    int group_number;
    std::string education_level;
    time_t start_week;
};

#endif //PROJECT_GROUP_H
