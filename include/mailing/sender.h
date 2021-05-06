#ifndef CODECARCASS_SENDER_H
#define CODECARCASS_SENDER_H

#include <iostream>
#include <vector>
#include <../ORM/Send_mail.h>
#include <curl/curl.h>
#include <cstring>

class EmailSender {
public:
    bool Send(std::vector<SendMail>);
private:
    static size_t payload_source(char *ptr, size_t size, size_t nmemb, void *userp);
    struct upload_status {
        int lines_read;
        std::string subject;
        std::string body;
    };
};

class Scheduler {
public:
    void ScanningDB();
private:
    EmailSender mail;
};

#endif //CODECARCASS_SENDER_H
