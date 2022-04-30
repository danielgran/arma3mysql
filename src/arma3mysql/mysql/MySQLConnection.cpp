#include <iostream>
#include "MySQLConnection.h"
#include "boost/format.hpp"


MySQLConnection::MySQLConnection(MySQLConnectionParam *param) {
  this->connectionParam = param;
  this->mysqlDriver = sql::mariadb::get_driver_instance();
}

void MySQLConnection::Connect() {
  try {

  boost::format fmt = boost::format("jdbc:mariadb://%1%:%2%/%3%") % this->connectionParam->Hostname % this->connectionParam->Port % this->connectionParam->Schema;
  string connectionString = boost::str(fmt);
  sql::SQLString sqlstring(connectionString);
  mysqlConnection = mysqlDriver->connect(sqlstring, connectionParam->Username, "");
  mysqlConnection->setSchema((*connectionParam).Schema);
  } catch (sql::SQLException& e) {
    string message = e.what();
    std::cout << "Error connecting to database: " << message << std::endl;
  }
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