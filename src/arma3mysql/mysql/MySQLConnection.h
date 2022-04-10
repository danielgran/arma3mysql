#pragma once

#include <string>
#include "jdbc/cppconn/driver.h"
#include "jdbc/cppconn/connection.h"
#include "jdbc/cppconn/statement.h"
#include "jdbc/cppconn/resultset.h"
#include "MySQLConnectionParam.h"

using namespace std;


class MySQLConnection {
private:
    MySQLConnectionParam *connectionParam;

    string Schema;

    sql::Driver *mysqlDriver;
    sql::Connection *mysqlConnection;
public:
    MySQLConnection(string schema, MySQLConnectionParam *param);

    void Connect();

    void Disconnect();

    sql::ResultSet *executeQuery(string query);

};

