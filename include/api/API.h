#include "Wrapper.h"

#pragma once

#include <map>
#include <nlohmann/json.hpp>

class API {
  public:
    API() = default;
    ~API() = default;
    virtual std::string Create(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db) = 0;
    virtual std::string Get(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db)    = 0;
    virtual std::string Update(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db) = 0;
    virtual std::string Delete(const std::unordered_map<std::string, std::string> &data, SQLWrapper &db) = 0;
};
