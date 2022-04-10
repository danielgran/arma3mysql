#include "gtest/gtest.h"
#include "library/string/helper.h"
#include "library/testlib.h"

using namespace std;

GTEST_TEST(Initialisation, Integration) {
  string callparam = "version";
  string a = testlib::callExtension(callparam);

  string find = ".";
  bool contains_string = stringlib::contains(a, find);
  EXPECT_TRUE(contains_string);

}


TEST(Connection, Integration) {
    string callparam = "database add root@192.168.59.1";
    string return_string = testlib::callExtension(callparam);

    ASSERT_EQ(return_string, "ok");

}