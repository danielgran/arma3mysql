#pragma once
#include <string>
using namespace std;

class Extension {
public:
    static string GetVersion();
    string ProcessCommand(string command);
};