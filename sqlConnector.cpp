#include <iostream>
#include <sqlite3.h>


int connectSQL() {

    sqlite3 *db;
    int rc = sqlite3_open("fastlogger.db", &db);

    if (rc != SQLITE_OK) {
        std::cerr << "Something went wrong, ironically cannot insert this into the logger!" << std::endl;
        std::cerr << sqlite3_errmsg(db) << std::endl;
        return 1;
    }

    std::cout << "Successful DB Connection" << std::endl;



    return 0;

}
