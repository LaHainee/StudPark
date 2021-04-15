#include "../../include/api/Logger.h"

std::ofstream Logger::file;
const char *LOG = "SP_LOG_LOCATION";

Logger::Logger() {
    const char *filename = std::getenv(LOG);
    file.open(filename, std::ofstream::out | std::ofstream::app);
}

Logger::~Logger() {
    file.close();
}

void Logger::Log(const char TYPE, const char *msg) {
    time_t now = time(0);
    char dt[100];
    strftime(dt, 100, "%a %b %d %T %Y", localtime(&now));
    file << TYPE << " [" << dt << "] " << msg << "\n";
}
