#include "gtest/gtest.h"
#include "arma3mysql/mysql/MySQLConnectionParam.h"
#include "arma3mysql/mysql/MySQLConnection.h"

using namespace std;

TEST(Construction, UnitTest) {

    check_lib();


    MySQLConnectionParam* params = new MySQLConnectionParam("localhost", 3306, "root", "");

    MySQLConnection* connection = new MySQLConnection("arma3", params);






    ASSERT_EQ(1, 1);

}