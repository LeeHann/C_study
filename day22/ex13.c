#include <stdio.h>

typedef struct file{
  short a;
  short b;
  long c;
}file;

int main()
{
  FILE *fp = fopen("t1.bin", "rb");

  file *p;
  
  fread(p, sizeof(file), 1, fp);

  printf("%d %d %d", p->a, p->b, p->c);
  
  fclose(fp);

  return 0;
}