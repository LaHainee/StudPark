#include "Logger.h"
#include "../Common.h"

class API {
  private:
    Logger *logger;
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
    struct Response {
        Response(std::string&, int, int);
        std::string body;
        int type;
        int status;
    };
    API();
    ~API();
    virtual std::string Get() = 0;
    virtual std::string Delete() = 0;
    virtual std::string Update() = 0;
};
