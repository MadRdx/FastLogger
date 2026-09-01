#pragma once

#include <sqlite3.h>
#include <string>
#include <iostream>
#include <string_view>

inline constexpr const char* FASTLOGGER = "fastlogger.db";

enum class LogLevel {
    Debug,
    Info,
    Warn,
    Error
};


// From databaseConn/sqlConnector.cpp, used to connect to database
int connectSQL(sqlite3 **p_db);

// From databaseConn/sqlWriter.cpp, used to write to database
int writeLog(
    sqlite3 *db,
    LogLevel logLevel,
    std::string_view message,
    std::string_view project_name
);
