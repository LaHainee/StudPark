#ifndef PROJECT_UTILS_HPP
#define PROJECT_UTILS_HPP

#include "Wrapper.h"

template<class Value>
int check_existence(std::string table, const std::string field, Value value) {
    SQLWrapper db;
    db << "SELECT * FROM " + table +" WHERE " << field + " = " << value << ";";
    db.exec();
    if (db.count_tuples() > 0) {
        return 0;
    }
    return 1;
}
#endif //PROJECT_UTILS_HPP