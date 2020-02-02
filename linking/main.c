//#include <stdio.h>

#define A array

int sum(int *a, int n);

int A[2] = {1, 2};

int main()
{
  int val = sum(A, 2);
  //printf("%d\n", val);
  return val;
}
