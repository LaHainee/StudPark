#ifndef C___GROUP_H
#define C___GROUP_H

class Group {
public:
    explicit Group(
            int id_group,
            int user_number_departament,
            int user_course,
            int user_group_number,
            time_t user_start_week,
            const std::string &user_faculty) :
            id(id_group),
            faculty(user_faculty),
            number_departament(user_number_departament),
            course(user_course),
            group_number(user_group_number),
            start_week(user_start_week) {}
    static void AddGroup(int user_number_departament, int user_course, int user_group_number, time_t start_week,
                         const std::string &user_faculty);
    void DeleteGroup(int group_id);
    static Group GetGroup(int group_id);
    static void UpdateGroup(int id_group, int user_number_departament, int user_course,
                            int user_group_number, time_t user_start_week, const std::string &user_faculty);
    int* GetMembers(int group_id);
private:
    int id;
    std::string faculty;
    int number_departament;
    int course;
    int group_number;
    time_t start_week;
};

#endif //C___GROUP_H
