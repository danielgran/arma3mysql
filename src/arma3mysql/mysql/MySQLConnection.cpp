#include "MySQLConnection.h"
#include "boost/format.hpp"
#include "mariadb/conncpp.hpp"


MySQLConnection::MySQLConnection(MySQLConnectionParam *param) {
  this->connectionParam = param;
  this->mysqlDriver = sql::mariadb::get_driver_instance();
}

void MySQLConnection::Connect() {
  try {

  boost::format fmt = boost::format("jdbc:mariadb://%1%:%2%/%3%") % this->connectionParam->Hostname % this->connectionParam->Port % this->connectionParam->Hostname;
  string connectionString = boost::str(fmt);
  mysqlConnection = mysqlDriver->connect(connectionString.c_str(), connectionParam->Username,
                                         connectionParam->Password);
  mysqlConnection->setSchema((*connectionParam).Schema);
  } catch (sql::SQLException& e) {
    return;
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