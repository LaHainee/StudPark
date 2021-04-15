std::string CalendarAPI::ListEvents(std::map<std::string, std::string> &data) {

}

std::string CalendarAPI::SetDeadline(std::map<std::string, std::string> &data) {

}

std::string CalendarAPI::ExportAsIcs(std::map<std::string, std::string> &data) {
    User::GetDeadlines();
}

std::string generateICS(std::map<std::string, std::string> &data) {
    // return ICS download link as std::string
}