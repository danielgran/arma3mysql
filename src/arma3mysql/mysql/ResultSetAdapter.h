#pragma once

#include "mariadb/conncpp.hpp"
#include "arma3mysql/extension/ArmA3ExtensionResult.h"

using namespace sql;

namespace MySQL {
    class ResultSetAdapter {
    private:
        ResultSet *MySQLResultSet;
    public:
        ResultSetAdapter(ResultSet *mysqlResultSet);

        ArmA3ExtensionResult *GetResult();
    };
}
