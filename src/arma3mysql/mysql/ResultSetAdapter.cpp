#include "ResultSetAdapter.h"

#include <sstream>
#include <iomanip>

#include "boost/algorithm/string.hpp"

using namespace std;

MySQL::ResultSetAdapter::ResultSetAdapter(ResultSet *mysqlResultSet) : MySQLResultSet(mysqlResultSet) {}

string toproper(string str) {
  return to_string(stoi(str));
}

string toDigits(string str, int digits) {
  double decimal = stod(str);
  stringstream sstream;
  sstream << std::fixed << std::setprecision(digits) << decimal;
  return sstream.str();
}


ArmA3ExtensionResult *MySQL::ResultSetAdapter::GetResult() {

  list<string> arrays;

  string armaReturnString = "[";
  while (MySQLResultSet->next()) {
    armaReturnString.append("[");
    auto meta = MySQLResultSet->getMetaData();

    for (int i = 1; i <= meta->getColumnCount(); i++) {
      string typeAsString = meta->getColumnTypeName(i);
      string valueAsString = MySQLResultSet->getString(i);

      if (typeAsString == "VARCHAR")
        armaReturnString.append("\"" + valueAsString + "\"");
      else if (typeAsString == "BIGINT")
        armaReturnString.append(valueAsString);
      else if (typeAsString == "DECIMAL")
        armaReturnString.append(toDigits(valueAsString, 4));
      else if (typeAsString == "DATE") {
        vector<string> date;
        boost::split(date, valueAsString, boost::is_any_of("-"));

        armaReturnString.append("[" + toproper(date.at(0)) + "," + toproper(date.at(1)) + "," +
                                toproper(date.at(2)) + "]");
      } else if (typeAsString == "DATETIME") {
        vector<string> rawData;
        boost::split(rawData, valueAsString, boost::is_any_of(" "));
        string dates = rawData.at(0);
        string times = rawData.at(1);
        vector<string> date, time;
        boost::split(date, dates, boost::is_any_of("-"));
        boost::split(time, times, boost::is_any_of(":"));

        armaReturnString.append("[" + toproper(date.at(0)) + "," + toproper(date.at(1)) + "," +
                                toproper(date.at(2)) + "," + toproper(time.at(0))
                                + "," + toproper(time.at(1)) + "," + toproper(time.at(2)) + "]");


      }

      armaReturnString.append("],");
    }
  }
  armaReturnString.pop_back();
  armaReturnString += "]";
  return new ArmA3ExtensionResult(armaReturnString);

}

