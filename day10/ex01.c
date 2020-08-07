#include <stdio.h>

int main(){
  int data[3] = {0x12345678, 0x12345678, 0x12345678};
  
  //data[0] = 0x00;//       0
  //*(data+0) = 0x00;//       0
  *(char *)(data+0) = 0x00;//12345600 리틀엔디언으로 들어가기 때문에 뒤집혀서 들어감
  
  printf("%8x \n", data[0]);
  
  //data[1]
  *((char *)data + 6) = 0x00; //12005678
  printf("%8x \n", data[1]); 

  //data[2]
  *((short *)data +4) = 0x0000; //12340000
  printf("%8x \n", data[2]);

  return 0;
}