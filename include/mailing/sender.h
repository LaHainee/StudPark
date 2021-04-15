#ifndef CODECARCASS_SENDER_H
#define CODECARCASS_SENDER_H

#include <iostream>
#include <vector>

struct MailingParcel {
    std::vector<std::string> mail_to;
    std::string head;
    std::string body;
    int delay;
};

class TelegramSender {
public:
    bool Send(std::string username, std::string body) {
        std::cout << "Сообщение в телеграм успешно отправлено" << std::endl;
        return true;
    }
};

class EmailSender {
public:
    bool Send(std::string mail_to, std::string head, std::string body) {
        std::cout << "Сообщение на почту успешно отправлено" << std::endl;
        return true;
    }
};

class Scheduler {
public:
    void ParseRequest(std::vector<MailingParcel> &vec) {
        for (int i = 0; i < vec.size(); ++i) {
            if (vec[i].delay == 0) {
                std::cout << "Сообщение будет отправлено сразу" << std::endl;
                sendMsg(vec[i].mail_to, vec[i].head, vec[i].body);
            } else {
                std::cout << "Сообщение будет отправленно позже" << std::endl;
                bool flag = saveData(vec);
                if (flag) {
                    std::cout << "Данные успешно сохранены" << std::endl;
                } else {
                    std::cout << "Ошибка при записи данных" << std::endl;
                }
            }
        }
    }
private:
    bool saveData(std::vector<MailingParcel> &vec) {
        std::cout << "Сохраняю данные в JSON формате" << std::endl;
        return true;
    }
    bool readData() {
        std::cout << "Произошла остановка программы. Читаю файл с данным для восстановления данных об отложенной отправке" << std::endl;
        return true;
    }
    void sendMsg(std::vector<std::string> mail_to, std::string head, std::string body) {
        bool flag;
        if (mail_to[0] != "") {
            flag = mail.Send(mail_to[0], head, body);
            if (!flag)
                std::cout << "Произошла ошибка при попытке отправить e-mail" << std::endl;
        }
        if (mail_to[1] != "") {
            flag = telegram.Send(mail_to[1], body);
            if (!flag)
                std::cout << "Произошла ошибка при попытке отправить сообщение в Telegram" << std::endl;
        }
    }
    TelegramSender telegram;
    EmailSender mail;
};

#endif //CODECARCASS_SENDER_H
