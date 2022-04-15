#include "MySQLConnection.h"
#include "boost/format.hpp"
#include "jdbc/cppconn/driver.h"


MySQLConnection::MySQLConnection(MySQLConnectionParam *param) {
  this->connectionParam = param;
  this->mysqlDriver = get_driver_instance();
}

void MySQLConnection::Connect() {
  boost::format fmt = boost::format("tcp://%1%:%2%") % this->connectionParam->Hostname % this->connectionParam->Port;
  string connectionString = boost::str(fmt);
  mysqlConnection = mysqlDriver->connect(connectionString.c_str(), connectionParam->Username,
                                         connectionParam->Password);
  mysqlConnection->setSchema((*connectionParam).Schema);
}

void MySQLConnection::Disconnect() {
  delete mysqlConnection;
}

sql::ResultSet* MySQLConnection::executeQuery(string query) {
  if(!mysqlConnection)
    Connect();
  sql::Statement *statement = this->mysqlConnection->createStatement();
  return statement->executeQuery(query);
}