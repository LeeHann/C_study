#include <stdio.h>

//#define __DEBUG__
void test(){
  #ifdef __DEBUG__
  printf("debug mode");
  #endif
  printf("hello define\n");
}

#define MSG "hello"

#define MYINT int
typedef int _MYINT;

int main(){
  test();

  //puts("hello");
  puts(MSG);

  //int a = 1;
  //MYINT a = 1;
  _MYINT a = 1;

  return 0;
}