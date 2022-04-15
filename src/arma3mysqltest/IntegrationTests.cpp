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

TEST(IntegrationTest, TestText) {
  string callparam = "database connect SampleServer";
  string result = testlib::callExtension(callparam);
  callparam = "database query SampleServer ###SELECT 'Hello World' as message;";
  result = testlib::callExtension(callparam);
  ASSERT_EQ(result, "[[\"Hello World\"]]");
}

TEST(IntegrationTest, QueryTestInteger) {
  string callparam = "database connect SampleServer";
  string result = testlib::callExtension(callparam);
  callparam = "database query SampleServer ###SELECT 1 as message;###";
  result = testlib::callExtension(callparam);
  ASSERT_EQ(result, "[[1]]");
}

TEST(IntegrationTest, QueryTestFloat) {
  string callparam = "database connect SampleServer";
  string result = testlib::callExtension(callparam);
  callparam = "database query SampleServer ###SELECT 1.3 as message;###";
  result = testlib::callExtension(callparam);
  ASSERT_EQ(result, "[[1.3000]]");
}

TEST(IntegrationTest, QueryTestDate) {
  string callparam = "database connect SampleServer";
  string result = testlib::callExtension(callparam);
  callparam = "database query SampleServer ###select CAST(\"2012-1-1\" as date);###";
  result = testlib::callExtension(callparam);
  ASSERT_EQ(result, "[[[2012,1,1]]]");
}

