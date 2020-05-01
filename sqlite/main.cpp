#include <iostream>
#include <sqlite_modern_cpp.h>

using namespace  sqlite;
using namespace std;

int main() {

   try{
      database db("company.sqlite");

      db << "select Fname from EMPLOYEE;"
         >> [&](string fname) {
            cout << fname << endl;
         };
   }
   catch (exception& e) {
      cout << e.what() << endl;
   }
}
