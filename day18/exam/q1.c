#include <stdio.h>
#include <stdlib.h>

typedef struct File
{
  char name[8];
  short x;
  short y;
  short w;
  short h;
}file;

int main()
{
  file *p = malloc(sizeof(file));
  FILE *fp = fopen("sheet.dat", "rb");

  
  while(fread(p, sizeof(file), 1, fp))
    printf("%s, %d %d %d %d\n", p->name, p->x, p->y, p->w, p->h);
  
  free(p);
  fclose(fp);
  return 0;
}