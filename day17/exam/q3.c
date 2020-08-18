#include <stdio.h>

typedef struct file
{
  short a, b;
  int c;
  char d[5];
} file;

int main()
{
  int buf[15] = {0,};
  file *p;
  FILE *fp = fopen("q1.dat", "rb");
  
  fread(buf, sizeof(int), 13, fp);
  p = (file *)&buf;

  short ans = (p->a) +(p->b);
  //ans += (p->c);

  printf("%x\n", ans);
  
  int ans1 = 0;
  for(int i=0; i<5; i++)
  {
    ans1 += p->d[i];
  }
  printf("%x ", ans1);

  fclose(fp);
  return 0;
}