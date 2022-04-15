#include "gtest/gtest.h"
#include "../library/testlib.h"
#include "arma3mysql/extension/ArmA3ExtensionResult.h"

using namespace std;

TEST(UnitTest_ArmA3ExtensionResult, Construction) {

  ArmA3ExtensionResult* a3Result = new ArmA3ExtensionResult("{}");
  delete a3Result;


}

