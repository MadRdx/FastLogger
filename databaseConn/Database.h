#pragma once

#include <dbOperations.h>



class Database {
private:
    sqlite3 *db;

public:
    Database();
    ~Database();

    Database(const Database&) = delete;
    Database& operator=(const Database&) = delete;

    int writeLog(
        Loglevel level;
        std::string_view message,
        std::string_view project_name
    );


};
