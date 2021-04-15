class CalendarAPI : API {
public:
    CalendarAPI() = default;
    static std::string ListEvents();
    static std::string SetDeadline();
    static std::string ExportAsIcs();
private:
    static std::string generateIcs();
}