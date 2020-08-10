#include <stdio.h>
#include <malloc.h>

typedef unsigned int UI;
typedef unsigned char UC;
typedef UC * pc;

typedef int MyData[5];

int main(){
  unsigned int a = 1;
  UI b = 2;
  UC c = 128;
  
  pc ptr; // = unsigned char *ptr;
  ptr = &c;
  
  MyData _p = {1,2,3,4,5};
  MyData *p;
  p = &_p;

  printf("%d %d %d %d %d\n", a, b, c, *ptr, *p[0]);
  return 0;
}