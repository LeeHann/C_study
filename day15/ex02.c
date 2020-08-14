#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "../engine/text_lable.h"
#include "../engine/button.h"

const Uint16 WINDOW_WIDTH = 640;
const Uint16 WINDOW_HEIGHT = 480;

SDL_Window *g_pWindow;
SDL_Renderer *g_pRenderer;
TTF_Font *g_pFont;

SDL_bool bLoop = SDL_TRUE;

S_TextLable *g_pLabelMainmenu;
S_BUTTON *g_pBtnExit;

void callbackExitButtonPush(S_BUTTON *pBtn)
{
  bLoop = SDL_FALSE;
}

int main(int argc, char *argv[])
{
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }

  g_pWindow = SDL_CreateWindow("GAME", // creates a window
                             SDL_WINDOWPOS_CENTERED,
                             SDL_WINDOWPOS_CENTERED,
                             WINDOW_WIDTH, WINDOW_HEIGHT, 0);
  if (!g_pWindow)
  {
    printf("error initializing SDL window: %s\n", SDL_GetError());
    return 1;
  }

  g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, SDL_RENDERER_ACCELERATED);
  if(!g_pRenderer)
  {
    printf("cant setup renderer : %s \n", SDL_GetError());
    return 1;
  }

  TTF_Init();
  g_pFont = TTF_OpenFont("../../adv/sdl/res/nmf.ttf", 28);

  g_pLabelMainmenu = createLable(g_pRenderer, 0,0,1,
                                L"메인메뉴",
                                g_pFont
                                );
  g_pBtnExit = createButton(g_pRenderer, 0, 30, 64, 32, 2, L"종료", g_pFont, callbackExitButtonPush);
  
  while (bLoop)
  {
    SDL_SetRenderDrawColor(g_pRenderer, 0x00,0xff,0x00,0xff);
    SDL_RenderClear(g_pRenderer);

    //라벨 랜더링 ..
    g_pLabelMainmenu->m_fpRender(g_pLabelMainmenu, g_pRenderer);
    //버튼 랜더링
    g_pBtnExit->m_fpRender(g_pBtnExit, g_pRenderer);

    SDL_RenderPresent(g_pRenderer);

    SDL_Event _event;
    while (SDL_PollEvent(&_event))
    {
      g_pBtnExit->m_fpDoEvent(g_pBtnExit, &_event);
      switch (_event.type)
      {
      case SDL_KEYDOWN:
        printf("%d \n", _event.key.keysym.scancode);
        break;
      case SDL_QUIT:
        bLoop = SDL_FALSE;
        break;
      default:
        break;
      }
    }
  }

  g_pBtnExit->m_fpDestory(g_pBtnExit);
  g_pLabelMainmenu->m_fpDestory(g_pLabelMainmenu);

  TTF_CloseFont(g_pFont);
  SDL_DestroyRenderer(g_pRenderer);
  SDL_DestroyWindow(g_pWindow);
  SDL_Quit();
  return 0;
}