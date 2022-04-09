#include "gtest/gtest.h"
#include "library/string/helper.h"
#include "library/testlib.h"

using namespace std;

TEST(Initialisation, BasicAssertions) {
  string callparam = "version";
  string a = testlib::callExtension(callparam);

  string find = ".";
  bool contains_string = stringlib::contains(a, find);
  EXPECT_TRUE(contains_string);

}