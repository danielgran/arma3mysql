#include "gtest/gtest.h"
#include "arma3mysql/configuration/ConfigurationAdapter.h"
#include "arma3mysql/mysql/MySQLConnectionParam.h"
#include <fstream>

using namespace Configuration;

TEST(UnitTest_Configuration, Construction) {
  ConfigurationAdapter *config;
  config = new ConfigurationAdapter();
}

TEST(UnitTest_Configuration, SaveSampleConfig) {
  ConfigurationAdapter *config = new ConfigurationAdapter();
  config->SaveSampleConfig();
  ifstream stream;
  stream.open(sampleConfigName);
  string contents, temp;
  while (std::getline(stream, temp)) {
    contents += temp + "\n";
  }
  string command = "rm " + sampleConfigName;
  std::system(command.c_str());
  ASSERT_EQ(contents, sampleData);
  delete config;
}

TEST(UnitTest_Configuration, TestExistantConfiguration) {
  ConfigurationAdapter *config = new ConfigurationAdapter();
  bool exists = config->ConfigurationExistant();
  ASSERT_FALSE(exists);
  delete config;
}

TEST(UnitTest_Configuration, TestInitialize) {
  ConfigurationAdapter *config = new ConfigurationAdapter();
  config->Initialize();
  bool exists = config->ConfigurationExistant();
  ASSERT_TRUE(exists);
  string command = "rm " + sampleConfigName;
  std::system(command.c_str());
  delete config;
}

TEST(UnitTest_Configuration, TestLoadFile) {
  ConfigurationAdapter (*config) = new ConfigurationAdapter();
  config->Initialize();
  config->LoadConfiguration();
  string command = "rm " + sampleConfigName;
  std::system(command.c_str());
}

TEST(UnitTest_Configuration, TestLoadMySQLConfiguration) {
  ConfigurationAdapter (*config) = new ConfigurationAdapter();
  config->Initialize();
  config->LoadConfiguration();
  map<string, MySQLConnectionParam*>* params;
  params = config->LoadMySQLConfiguration();

  string first_hostname = (*params->at(0)).Hostname;
  ASSERT_EQ(first_hostname, "127.0.0.1");
}
