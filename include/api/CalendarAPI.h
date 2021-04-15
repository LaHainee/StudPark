class CalendarAPI : API {
public:
    CalendarAPI() = default;
    static API::Response ListEvents();
    static API::Response SetDeadline();
    static API::Response ExportAsIcs();
private:
    static std::string generateIcs();
}