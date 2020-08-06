#include <stdio.h>

int main(){
  char a = 0x12, b = 0x34;
  short c = 0x5678;
//  int t;

  char *pa, *pb;
  short *pc;
  pa = &a;
  pb = &b;
  pc = &c;

  *(pa+1) = *pb;
  *(short*)(pa+3) = *pc;
  printf("%x \n", *pa); //12
  printf("%x \n", *(pa+1)); //34
  printf("%x \n", *(short*)(pa+3)); //5678
  
  int *pt;
  pt = (int*)pa;
  //*(pt+1) = (int*)&b;
  //*(pt+3) = (int*)&c;
  int t;
  t = *pt;
  printf("%x \n", t); 
  return 0;
}