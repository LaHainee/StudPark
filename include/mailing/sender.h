#ifndef CODECARCASS_SENDER_H
#define CODECARCASS_SENDER_H

#include <iostream>
#include <vector>
#include <../ORM/Send_mail.h>
#include <curl/curl.h>
#include <cstring>
#include <thread>
#include <iterator>
#include <algorithm>
#include <queue>

class EmailSender {
public:
    static void Send(std::vector<SendMail> data, std::vector<std::string> &accountsForMailing);
private:
    static void threadSendMail(const std::vector<SendMail> &data, const std::string &account);
    static size_t payloadSource(char *ptr, size_t size, size_t nmemb, void *userp);
    struct uploadStatus {
        int lines_read;
        std::string subject;
        std::string body;
        std::string account;
    };
};

class Scheduler {
public:
    Scheduler();
    void Scan();
private:
    std::vector<std::string> accountsForMailing;
};

#endif //CODECARCASS_SENDER_H
