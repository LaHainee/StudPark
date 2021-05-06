#include "Logger.h"
#include "Wrapper.h"

#include <map>
#include <nlohmann/json.hpp>

class API {
  public:
    enum ResponseTypes{
        WEBPAGE,
        DOWNLOAD
    };
    enum Status{
        OK,
        API_ERR,
        ORM_ERR
    };
    API() = default;
    ~API() = default;
    virtual std::string Create(const std::map<std::string, std::string> &data, SQLWrapper &db) = 0;
    virtual std::string Get(const std::map<std::string, std::string> &data, SQLWrapper &db)    = 0;
    virtual std::string Update(const std::map<std::string, std::string> &data, SQLWrapper &db) = 0;
    virtual std::string Delete(const std::map<std::string, std::string> &data, SQLWrapper &db) = 0;
};
