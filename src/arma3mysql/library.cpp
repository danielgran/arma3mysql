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

static int alreadyLaunched = 0;

void RVExtension(char *output, int outputSize, const char *function) {

  if (strcmp(function, "version") == 0){
    strcpy(output, "1.0");
    return;
  }

  if(alreadyLaunched)
    strcpy(output, "I was not launched the first time");
  else {
    strcpy(output, "Hello World");
    alreadyLaunched = 1;

  }
}
