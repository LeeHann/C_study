#include <stdio.h>

void test(const int *_a, int * const _b){
//  *_a = 11; // const int value '_a' read-only 
//  _b = _a; // assignment of read-only parameter '_b'
  printf("%d %d\n", *_a, *_b);
}

int main(){
  int a = 10;
  int b = 11;
  test(&a, &b);
  return 0;
}