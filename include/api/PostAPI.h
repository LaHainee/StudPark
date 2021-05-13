#include "Student.h"
#include "Post.h"
#include <map>
#include "API.h"
#include "Comment.h"

class PostAPI : API {
public:
    PostAPI() = default;

    std::string Create(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db) override;
    std::string Get(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db)    override;
    std::string Update(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db) override;
    std::string Delete(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db) override;

    std::string AddPostComment(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db);
    int DeletePostComment(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db);
};
