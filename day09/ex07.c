#include <SDL2/SDL.h>
#include <stdio.h>

int main(int argc, char *argv[]){
  SDL_bool bLoop = SDL_TRUE;

  while(bLoop){
    printf("exit now? (1.yes 2.no 3.print app version 4.start game 5.connect network) : ");
    Sint8 sel = getchar();
    rewind(stdin);
    if(sel == '1') bLoop = SDL_FALSE;
    else if(sel == '3') printf("app version 1.0 \n");
    else if(sel == '4') printf("now launch game client! \n");
    else if(sel == '5') printf("connecting now... \n");
  }

  return 0;
}