#include "MySQLConnectionParam.h"


MySQLConnectionParam::MySQLConnectionParam(string hostname, int port, string schema, string username, string password) {
    this->Hostname = hostname;
    this->Port = port;
    this->Schema = schema;
    this->Username = username;
    this->Password = password;
}
