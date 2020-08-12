#include <stdio.h>

int _sum(int a, int b){
  return a+b;
}

int _sub(int a, int b){
  return a-b;
}

int main(){
  int (*p[2])(int, int);
  p[0] = _sum;
  p[1] = _sub;

  for(int i=0; i<2; i++){
    printf("%d \n", p[i](1, 2));
  }

  return 0;
}