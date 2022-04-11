#include "Extension.h"
#include <vector>
#include "boost/algorithm/string.hpp"

#include "../configuration/ConfigurationAdapter.h"


Extension::Extension() {
  auto *p = new Configuration::ConfigurationAdapter();
  p->Initialize();
  p->LoadConfiguration();
  ConnectionParams = p->LoadMySQLConfiguration();
  delete p;
  Connections = new map<string, MySQLConnection *>;
}

string Extension::GetVersion() {
  return "1.0";
}

string Extension::ProcessCommand(string command) {
  try {
    vector<string> args;
    boost::split(args, command, boost::is_any_of(" "));

    if (args.at(0) == "version") {
      return GetVersion();
    }

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