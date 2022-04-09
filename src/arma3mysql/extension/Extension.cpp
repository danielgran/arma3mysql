#include <map>
#include "../mysql/MySQLConnection.h"


class Extension {
public:
    std::map<MySQLConnection*, int> Connections;


};


