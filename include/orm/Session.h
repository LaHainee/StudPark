#ifndef PROJECT_SESSION_H
#define PROJECT_SESSION_H

#include <string>
#include "Wrapper.h"

class Session {
public:
    explicit Session(
        int _id,
        int _user_id,
        const std::string &_session,
        time_t _time_end) :
        id(_id),
        user_id(_user_id),
        session(_session),
        time_end(_time_end) {}
    static void DeleteSession(SQLWrapper &db, const std::string &session);
    static int AddSession(SQLWrapper &db, int user_id, const std::string &session, time_t time_end);

    int id;
    int user_id;
    std::string session;
    time_t time_end;
};
#endif // PROJECT_SESSION_H
