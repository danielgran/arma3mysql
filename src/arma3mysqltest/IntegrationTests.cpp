#include "gtest/gtest.h"
#include "library/string/helper.h"
#include "library/testlib.h"

using namespace std;

TEST(IntegrationTest, GetVersion) {
  string callparam = "version";
  string a = testlib::callExtension(callparam);

  ASSERT_EQ(a, "1.0");
}


TEST(IntegrationTest, Connection) {
  string callparam = "database connect SampleServer";
  string a = testlib::callExtension(callparam);

  ASSERT_EQ(a, "ok");
}