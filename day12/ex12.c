#include <SDL2/SDL.h>
#include <stdio.h>

int main(int argc,char *argv[])
{
  SDL_Rect _rect;

  SDL_RWops *rw = SDL_RWFromFile("test2.bin", "rb");

  SDL_RWread(rw,&_rect,sizeof(SDL_Rect),1);

  SDL_RWclose(rw);

  printf("x:%d,y:%d,w:%d,h:%d\n",_rect.x,_rect.y,_rect.w,_rect.h);

  return 0;
}