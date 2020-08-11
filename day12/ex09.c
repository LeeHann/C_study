#include <stdio.h>

int main()
{
  unsigned char data[8] = {10,20,30,00,50,60,70,80};
  
  FILE *fp;
  fp = fopen("test.bin", "wb");
  
  fwrite(data, sizeof(unsigned char), 8, fp);

  fclose(fp);
  printf("done ! \n");
  return 0;
}