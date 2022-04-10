#pragma once
#include <string>
using namespace std;


class MySQLConnectionParam {
public:
    string Hostname;
    int Port;
    string Schema;
    string Username;
    string Password;

public:
    MySQLConnectionParam(string hostname, int port, string schema, string username, string password);

};