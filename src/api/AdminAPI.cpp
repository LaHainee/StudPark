std::string AdminAPI::CreateUser(const std::map<std::string, std::string> &data) {
    if (User::GetByField("login", data["login"])) {  // Уже существует, ошибка
        // Render template "User exists"
    } else {
        const uint user = User::Create(data);
        const std::string cookie = UserAPI::Auth(user);
        // Authenticate user (set cookie) and render template "Home page"
    }
}

std::string AdminAPI::CreateGroup(const std::map<std::string, std::string> &data) {
    if (Group::GetByField("", data["name"])) {

    } else {

    }
}

std::string AdminAPI::DeleteUser(const uint id) {
    if (User::Delete(id)) {
        // Render template "User deleted"
    } else {
        // Render template "Error occurred"
    }
}

std::string AdminAPI::DeleteGroup(const uint id) {
    if (Group::Delete(id)) {
        // Render template "User deleted"
    } else {
        // Render template "Error occurred"
    }
}