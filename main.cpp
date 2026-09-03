#include <iostream>
#include "database.h"


int main () {
    Database db;

    int rc =    db.writeLog(LogLevel::INFO, "First Log", "MyProj");
    std::cout << "SQLITE OP " << rc << std::endl;
    return 0;

}
