#include "gtest/gtest.h"
#include "library/testlib.h"

TEST(HelloTest, BasicAssertions) {


  string a = callExtension((string &) "test");
#ifdef __APPLE__
  printf("Hello Apple");
#endif
  printf("%s", a.c_str());


// Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
// Expect equality.
  EXPECT_EQ(7 * 6, 42);
}