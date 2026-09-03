#pragma once

#include <sqlite3.h>
#include <string>
#include <iostream>
#include <string_view>

inline constexpr const char* FASTLOGGER = "fastlogger.db";
inline constexpr const char* WRITE_QUERY = "INSERT INTO logs(level, message, project_name) VALUES (?, ?, ?);";
enum class LogLevel {
    DEBUG,
    INFO,
    WARN,
    ERROR
};


