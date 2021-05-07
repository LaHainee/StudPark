#include "sender.h"

Scheduler::Scheduler() {
    accountsForMailing.emplace_back(std::getenv("MAIL_USER_1"));
    accountsForMailing.emplace_back(std::getenv("MAIL_USER_2"));
    accountsForMailing.emplace_back(std::getenv("MAIL_USER_3"));
    accountsForMailing.emplace_back(std::getenv("MAIL_USER_4"));
    accountsForMailing.emplace_back(std::getenv("MAIL_USER_5"));
    accountsForMailing.emplace_back(std::getenv("MAIL_USER_6"));
    accountsForMailing.emplace_back(std::getenv("MAIL_USER_7"));
    accountsForMailing.emplace_back(std::getenv("MAIL_USER_8"));
}

int main() {
    Scheduler sch;
    sch.Scan();
    return 0;
}