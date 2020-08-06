#include <stdio.h>

int main(){
  int input_data;
  
  input_data = getchar();
  rewind(stdin); //운영체제 내부에서 버퍼를 가리키는 포인터 함수
  printf("%d\n", input_data);

  //getchar();
  //printf("%d", input_data);
  
  input_data = getchar();
  printf("%d\n", input_data);
  
  return 0;
}