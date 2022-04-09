#include "MySQLConnectionParam.h"


MySQLConnectionParam::MySQLConnectionParam(string hostname, int port, string username, string password) {
    this->Port = port;
    this->Hostname = hostname;
    this->Username = username;
    this->Password = password;
}
