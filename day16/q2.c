#include <stdio.h>

int main()
{
  int a = 0x00030002;
  short *t1, *t2;

  t1 = (short *)&a;
  *t2 = *(t1+1);

  printf("%d + %d = %d\n", *t1, *t2, *t1+*t2);

  return 0;
}