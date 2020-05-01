#include <iostream>
#include <sqlite_modern_cpp.h>

using namespace sqlite;
using namespace std;

int main() {

   /**
    * See https://github.com/SqliteModernCpp/sqlite_modern_cpp for more examples
    */

   try{
      database db("company.sqlite");

      db << "select Bdate, Address from EMPLOYEE where Fname = ? and Lname = ?;"
         << "John"
         << "Smith"
         >> [&](string Bdate, string Address) {
            cout << Bdate << ' ' << Address << endl;
         };
   }
   catch (exception& e) {
      cout << e.what() << endl;
   }
}
