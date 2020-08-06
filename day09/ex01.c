#include <stdio.h>

int main(){
  const int *pb; // 값 읽기만 가능 - 값 변경 불가능
  int *pa;
  int num = 3;
  int num2 = 9; 
  int * const pc = &num2; //주소값 읽기만 가능 - 주소 변경 불가능

  pa = &num;
  pb = pa;
//  *pb = 7; 
  *pa = 7;
//  pc = pa; 

  printf("%d %d\n", *pb, *pc); 
  return 0;
}