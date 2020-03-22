/**
 * Example assembly functions from CSCI 366 lectures
 */

#include <stdio.h>
#include <inttypes.h>
#include <vector>

using namespace std;

extern "C" int64_t examples(int64_t, int64_t);

extern "C" int get_elem(vector<int>*, int i, int j);


int main() {
   int *i = 0;
   printf("%ld\n", examples(1, 2));

   vector< vector<int>> A(5, vector<int>(3));
   A[2][0] = 3;
   A[2][1] = 5;
   A[2][2] = 7;
   printf("%ld\n", get_elem(A.data(),2, 0));

   return 0;
}