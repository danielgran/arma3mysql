#include "Extension.h"

#include <string>
#include <vector>
#include "boost/algorithm/string.hpp"

#include "../configuration/ConfigurationAdapter.h"
#include "../mysql/ResultSetAdapter.h"
#include "ArmA3ExtensionResult.h"


Extension::Extension() {
  auto *configurationAdapter = new Configuration::ConfigurationAdapter();
  configurationAdapter->Initialize();
  configurationAdapter->LoadConfiguration();
  ConnectionParams = configurationAdapter->LoadMySQLConfiguration();
  delete configurationAdapter;
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

        auto *connectionParam = ConnectionParams->at(databaseConfigName);
        auto *connection = new MySQLConnection(connectionParam);
        Connections->insert(pair<string, MySQLConnection *>(databaseConfigName, connection));
        connection->Connect();
        return "ok";
      }
      if (args.at(1) == "query") {
        string databaseConfigName = args.at(2);
        char *query;
        strtok((char *) command.c_str(), "###");
        query = strtok(NULL, "###");
        auto *connection = Connections->at(databaseConfigName);
        ResultSet *result = connection->executeQuery(query);

        auto *adapter = new MySQL::ResultSetAdapter(result);

        auto *a3result = adapter->GetResult();

        string returnString = a3result->Result;

        return returnString;

      }
    }
  } catch (exception &e) {
    return "error";
  }
  return "Unknown command.";
}