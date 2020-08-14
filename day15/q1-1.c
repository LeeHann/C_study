#include <stdio.h>

typedef struct _test
{
  unsigned char a;
  unsigned char b;
  unsigned char c;
  unsigned char d;
} S_TEST;


int main()
{
  int a = 0x12345678;
  S_TEST *p = (S_TEST *)&a;

  printf("%3x%3x%3x%3x\n",p->a,p->b,p->c,p->d);
  
  return 0;
}