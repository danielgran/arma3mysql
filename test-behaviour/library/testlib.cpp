#include "testlib.h"

string callExtension(string& param) {
  void *libhandle = dlopen("../arma3mysql/libarma3mysql.dylib", RTLD_LAZY);
  try {
    void (*func)(char*, int, const char*);
    func = (void (*)(char*, int, const char*))dlsym(libhandle, "RVExtension");
    char* returnstring = (char*)malloc(1000);
    func(returnstring, 1000, param.c_str());
    return returnstring;
  } catch (exception e){
    dlclose(libhandle);
  }

  return "asd";


}