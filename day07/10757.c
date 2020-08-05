#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char a[10001], b[10001], carry[10001], ans[10001];

int main(){
  int i;

  scanf(" %s %s", a, b);
  int _size = (strlen(a) >= strlen(b) ? strlen(b) : strlen(a));
  
  for(i=0; i<_size; i++){
    char sum = carry[i-1] + a[strlen(a)-i] + b[strlen(b)-i];
    carry[i] = sum/10;
    ans[i] = sum%10;
  }

  int _reSize = (strlen(a) >= strlen(b) ? strlen(a) : strlen(b));
  for(i = _size-1 ; i<_reSize; i++){
    
  }
  return 0;
}