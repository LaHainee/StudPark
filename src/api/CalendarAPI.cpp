API::Response CalendarAPI::ListEvents(std::map<std::string, std::string> &data) {
    
}

API::Response CalendarAPI::SetDeadline(std::map<std::string, std::string> &data) {
    
}

API::Response CalendarAPI::ExportAsIcs(std::map<std::string, std::string> &data) {
    User u = Users::Get(id);
    std::map<std::string, std::string> deadlines = u.GetDeadlines();
}

std::string generateICS(std::map<std::string, std::string> &data) {
    // return ICS download link as std::string
}