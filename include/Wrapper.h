#ifndef C___WRAPPER_H_
#define C___WRAPPER_H_

#include <sstream>
//#include <postgresql>

class SQLWrapper {
public:
   // SQLWrapper() : {}

    void Clear();

  //  PGconn *GetConn();

    void Disconnect();

    bool Exec();
    char *GetStr(int field_num, int tup_num = 0);
    int GetInt(int field_num, int tup_num = 0);
    bool GetBool(int field_num, int tup_num = 0);
    int CountTupls();
    bool CheckConnect();

private:
//    PGconn *conn;
    std::ostringstream os;
  //  PGresult *result;
};

#endif // C___WRAPPER_H_
