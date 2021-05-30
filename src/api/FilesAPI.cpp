#include "FilesAPI.h"

std::string FilesAPI::Create(const std::unordered_map <std::string, std::string> &data, SQLWrapper &db) {
    Student st;

    try {
        st = Student::GetStudentBySession(db, data.find("session")->second);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        // Render page "Session not found"
        return "";
    }

    std::string salt = randomString(SALT_LENGTH);
    std::string filepath = data.find("filepath")->second;
    if (!std::filesystem::exists(filepath)) {
        throw std::invalid_argument("The file does not exist");
    }
    std::string filename = std::filesystem::path(filepath).filename().generic_string();
    std::string hashedFilename = sha256(filename + salt);
    std::filesystem::rename(filepath, std::getenv("FILE_STORAGE") + hashedFilename);
    std::cout << File::AddFile(db, st.id, filename, salt);

    return "OK";
}

std::string FilesAPI::Get(const std::unordered_map <std::string, std::string> &data, SQLWrapper &db) {
    Student st;
    std::string session = data.find("session")->second;
    try {
        st = Student::GetStudentBySession(db, session);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        // Render page "Session not found"
    }
    File file = File::GetFile(db, std::stoi(data.find("id")->second));
    if (file.owner != st.id) {
        // Render "You are not the owner of this document
    }
    std::string storagePath = std::getenv("SYMLINKS_DIR") + session;
    if (!std::filesystem::exists(storagePath) ) {
        std::filesystem::create_directory(storagePath);
    }
    std::cout << "Creating symlink to " << std::getenv("FILE_STORAGE") + sha256(file.name + file.salt) << std::endl;
    std::cout << "Name: " << file.name << " Salt: " << file.salt << file.salt.length() << std::endl;

    try {
        std::filesystem::create_symlink(
            std::getenv("FILE_STORAGE") + sha256(file.name + file.salt),
                        storagePath + '/' + file.name);
    } catch (std::exception &e) {
        std::cout << "Symlink already exists, it's OK, but should've been deleted (" << e.what() << ")" << std::endl;
    }

    return "OK";
}

std::string FilesAPI::Update(const std::unordered_map <std::string, std::string> &data, SQLWrapper &db) {
    return nullptr;  // Change to Rename, returns int, AJAX
}

std::string FilesAPI::Delete(const std::unordered_map <std::string, std::string> &data, SQLWrapper &db) {
    Student st = Student::GetStudentBySession(db, data.find("session")->second);
    File f = File::GetFile(db, std::stoi(data.find("id")->second));

    try {
        File::DeleteFile(db, f.id);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return ""; // Return error code
    }
    return "";  // Change to int, AJAX
}

int FilesAPI::Share(const std::unordered_map <std::string, std::string> &data, SQLWrapper &db) {
    Student st;
    try {
        st = Student::GetStudentBySession(db, data.find("session")->second);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        // Return error int
    }
//    Share::AddShare(db, st.id, ), not yet implemented in orm
    return 200;
}

std::string FilesAPI::List() {
    // List files and render template, not yet implemented in orm
    return "";
}
