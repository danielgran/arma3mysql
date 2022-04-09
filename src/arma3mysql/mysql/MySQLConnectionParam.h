#pragma once
#include <string>
using namespace std;


class MySQLConnectionParam {
public:
    string Hostname;
    int Port;
    string Username;
    string Password;

public:
    MySQLConnectionParam(string hostname, int port, string username, string password);

};