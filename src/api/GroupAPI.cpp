API::Response GetGroupMembers(std::map<std::string, std::string> &data) {
    Group g = Group::Get(data["id"]);
    return TemplateEngine::Render(g.GetMembers());
}
API::Response AddGroupMembers(std::map<std::string, std::string> &data) {}
API::Response DeleteGroupMembers(std::map<std::string, std::string> &data) {}
API::Response ExportGroupList(std::map<std::string, std::string> &data) {}
API::Response AddJournalEntry(std::map<std::string, std::string> &data) {}
API::Response CreateLabQueue(std::map<std::string, std::string> &data) {}
API::Response EditLabQueue(std::map<std::string, std::string> &data) {}
std::string createCsvFromData(std::map<std::string, std::string> &data) {}