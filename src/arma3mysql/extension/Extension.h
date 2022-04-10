#pragma once

#include <string>
#include "../mysql/MySQLConnectionParam.h"
#include "../mysql/MySQLConnection.h"


using namespace std;

class Extension {
private:
    static const string CMD_VERSION;
    map<string, MySQLConnectionParam *> *ConnectionParams;
    map<string, MySQLConnection *> *Connections;
public:
    Extension();

    static string GetVersion();

    string ProcessCommand(string command);
};