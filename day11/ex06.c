#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main(){
  char **pNames;
  int _count;

  printf("input name count : ");
  scanf("%d", &_count);
  rewind(stdin);

  pNames = (char **)malloc(sizeof(char *) * _count);

  for(int i=0; i<_count; i++){
    char buf[32];
    gets(buf);
    int _size = strlen(buf)+1;
    pNames[i] = (char *)malloc(_size);
    strcpy(pNames[i], buf);
  }

  for(int i=0; i<_count; i++){
    printf("%s\n", pNames[i]);
    free(pNames[i]);
  }
  
  free(pNames);
  return 0;
}