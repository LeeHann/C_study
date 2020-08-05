#include <stdio.h>
#include <SDL2/SDL.h>

int main(int argc, char *argv[]){
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }
  unsigned int b = 0x12345678;
  //unsigned char d = 0x00;
  //unsigned short e = 0x0000;
  Uint8 d = 0x00; //unsigned int 8 진수
  Uint16 e = 0x0000;

  d = b;
  e = b;
  printf("%x \n", d); // 큰 수를 작은 범위 안에 넣으면 값이 잘림
  printf("%x \n", e);


  SDL_Quit();
  return 0;
}