//
// Created by Daniel Gran on 10.04.22.
//

#include "Extension.h"
#include <cstring>
#include <vector>
#include "boost/algorithm/string.hpp"

const static string CMD_VERSION = "version";

string Extension::GetVersion(void) {
  return "1.0";
}

string Extension::ProcessCommand(string command) {
  if (command == CMD_VERSION) {
    return "1.0";
  }

  vector<string> args;
  boost::split(args, command, boost::is_any_of(" "));

  if(args.at(0) == "database"){
    if(args.at(1) == "add") {
      string databaseConfigName = args.at(2);
      // Resolve configuration
      return "ok";
    }
  }

  return "";
}
