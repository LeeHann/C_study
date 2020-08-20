#include <stdio.h>

typedef struct PTR{
  short a;
  short b;
  char c;
  char d;
} ptr;

int main(int argc, char* argv[])
{
  char data[] = {0x07, 0x00, 0x08, 0x00, 0x05, 0x03};
  ptr *p;

  p = (ptr *)&data;

  printf("%d %d %d %d\n", p->a, p->b, p->c, p->d);
  printf("%d", (p->a)+(p->b)+(p->c)+(p->d));
  
  return 0;
}