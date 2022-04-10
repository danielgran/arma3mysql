#include "gtest/gtest.h"
#include "arma3mysql/mysql/MySQLConnectionParam.h"
#include "arma3mysql/mysql/MySQLConnection.h"

using namespace std;

TEST(Construction, UnitTest) {
    MySQLConnectionParam* params = new MySQLConnectionParam("localhost", 3306, "schema", "root", "");
    MySQLConnection* connection = new MySQLConnection("arma3", params);
    connection->Connect();

    ASSERT_EQ(1, 1);
}