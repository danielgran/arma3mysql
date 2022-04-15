#include "ResultSetAdapter.h"

using namespace std;

MySQL::ResultSetAdapter::ResultSetAdapter(ResultSet *mysqlResultSet) : MySQLResultSet(mysqlResultSet) {}

ArmA3ExtensionResult *MySQL::ResultSetAdapter::GetResult() {

  list<string> arrays;

  string armaReturnString = "[";
  while (MySQLResultSet->next()) {
    armaReturnString.append("[");
    auto meta = MySQLResultSet->getMetaData();

    for (int i = 1; i <= meta->getColumnCount(); i++) {
      string typeAsString = meta->getColumnTypeName(i);

      if (typeAsString == "VARCHAR") {
        armaReturnString.append("\"" + MySQLResultSet->getString(i) + "\"");
      }

      armaReturnString.append("],");
    }
  }
  // Remove the last ","
  armaReturnString.pop_back();
  armaReturnString += "]";
  return new ArmA3ExtensionResult(armaReturnString);

}
