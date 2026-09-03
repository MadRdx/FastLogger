#pragma once

#include "dbOperations.h"
#include <string_view>


class Database {
private:
    sqlite3 *db;
    const char* writeQuery = "INSERT INTO logs(level, message, project_name) VALUES (?, ?, ?);";

public:
    Database();
    ~Database();

    Database(const Database&) = delete;
    Database& operator=(const Database&) = delete;

    int writeLog(
        LogLevel level;
        std::string_view message,
        std::string_view project_name
    );


};
