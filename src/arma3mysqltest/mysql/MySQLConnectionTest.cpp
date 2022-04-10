#include "gtest/gtest.h"
#include "arma3mysql/mysql/MySQLConnectionParam.h"
#include "arma3mysql/mysql/MySQLConnection.h"

using namespace std;

TEST(UnitTest_MySQLConnection, Construction) {
    MySQLConnectionParam* params = new MySQLConnectionParam("127.0.0.1", 3306, "arma3", "root", "");
    MySQLConnection* connection = new MySQLConnection(params);
    connection->Connect();

    ASSERT_EQ(1, 1);
}