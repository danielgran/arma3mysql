#include "jdbc/cppconn/driver.h"
#include "jdbc/cppconn/resultset.h"
#include "jdbc/cppconn/statement.h"
#include <iostream>
#include <cstring>

extern "C"
{
void RVExtension(char *output, int outputSize, const char *function);
void RVExtensionVersion(char *output, int outputSize);
int RVExtensionArgs(char *output, int outputSize, const char *function, const char **argv, int argc);
};

using namespace std;

void RVExtension(char *output, int outputSize, const char *function) {
  strcpy(output, "Hello World.");
}
