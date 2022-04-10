#include "testlib.h"
#include <dlfcn.h>

#ifdef __APPLE__
#define PATH "../arma3mysql/libarma3mysql_lib.dylib"
#endif
#ifdef __linux__
#define PATH "../arma3mysql/libarma3mysql_lib.so"
#endif

string testlib::callExtension(string& param) {

  void *libhandle = dlopen(PATH, RTLD_LAZY);
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

