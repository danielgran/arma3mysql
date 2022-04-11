#include <cstring>

#include "arma3mysql/mysql/MySQLConnectionParam.h"
#include "extension/Extension.h"

using namespace std;

// These are the defines so that the library can be loaded by the ArmA3 Engine
extern "C"
{
void RVExtension(char *output, int outputSize, const char *function);
void RVExtensionVersion(char *output, int outputSize);
int RVExtensionArgs(char *output, int outputSize, const char *function, const char **argv, int argc);
};

static int alreadyLaunched = 0;
static Extension *Main;

void RVExtension(char *output, int outputSize, const char *function) {
  if (alreadyLaunched == 0) {
    Main = new Extension();
    alreadyLaunched = 1;
  }
  string returnValue;
  returnValue = Main->ProcessCommand((string) function);
  strcpy(output, returnValue.c_str());
}

void RVExtensionVersion(char *output, int outputSize) {
  string returnValue;
  returnValue = Extension::GetVersion();
  strcpy(output, returnValue.c_str());
}


int main() {
  char *return_value = (char *) malloc(10000);
  RVExtension(return_value, 1000, "version");
  printf("%s", return_value);
}