#include "PostAPI.h"

TemplateEngine templates;

std::string PostAPI::Create(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db) {
    Student admin;
    try {
        admin = Student::GetStudentBySession(db, data.find("session")->second);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;  // @todo=logs
        return "Session not found";  // Render template "error"
    }
    if (admin.role != Student::Roles::LEADER) {
        return "Not enough privileges";  // Render template
    }
    try {
        Post::AddPost(db,
                      data.find("head")->second,
                      data.find("body")->second,
                      admin.id,
                      time(nullptr));
    } catch (std::exception &e) {
        std::cout << e.what();
        return "Post creation failed";  // Render template
    }
    return "";  // Render template
}

std::string PostAPI::Get(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db) {
    return "";  // Single post page, not implemented
}
std::string PostAPI::Update(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db) {
    return "";  // Not implemented
}
std::string PostAPI::Delete(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db) {
    Student st = Student::GetStudentBySession(db, data.find("session")->second);
    Post post = Post::GetPost(db, std::stoi(data.find("id")->second));
    if (post.owner != st.id) {
        throw std::invalid_argument("Not enough privileges");
    }
    try {
        Post::DeletePost(db, std::stoi(data.find("id")->second));
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return "";  // Change to AJAX, returns int
}

std::string PostAPI::AddPostComment(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db) {
    Student st = Student::GetStudentBySession(db, data.find("session")->second);
    try {
        Comment::AddComment(db, std::stoi(data.find("post")->second), st.id, data.find("text")->second);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return "Comment::AddComment failed";  // Render template
    }
    return "Comment added";  // Render template
}

int PostAPI::DeletePostComment(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db) {
    Student st = Student::GetStudentBySession(db, data.find("session")->second);
    Comment::DeleteComment(db, std::stoi(data.find("id")->second));
    return 200;
}

std::string PostAPI::Feed(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db) {
    Student st;
    std::vector<Post> posts;
    try {
        st = Student::GetStudentBySession(db, data.find("session")->second);
    } catch (std::exception &e) {
        return templates.RenderErrors(e.what());
    }
    try {
        posts = Post::GetPostsByIdGroup(db, st.group_id);
    } catch (std::exception &e) { 
        return templates.RenderErrors(e.what());
    }

    return templates.RenderPosts(db, posts);
}
