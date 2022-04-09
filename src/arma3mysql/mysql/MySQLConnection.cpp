//
// Created by danielgran on 4/9/22.
//

#include "MySQLConnection.h"
#include "boost/format.hpp"
#include "jdbc/cppconn/driver.h"


MySQLConnection::MySQLConnection(string schema, MySQLConnectionParam *param) {
    this->Schema = schema;

    this->connectionParam = param;

    this->mysqlDriver = get_driver_instance();

    boost::format fmt = boost::format("tcp://%1%:%2%") % this->connectionParam->Hostname % this->connectionParam->Port;
    string connectionString = boost::str(fmt);
    mysqlConnection = mysqlDriver->connect(connectionString.c_str(), connectionParam->Username, connectionParam->Password);
    mysqlConnection->setSchema(Schema.c_str());
}
