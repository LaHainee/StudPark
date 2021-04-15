#include <gtest/gtest.h>
#include "sender.h"

MailingParcel mailing;

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    mailing.mail_to.push_back("example@gmail.com");
    mailing.mail_to.push_back("@example");
    mailing.head = "Тест";
    mailing.body = "Тестовое письмо";
    mailing.delay = 10;
    return RUN_ALL_TESTS();
}

TEST(send_mail, test1) {
    EmailSender mail;
    ASSERT_TRUE(mail.Send(mailing.mail_to[0], mailing.head, mailing.body));
}

TEST(send_telegram, test2) {
    TelegramSender telegram;
    ASSERT_TRUE(telegram.Send(mailing.mail_to[1], mailing.body));
}

