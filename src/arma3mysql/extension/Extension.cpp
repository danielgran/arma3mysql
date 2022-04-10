#include "Extension.h"
#include <vector>
#include "boost/algorithm/string.hpp"

#include "../configuration/ConfigurationAdapter.h"


const string Extension::CMD_VERSION = "version";

Extension::Extension() {
  Configuration::ConfigurationAdapter *p = new Configuration::ConfigurationAdapter();
  p->Initialize();
  p->LoadConfiguration();
  ConnectionParams = p->LoadMySQLConfiguration();
  delete p;
  Connections = new map<string, MySQLConnection *>;
}


string Extension::GetVersion(void) {
  return "1.0";
}

string Extension::ProcessCommand(string command) {
  if (command == CMD_VERSION) {
    return GetVersion();
  }

  try {
    vector<string> args;
    boost::split(args, command, boost::is_any_of(" "));

    if (args.at(0) == "database") {
      if (args.at(1) == "connect") {
        string databaseConfigName = args.at(2);

        auto connectionParam = ConnectionParams->at(databaseConfigName);
        auto *connection = new MySQLConnection(connectionParam);
        Connections->insert(pair<string, MySQLConnection *>(databaseConfigName, connection));
        connection->Connect();
        return "ok";
      }
    }
  } catch (exception &e) {
    return "error";
  }
  return "Unknown command.";
}