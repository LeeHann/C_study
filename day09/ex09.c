#include <stdio.h>

int main(){
  char input_str[8];
  
  int i;
  for(i=0; i<7; i++){
    char _c = getchar(); //메모리를 사용하지 않고 버퍼에 접근 가능
    printf("input char : %c \n", _c);
    input_str[i] = _c;
  }

  input_str[i] = 0x00;
  printf("%s\n", input_str);

  return 0;
}