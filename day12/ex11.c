#include <SDL2/SDL.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
  SDL_Rect _rect;
  _rect.x = 10;
  _rect.y = 20;
  _rect.w = 100;
  _rect.h = 150;
  
  SDL_RWops *rw = SDL_RWFromFile("test2.bin", "wb");
  SDL_RWwrite(rw, &_rect, sizeof(SDL_Rect), 1);
  
  SDL_RWclose(rw);

  return 0;
}