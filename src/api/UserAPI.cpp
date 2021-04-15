API::Response UserAPI::Update(std::map<std::string, std::string> &data) {
    User u = User::Get(data["id"]);
    u.Update(data);
}

API::Response UserAPI::SetReminder(std::map<std::string, std::string> &data) {
    User u = User::Get(data["id"]);
    Scheduler::MailingParcel p;
    p.body = "По дисциплине \"Схемотехника\" завтра в 9:00 сдача ДЗ.";
    if (data["channel"] == Scheduler::TELEGRAM) {
       p.mail_to = u.GetEmail();
       p.head = "Дедлайн близко";
       int delay;  // = просмотреть все дедлайны и посчитать время 
    } else if (data["channel"] == Scheduler::EMAIL) {
       p.mail_to = u.GetTelegram();
    } else {  // EMAIL & TELEGRAM
       // Scheduler::Set(p, MAILING_EMAIL | MAILING_TELEGRAM); <- хочу так
    }

    // Нужно чтобы был класс Sender, выбирать тип рассылки нужно через маску MAILING_TELEGRAM | MAILING_EMAIL
}

UserAPI::Auth(std::map<std::string, std::string> &data) {

}