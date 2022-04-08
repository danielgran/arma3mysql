#include "jdbc/cppconn/driver.h"
#include "jdbc/cppconn/resultset.h"
#include "jdbc/cppconn/statement.h"
#include <iostream>

using namespace std;

int main() {

    sql::Driver *driver = get_driver_instance();

    sql::Connection *connection = driver->connect("localhost", "root", "");

    connection->setSchema("arma3");

    sql::Statement *stmt = connection->createStatement();
    sql::ResultSet *res = stmt->executeQuery("SELECT 'Hello World!' AS _message");
    while (res->next()) {
        cout << "\t... MySQL replies: ";
        /* Access column data by alias or column name */
        cout << res->getString("_message") << endl;
        cout << "\t... MySQL says it again: ";
        /* Access column data by numeric offset, 1 is the first column */
        cout << res->getString(1) << endl;
    }


    connection->nativeSQL("SHOW PROCESSLIST");


}
