#pragma once

#include <string>
#include "mariadb/conncpp.hpp"
#include "MySQLConnectionParam.h"


using namespace std;

class MySQLConnection {
private:
    MySQLConnectionParam *connectionParam;
    sql::Driver *mysqlDriver;
    sql::Connection *mysqlConnection;
public:
    MySQLConnection(MySQLConnectionParam *param);

    void Connect();
    void Disconnect();

    sql::ResultSet *executeQuery(string query);

};

