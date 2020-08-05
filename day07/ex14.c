#include <stdio.h>
#include <SDL2/SDL.h>
#include <string.h>

void _copyStr(int nStartIndex,int nEndIndex,char src[],char dest[])
{
  int j = 0;
  for(int i = nStartIndex; i<nEndIndex; i++){
    dest[j] = src[i];
    j++; 
  }
}

char data[] = "kor,mat,eng,bio,phy,earth";
char buf1[16];
char buf2[16];
char buf3[16];
char buf4[16];
char buf5[16];
char buf6[16];

int main(int argc,char *argv[])
{
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }
  
  int ck = 0, start = 0, end = 0;
  for(int i=0; i<strlen(data); i++){
    if(data[i] == ','){
      ck++;
      end=i;
    }
    switch(ck){
      case 1:
        _copyStr(start, end, data, buf1);
        start = end+1;
        break;
      case 2:
        _copyStr(start, end, data, buf2);
        start = end+1;
        break;
      case 3:
        _copyStr(start, end, data, buf3);
        start = end+1;
        break;
      case 4:
        _copyStr(start, end, data, buf4);
        start = end+1;
        break;
      case 5:
        _copyStr(start, end, data, buf5);
        start = end+1;
        break;
    }
    if(i==strlen(data)-1){
      end = strlen(data);
        _copyStr(start, end, data, buf6);
    }
  }
  printf("%s\n", buf1);
  printf("%s\n", buf2);
  printf("%s\n", buf3);
  printf("%s\n", buf4);
  printf("%s\n", buf5);
  printf("%s\n", buf6);
  SDL_Quit();
  return 0;
}