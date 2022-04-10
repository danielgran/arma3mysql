//
// Created by Daniel Gran on 10.04.22.
//

#include "Extension.h"

const static string CMD_VERSION = "version";

string Extension::GetVersion(void) {
  return "1.0";
}

string Extension::ProcessCommand(string command) {
  if (command == CMD_VERSION){
    return "1.0";
  }
  return "";
}
