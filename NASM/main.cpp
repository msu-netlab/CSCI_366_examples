/**
 * Example assembly functions from CSCI 366 lectures
 */

#include <stdio.h>
#include <inttypes.h>
#include <vector>

using namespace std;


/**
 * define a rectangle structure Rect, so we can use in get_rect_area as a parameter type
 */
struct Rect {
   int llx;
   int lly;
   char color;
   double width;
   double height;
};


extern "C" int64_t examples(int64_t, int64_t);
extern "C" int get_2D_array_element(int [][3], int i, int j);
extern "C" int get_2D_vector_element(vector<int>*, int i, int j);
extern "C" double get_rect_area(Rect *r);
extern "C" bool get_bit(int data, int mask);


int main() {

   /**
    * uncomment the code below to run examples.asm
    * contains examples of arithmetic and program control instructions
    */
//   printf("%ld\n", examples(1, 2));

   /**
    * uncomment the code below to run get_2D_array_element.asm
    * contains an example of accessing two dimensional integer array
    */
//   int A[5][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}, {13, 14, 15}};
//   printf("%d\n", get_2D_array_element(A, 1, 2));

   /**
    * uncomment the code below to run get_2D_vector_element.asm
    * contains an example of accessing two dimensional vector data in assembly
    */
//   vector< vector<int>> A(5, vector<int>(3));
//   A[2][0] = 3;
//   A[2][1] = 5;
//   A[2][2] = 7;
//   printf("%d\n", get_2D_vector_element(A.data(), 2, 0));

   /**
    * uncomment the code below to write get_rect_area.asm
    * contains an example of computing the area of a rectangle stored as a structure
    */
//   Rect r = {1, 1, 0, 1.5, 3};
//   printf("the size of the rect structure is %lu\n", sizeof(Rect));
//   printf("rectangle area is %.1f\n", get_rect_area(&r));

   /**
    * uncomment the code below to write get_rect_area.asm
    * contains an example of computing the area of a rectangle stored as a structure
    */
   int data = 8;
   int mask = 1 << 3;
   printf("bit is %d\n", get_bit(data, mask));

   return 0;
}