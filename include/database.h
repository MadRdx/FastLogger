#pragma once

#include "dbUtilities.h"
#include <string_view>


class Database {
private:
    sqlite3 *db;

public:
    Database();
    ~Database();

    Database(const Database&) = delete;
    Database& operator=(const Database&) = delete;

    int writeLog(
        LogLevel level,
        std::string_view message,
        std::string_view project_name
    );


};
