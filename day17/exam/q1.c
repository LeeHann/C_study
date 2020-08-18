#include <stdio.h>
#include <stdlib.h>

typedef struct _S_Data
{
  short a;
  short b;
  int c;
  char d[5];
} S_Data;

int main()
{
  S_Data *pdata = malloc(sizeof(S_Data));
  FILE *fp = fopen("q1.dat", "rb");
  fread(pdata, sizeof(S_Data), 1, fp);

  printf("%4x%4x%4x\n", pdata->a, pdata->b, pdata->c);

  for(int i=0; i<5; i++)
  {
    printf("%4x", pdata->d[i]);
  }
  
  fclose(fp);
  printf("done!\n");
  return 0;
}