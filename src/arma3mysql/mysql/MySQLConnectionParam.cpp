#include "MySQLConnectionParam.h"

#include <utility>


MySQLConnectionParam::MySQLConnectionParam(string hostname, int port, string schema, string username, string password) {
    this->Hostname = std::move(hostname);
    this->Port = port;
    this->Schema = std::move(schema);
    this->Username = std::move(username);
    this->Password = std::move(password);
}
