//little endian , big endian
#include <stdio.h>

int main()
{
  char a[][4] = {
      {0x1, 0x10, 0x00, 0x00},
      {0x2, 0x20, 0x00, 0x00},
      {0x3, 0x00, 0x30, 0x00},
      {0x4, 0x00, 0x40, 0x00},
      {0x5, 0x00, 0x00, 0x50}};
  char b[5][4];

  int a1, a2, a3, a4, a5;
  int sum;

  a1 = *(int *)a[0];
  a2 = *(int *)a[1];
  a3 = *(int *)a[2];
  a4 = *(int *)a[3];
  a5 = *(int *)a[4];

  sum = a1 + a2 + a3 + a4 + a5;

  //little endian
  printf("%8x\n%8x\n%8x\n%8x\n%8x\n%8x\n", a1, a2, a3, a4, a5, sum);
  printf("\n");
  
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      b[i][j] = a[i][4 - (j+1)];
    }
  }

  a1 = *(int *)b[0];
  a2 = *(int *)b[1];
  a3 = *(int *)b[2];
  a4 = *(int *)b[3];
  a5 = *(int *)b[4];

  sum = a1 + a2 + a3 + a4 + a5;

  //big endian
  printf("%8x\n%8x\n%8x\n%8x\n%8x\n%8x\n", a1, a2, a3, a4, a5, sum);

  return 0;
}