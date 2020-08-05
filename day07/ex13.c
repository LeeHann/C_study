#include <stdio.h>
#include <SDL2/SDL.h>
#include <string.h>

int main(int argc, char *argv[])
{
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }

  char data[] = "kor,mat,eng,bio,phy,earth";
  int ck = 0;
  char buf[256];

  char buf1[16];
  char buf2[16];
  char buf3[16];
  char buf4[16];
  char buf5[16];
  char buf6[16];
  /*
  for(int i=0; i<strlen(data); i++){
    if(data[i] == ','){
      check++;
      switch(check){
        case 1:
          strncpy(buf1, buf, i);
          printf("%s \n", buf1);
          buf[0] = 0;
          break;
        case 2:
          strncpy(buf2, buf, i);
          printf("%s \n", buf2);
          buf[0] = 0;
          break;
      }
      continue;
    }
    buf[i] = data[i];
  }
*/
  int ckValue = 0;
  for (int i = 0; i < strlen(data); i++)
  {
    if (data[i] == ',')
    {
      ck++;
      ckValue = i;
      continue;
    }
    switch (ck)
    {
    case 0:
      buf1[i - ckValue] = data[i];
      break;
    case 1:
      buf2[i - ckValue - 1] = data[i];
      break;
    case 2:
      buf3[i - ckValue - 1] = data[i];
      break;
    case 3:
      buf4[i - ckValue - 1] = data[i];
      break;
    case 4:
      buf5[i - ckValue - 1] = data[i];
      break;
    case 5:
      buf6[i - ckValue - 1] = data[i];
      break;
    }
  }
  printf("\n%s\n%s\n%s\n%s\n%s\n%s\n", buf1, buf2, buf3, buf4, buf5, buf6);
  SDL_Quit();
  return 0;
}