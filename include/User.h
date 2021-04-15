#ifndef C___USER_H
#define C___USER_H

class User {
public:
    explicit User(
            int user_id,
            const std::string &f_name,
            const std::string &s_name,
            const std::string &user_patronymic,
            char user_form_educational,
            bool user_hostel,
            const std::string &user_stud_card,
            const std::string &user_avatar,
            const std::string &user_record_book,
            int user_role,
            int user_role_university,
            const std::string &user_login,
            const std::string &user_password,
            time_t user_date_admission,
            time_t date_reg,
            int _group_id,
            const std::string &user_status = "") :
            id(user_id),
            first_name(f_name),
            second_name(s_name),
            patronymic(user_patronymic),
            form_educational(user_form_educational),
            hostel(user_hostel),
            stud_card(user_stud_card),
            avatar(user_avatar),
            record_book(user_record_book),
            role(user_role),
            role_university(user_role_university),
            login(user_login),
            password(user_password),
            date_admission(user_date_admission),
            date_registration(date_reg),
            status(user_status),
            group_id(_group_id){}
    static void AddUser(const std::string &f_name, const std::string &s_name, const std::string &user_patronymic,
                        char user_form_educational,  bool user_hostel, const std::string &user_stud_card,
                        const std::string &user_avatar, const std::string &user_record_book, int user_role,
                        int user_role_university, const std::string &user_login, const std::string &user_password,
                        time_t user_date_admission, time_t date_reg, int group_id, const std::string &user_status);
    void DeleteUser(int user_id);
    static User GetUser(int user_id);
    bool SearchLogin(std::string login);
    static void UpdateUser(int user_id, const std::string &f_name, const std::string &s_name,
                           const std::string &user_patronymic,  char user_form_educational, bool user_hostel,
                           const std::string &user_stud_card, const std::string &user_avatar,
                           const std::string &user_record_book, int user_role, int user_role_university,
                           const std::string &user_login, const std::string &user_password,
                           time_t user_date_admission, time_t date_reg, int group_id, const std::string &user_status);
private:
    int id;
    std::string first_name;
    std::string second_name;
    std::string patronymic;
    char form_educational;
    bool hostel;
    std::string stud_card;
    std::string avatar;
    std::string record_book;
    int role;
    int role_university;
    std::string login;
    std::string password;
    time_t date_registration;
    time_t date_admission;
    std::string status;
    int group_id;
};

#endif //C___USER_H
