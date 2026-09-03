#include<iostream>

#include "database.h"


const char* logLevelToString(LogLevel level) {
    switch (level) {
        case LogLevel::DEBUG: return "DEBUG";
        case LogLevel::INFO:  return "INFO";
        case LogLevel::WARN:  return "WARN";
        case LogLevel::ERROR: return "ERROR";
    }

    return "UNKNOWN";
}


Database::Database() : db(nullptr) {
    sqlite3_open(FASTLOGGER, &db);
}

Database::~Database() {
    if(db != nullptr) sqlite3_close(db);
}

int Database::writeLog(
    LogLevel logLevel,
    std::string_view message,
    std::string_view project_name
) {

    sqlite3_stmt* stmt = nullptr;
    int rc = sqlite3_prepare_v2(
        db, WRITE_QUERY, -1, &stmt, nullptr
    );

    if(rc != SQLITE_OK) return rc;

    sqlite3_bind_text(
        stmt, 1, logLevelToString(logLevel), -1, SQLITE_TRANSIENT
    );
    sqlite3_bind_text(
        stmt, 2, message.data(), static_cast<int>(message.size()), SQLITE_TRANSIENT
    );
  sqlite3_bind_text(
        stmt, 3, project_name.data(), static_cast<int>(project_name.size()), SQLITE_TRANSIENT
    );

    rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    return rc == SQLITE_DONE ? SQLITE_OK : rc;

}
