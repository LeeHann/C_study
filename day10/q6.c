#include <stdio.h>
#include <malloc.h>

int main(){
  char ***p = (char ***)malloc(2*3*4);
  
  free(p);

  return 0;
}