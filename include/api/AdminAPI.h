class AdminAPI : API {
public:
    AdminAPI() = default;
    static std::string CreateUser();   // Для добавления старост
    static std::string CreateGroup(std::map<std::string, std::string>);  // При добавлении старосты логично причислить его к группе
    static std::string DeleteUser();
    static std::string DeleteGroup();
}