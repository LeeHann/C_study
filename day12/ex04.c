#include <stdio.h>

int main(){
  char szBuf[32];
  gets(szBuf);

  FILE *fp = fopen("test.txt", "wt");

  if(!fp){
    printf("file open error\n");
  }
  else{
    printf("open success\n");
    int _count = fprintf(fp, "%s\n", szBuf);
    printf("%d byte write \n", _count);

    short data = 0x412;
    int _count1 = fprintf(fp, "%x\n", data);
    printf("%d byte write \n", _count1);
  }

  fclose(fp);
  return 0;
}