#pragma once

#include <string>
#include "../mysql/MySQLConnectionParam.h"
#include "../mysql/MySQLConnection.h"


using namespace std;

class Extension {
private:
    map<string, MySQLConnectionParam *> *ConnectionParams;
    map<string, MySQLConnection *> *Connections;
public:
    Extension();

    static string GetVersion();

    string ProcessCommand(string command);
};