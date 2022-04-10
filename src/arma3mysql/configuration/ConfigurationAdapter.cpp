#include "ConfigurationAdapter.h"

#include <fstream>
#include <vector>

Configuration::ConfigurationAdapter::ConfigurationAdapter() {
  init = new CSimpleIniA();
  init->SetUnicode(true);
}

void Configuration::ConfigurationAdapter::SaveSampleConfig() {
  ofstream sampleConfigFile;
  sampleConfigFile.open(sampleConfigName);
  sampleConfigFile << sampleData;
  sampleConfigFile.close();
}

bool Configuration::ConfigurationAdapter::ConfigurationExistant() {
  ifstream configFile;
  configFile.open(sampleConfigName);
  if (configFile.is_open())
    return true;
  return false;
}

void Configuration::ConfigurationAdapter::Initialize() {
  if (!ConfigurationExistant())
    this->SaveSampleConfig();
}

map<string, MySQLConnectionParam *> *Configuration::ConfigurationAdapter::LoadMySQLConfiguration() {
  CSimpleIniA::TNamesDepend sections;
  init->GetAllSections(sections);

  auto *returnVector = new map<string, MySQLConnectionParam *>();

  LoadSectionsFromFile(sections, returnVector);
  return returnVector;
}

void Configuration::ConfigurationAdapter::LoadSectionsFromFile(
    CSimpleIniTempl<char, SI_GenericNoCase<char>, SI_ConvertA<char>>::TNamesDepend &sections,
    map<string, MySQLConnectionParam *> *returnVector) const {
  for (const auto &a: sections) {
    string dbname = a.pItem;
    string hostname, port, schema, username, password;

    hostname = init->GetValue(dbname.c_str(), "hostname");
    port = init->GetValue(dbname.c_str(), "port");
    schema = init->GetValue(dbname.c_str(), "schema");
    username = init->GetValue(dbname.c_str(), "username");
    password = init->GetValue(dbname.c_str(), "password");

    auto *param = new MySQLConnectionParam(hostname,
                                           stoi(port),
                                           schema,
                                           username,
                                           password);
    returnVector->insert(pair<string, MySQLConnectionParam *>(dbname, param));
  }
}


void Configuration::ConfigurationAdapter::LoadConfiguration() {
  SI_Error rc = init->LoadFile(sampleConfigName.c_str());
  if (rc < 0) throw std::invalid_argument("Could not load file.");
}
