//
// Created by Daniel Gran on 10.04.22.
//

#include "Extension.h"
#include <vector>
#include "boost/algorithm/string.hpp"

#include "../configuration/ConfigurationAdapter.h"

const static string CMD_VERSION = "version";

Extension::Extension() {
  Configuration::ConfigurationAdapter *p = new Configuration::ConfigurationAdapter();
  p->Initialize();
  p->LoadConfiguration();
  connectionParams = p->LoadMySQLConfiguration();
  delete p;
  connections = new map<string, MySQLConnection *>;
}


string Extension::GetVersion(void) {
  return "1.0";
}

string Extension::ProcessCommand(string command) {
  if (command == CMD_VERSION) {
    return "1.0";
  }

  vector<string> args;
  boost::split(args, command, boost::is_any_of(" "));

  if (args.at(0) == "database") {
    if (args.at(1) == "connect") {
      string databaseConfigName = args.at(2);

      auto connectionParam = connectionParams->at(databaseConfigName);
      MySQLConnection* connection = new MySQLConnection(connectionParam);
      connections->insert(pair<string, MySQLConnection*>(databaseConfigName, connection));
      connection->Connect();
      return "ok";
    }
  }

  return "";
}