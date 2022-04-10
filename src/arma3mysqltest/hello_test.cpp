#include "gtest/gtest.h"
#include "library/string/helper.h"
#include "library/testlib.h"

using namespace std;

GTEST_TEST(Integration, GetVersion) {
  string callparam = "version";
  string a = testlib::callExtension(callparam);

  ASSERT_EQ(a, "1.0");
}


TEST(Integration, Connection) {
    string callparam = "database add root@192.168.59.1";
    string return_string = testlib::callExtension(callparam);

    ASSERT_EQ(return_string, "ok");

}