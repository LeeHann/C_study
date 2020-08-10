#include <stdio.h>

int main(){
  int data = 3;
  int **pp;
  int my_ptr = (int)&data;

  pp = (int **)&my_ptr;

  //임베디드 시스템에서 하드웨어 제어하는 코드 예제
  //int portnum = 1000;
  //*((int *)portnum) = 1;
  //*((char *)0x7000) = 1;

  printf("%d \n", **pp); //3
  
  (**pp)++;
  printf("%d \n", data); //4

  **pp = 5;
  printf("%d \n", data); //5
  return 0;
}