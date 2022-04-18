#pragma once

#include "simpleini-4.19/SimpleIni.h"
#include "arma3mysql/mysql/MySQLConnectionParam.h"

using namespace std;

namespace Configuration {
    const string sampleData = "[SampleServer]\n"
                              "hostname=192.168.59.1\n"
                              "port=3306\n"
                              "schema=arma3\n"
                              "username=root\n"
                              "password=\n";

    const string sampleConfigName = "arma3mysql-configuration.cfg";

    class ConfigurationAdapter {
    private:
        CSimpleIniA *init;
        void LoadSectionsFromFile(CSimpleIniTempl<char, SI_GenericNoCase<char>, SI_ConvertA<char>>::TNamesDepend &sections,
                                  map<string, MySQLConnectionParam *> *returnVector) const;
    public:
        ConfigurationAdapter();
        void SaveSampleConfig();

        bool ConfigurationExistant();

        void Initialize();

        map<string, MySQLConnectionParam*>* LoadMySQLConfiguration();

        void LoadConfiguration();
    };
}
