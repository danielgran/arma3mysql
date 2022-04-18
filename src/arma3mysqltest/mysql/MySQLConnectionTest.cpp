#include "gtest/gtest.h"
#include "arma3mysql/mysql/MySQLConnectionParam.h"
#include "arma3mysql/mysql/MySQLConnection.h"

using namespace std;

TEST(UnitTest_MySQLConnection, Construction) {
    auto* params = new MySQLConnectionParam("192.168.59.1", 3306, "arma3", "root", "");
    auto* connection = new MySQLConnection(params);
    connection->Connect();
}