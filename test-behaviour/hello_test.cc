#include <dlfcn.h>
#include "gtest/gtest.h"

TEST(HelloTest, BasicAssertions) {


  void *libhandle = dlopen("../arma3mysql/libarma3mysql.dylib", RTLD_LAZY);

  void (*func)(char*, int, const char*);
  func = (void (*)(char*, int, const char*))dlsym(libhandle, "RVExtension");

  char* a = (char*)malloc(10);

  func(a, 100, "test");

  printf("%s", a);


// Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
// Expect equality.
  EXPECT_EQ(7 * 6, 42);
}