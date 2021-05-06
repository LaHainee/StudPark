#include "sender.h"
#include "../../include/ORM/Send_mail.h"

void Scheduler::ScanningDB() {
    std::vector<SendMail> data;
    SQLWrapper wrapper;
    data = SendMail::NeedSend(wrapper);
    if (data.size() > 0) {
        mail.Send(data);
    }
}

size_t EmailSender::payload_source(char *ptr, size_t size, size_t nmemb, void *userp) {
    struct upload_status *upload_ctx = (struct upload_status *)userp;
    const char *payload_text[] = {
            "From: Studpark <TESTINTERNETYSER@gmail.com> \r\n",
            std::string("Subject: " + upload_ctx->subject + "\r\n").c_str(),
            "\r\n",
            std::string(upload_ctx->body + "\r\n").c_str(),
            NULL
    };
    const char *data;
    if((size == 0) || (nmemb == 0) || ((size*nmemb) < 1)) {
        return 0;
    }
    data = payload_text[upload_ctx->lines_read];
    if(data) {
        size_t len = strlen(data);
        std::memcpy(ptr, data, len);
        upload_ctx->lines_read++;
        return len;
    }
    return 0;
}

bool EmailSender::Send(std::vector<SendMail> data) {
    CURL *curl;
    CURLcode result = CURLE_OK;
    struct upload_status upload_ctx;
    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_USERNAME, std::getenv("MAIL_USER"));
    curl_easy_setopt(curl, CURLOPT_PASSWORD, std::getenv("MAIL_PASSWORD"));
    curl_easy_setopt(curl, CURLOPT_URL, std::getenv("MAIL_SERVER"));
    if (curl) {
        for (int i = 0; i < data.size(); ++i) {
            struct curl_slist *recipients = NULL;
            upload_ctx.subject = data[i].head_mail;
            upload_ctx.body = data[i].body_mail;
            upload_ctx.lines_read = 0;
            recipients = curl_slist_append(recipients, data[i].recipient.c_str());
            curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);
            curl_easy_setopt(curl, CURLOPT_READFUNCTION, payload_source);
            curl_easy_setopt(curl, CURLOPT_READDATA, &upload_ctx);
            curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
            result = curl_easy_perform(curl);
            if(result != CURLE_OK)
                fprintf(stderr, "curl_easy_perform() failed: %s\n",
                        curl_easy_strerror(result));
            curl_slist_free_all(recipients);
        }
        curl_easy_cleanup(curl);
    }
}

