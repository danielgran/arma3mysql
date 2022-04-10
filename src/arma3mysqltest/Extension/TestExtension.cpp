#include "gtest/gtest.h"
#include "arma3mysql/extension/Extension.h"

using namespace std;

TEST(UnitTest_Extension, Construct) {
  Extension *extension = new Extension();

  ASSERT_NE(extension, nullptr);
}


TEST(UnitTest_Extension, GetVersion) {
  ASSERT_EQ("1.0", Extension::GetVersion());
}

TEST(UnitTest_Extension, ProcessCommand) {
  Extension *extension = new Extension();
  string ver = extension->ProcessCommand("version");

  ASSERT_EQ(ver, "1.0");
}