#include "jdbc/cppconn/driver.h"
#include "jdbc/cppconn/resultset.h"
#include "jdbc/cppconn/statement.h"
#include "arma3mysql/mysql/MySQLConnectionParam.h"
#include "arma3mysql/mysql/MySQLConnection.h"
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
    strcpy(output, "Hello aWorld");
    alreadyLaunched = 1;

  }
}

int main(){
    char* return_value = (char*)malloc(100);
    RVExtension(return_value, 100, "version");

    printf("%s", return_value);
    MySQLConnectionParam* params = new MySQLConnectionParam("127.0.0.1", 3306, "root", "");

    MySQLConnection* connection = new MySQLConnection("arma3", params);
    connection->Connect();

    printf("%s", params->Username.c_str());



    delete params;
    delete connection;


}