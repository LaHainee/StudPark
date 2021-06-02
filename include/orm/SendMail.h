#ifndef PROJECT_SENDMAIL_H
#define PROJECT_SENDMAIL_H

#include <iostream>
#include <vector>
#include "Wrapper.h"
#include <string>

class SendMail {
 public:
    explicit SendMail(
        int _id,
        const std::string &_recipient,
        const std::string &_head_mail,
        const std::string &_body_mail,
        time_t _time_send) :
        id(_id),
        recipient(_recipient),
        head_mail(_head_mail),
        body_mail(_body_mail),
        time_send(_time_send) {}
    static void DeleteFromQueue(SQLWrapper &db, int id);
    static std::vector<SendMail> NeedSend(SQLWrapper &db);
    static int AddInQueue(SQLWrapper &db, const std::string &recipient, const std::string &head_mail,
            const std::string &body_mail, time_t time_send);

    int id;
    std::string recipient;
    std::string head_mail;
    std::string body_mail;
    time_t time_send;
};
#endif // PROJECT_SENDMAIL_H
