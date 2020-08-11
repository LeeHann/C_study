#include <stdio.h>

int main()
{
  char strBuf[32];
  FILE *fp = fopen("test3.txt", "rt");

  //while(EOF != fscanf(fp, "%s", strBuf))
  while(NULL != fgets(strBuf, sizeof(strBuf), fp))
  {
    puts(strBuf);
  }

  fclose(fp);
  return 0;
}