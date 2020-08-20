#include <stdio.h>

int main(int argc, char* argv[])
{
  char data[] = {0x07, 0x00, 0x08, 0x00, 0x05, 0x03};
  
  short a = *(short *)data;
  short b = *(short *)(data+2);
  char c = *(data+4);
  char d = data[5];

  printf("%d+%d+%d+%d = %d\n", a,b,c,d,(a+b+c+d));

  return 0;
}