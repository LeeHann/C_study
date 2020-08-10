#include <stdio.h>
#include <SDL2/SDL.h>

int main(int argc, char *argv[])
{
  SDL_Rect rect = {10, 20, 300, 400};

  /*
  rect.x = 0;
  rect.y = 0;
  rect.h = 100;
  rect.w = 100;
*/

  SDL_Rect *pRect;
  pRect = &rect;

  printf("%d %d %d %d\n",
         pRect->x,
         pRect->y,
         pRect->h,
         pRect->w);
  return 0;
}