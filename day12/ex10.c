#include <stdio.h>

int main()
{
  unsigned char data;

  FILE *fp;
  fp = fopen("test.bin", "rb");
  fseek(fp, 2, SEEK_SET); //파일의 시작 위치부터 2바이트 이동한 곳
  fread(&data, sizeof(unsigned char), 1, fp);
  printf("%d \n", data);

  fseek(fp, 0, SEEK_SET);
  fread(&data, sizeof(unsigned char), 1, fp);
  printf("%d \n", data);

  fclose(fp);
  return 0;
}