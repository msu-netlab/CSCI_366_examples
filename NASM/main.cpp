/**
 * Example assembly functions from CSCI 366 lectures
 */

#include <stdio.h>
#include <inttypes.h>


extern "C" int64_t examples(int64_t, int64_t);

extern "C" int64_t maxofthree(int64_t, int64_t, int64_t);

int main() {
   int *i = 0;
   printf("%ld\n", examples(1, 2));
//   printf("%ld\n", maxofthree(1, -4, -7));
//   printf("%ld\n", maxofthree(2, -6, 1));
//   printf("%ld\n", maxofthree(2, 3, 1));
//   printf("%ld\n", maxofthree(-2, 4, 3));
//   printf("%ld\n", maxofthree(2, -6, 5));
//   printf("%ld\n", maxofthree(2, 4, 6));
   return 0;
}