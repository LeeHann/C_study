#include <stdio.h>

void foo(){
  printf("hello function foo1 \n");
}

void foo2(){
  printf("hello function foo2 \n");
}

void foo3(char *msg){
  printf("%s \n", msg);
}

int foo4(int a, int b){
  return a+b;
}

int main(){
  void (*p)();

  p = foo;
  p();
  p = foo2;
  p();
  
  void (*p2)(char *);

  p2 = foo3;
  p2("hello function foo3");

  int (*p3)();
  p3 = foo4;
  printf("%d\n", p3(1, 2));

  return 0;
}