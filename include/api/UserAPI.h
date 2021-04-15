class UserAPI : API {
public:
    UserAPI() = default;
    static API::Response Update();
    static API::Response SetReminder();
    static API::Response Auth();
}