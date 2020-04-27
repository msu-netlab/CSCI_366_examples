#include <iostream>
#include <fstream>
#include <cereal/archives/json.hpp>
#include <cereal/types/vector.hpp>

using namespace std;

/**
 * An example of how to use cereal serialization and deserialization functions
 */
int main() {
   string fname = "array.json";

   // remove any old serialization files
   remove(fname.c_str());

   // create an integer array
   vector< int > array1(2);

   // set some value and print
   array1[1] = 1;
   printf("array1[0] = %d, array1[1] = %d\n", array1[0], array1[1]);

   // serialize the array
   ofstream array_ofp(fname); // create an output file stream
   // cereal archives are guaranteed to finish writing before leaving scope
   // to finalize writing, put serialization into its own scope
   {  // open scope
      cereal::JSONOutputArchive write_archive(array_ofp); // initialize an archive on the file
      write_archive(cereal::make_nvp("array", array1)); // serialize the data giving it a name
   } // close scope
   array_ofp.close(); // close the file


   // create a two dimensional array for deserialization
   vector< int > array2(2);

   // deserialize the array
   ifstream array_ifp(fname); // create an input file stream
   cereal::JSONInputArchive read_archive(array_ifp); // initialize an archive on the file
   read_archive(array2); // deserialize the array
   array_ifp.close(); // close the file

   // print the result of deserialization
   printf("array2[0] = %d, array2[1] = %d\n", array2[0], array2[1]);


   return 0;
}
