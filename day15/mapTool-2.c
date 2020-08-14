//불러온 맵을 저장된 다른 맵으로 교체하는 swap 버튼 (맵 선택지 3개)
//맵 크기에 따라 캐릭터가 갈 수 있는 거리를 한정 짓기
//맵 클리어 버튼

#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "../engine/ui/ui_base.h"
#include "../engine/ui/button.h"

int doTokenize(char *szBuf, char szBufToken[][32]);
void putTile(SDL_Renderer *pRenderer, SDL_Texture *pTex, Uint16 _x, Uint16 _y, Uint16 _index);

const Uint16 WINDOW_WIDTH = 640;
const Uint16 WINDOW_HEIGHT = 480;

SDL_Window *gWindow;
SDL_Renderer *g_pRenderer;
SDL_Texture *g_pTileTexture;

SDL_Texture *g_pChtrTexture;

TTF_Font *g_pFont;
S_BUTTON *g_pSwapButton;
S_BUTTON *g_pClearButton;

Uint16 g_worldMap_Layer_1[64];
Uint16 g_nSelectTileIndex = 0;

void processCmd(char *_szCmd, SDL_bool *bLoop)
{
  static char szCmd[32];
  static char szTokens[8][32];

  strcpy(szCmd, _szCmd);

  printf("token count %s\n", szCmd);
  int _numToken = doTokenize(szCmd, szTokens);

  printf("token count %d\n", _numToken);

  if (strcmp(szTokens[0], "quit") == 0)
  {
    *bLoop = SDL_FALSE;
  }
  else if (strcmp(szTokens[0], "setTile") == 0)
  {
    //setTile x y index
    int _x = SDL_atoi(szTokens[1]);
    int _y = SDL_atoi(szTokens[2]);
    int _index = SDL_atoi(szTokens[3]);

    g_worldMap_Layer_1[(_y * 8) + _x] = _index;
  }
  else if (strcmp(szTokens[0], "save") == 0)
  {
    //save file.map
    char *pFileName = szTokens[1];
    SDL_RWops *rw = SDL_RWFromFile(pFileName, "wb");
    SDL_RWwrite(rw, g_worldMap_Layer_1, sizeof(Uint16), 64);
    SDL_RWclose(rw);
  }
  else if (strcmp(szTokens[0], "load") == 0)
  {
    char *pFileName = szTokens[1];
    SDL_RWops *rw = SDL_RWFromFile(pFileName, "rb");
    SDL_RWread(rw, g_worldMap_Layer_1, sizeof(Uint16), 64);
    SDL_RWclose(rw);
  }
}

void onPushClear(S_BUTTON *pBtn)
{
  for(int i=0; i<64; i++)
    g_worldMap_Layer_1[i] = -1;
}

void onPushSwap(S_BUTTON *pBtn)
{
  onPushClear(&pBtn);
  
}

int main(int argc, char *argv[])
{
  for (int i = 0; i < 64; i++)
    g_worldMap_Layer_1[i] = -1;

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }

  gWindow = SDL_CreateWindow("GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);

  if (!gWindow)
  {
    printf("error initializing SDL window: %s\n", SDL_GetError());
    return 1;
  }
  g_pRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
  {
    SDL_Surface *surface;
    surface = IMG_Load("../res/dungeontiles.png");
    SDL_Texture *tex = SDL_CreateTextureFromSurface(g_pRenderer, surface);
    SDL_FreeSurface(surface);
    g_pTileTexture = tex;
  }

  //Initialize SDL_ttf
  if (TTF_Init() == -1)
  {
    printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
    return 0;
  }
  else
  {
    printf("SDL_ttf initialize Ok!  \n");
  }

  //LOAD font file
  g_pFont = TTF_OpenFont("../../adv/sdl/res/nmf.ttf", 28);

  if (!g_pFont)
  {
    printf("font file load error");
    printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
    return 0;
  }
  else
  {
    printf("font load ok!\n");
  }

  int nTileIndex = 0;
  int nInputFSM = 0; //0 -> ready , 1-> text input

  //캐릭터 텍스쳐
  {
    SDL_Surface *textSf = IMG_Load("../res/characters.png");
    g_pChtrTexture = SDL_CreateTextureFromSurface(g_pRenderer, textSf);
    SDL_FreeSurface(textSf);
  }
  SDL_Point _position = {0, 0};

  g_pSwapButton = myui_createButton(g_pRenderer, 540, 400, 90, 40, 1, L"SWAP", g_pFont, onPushSwap);
  g_pClearButton = myui_createButton(g_pRenderer, 430, 400, 100, 40, 2, L"CLEAR", g_pFont, onPushClear);

  static char strBuf[32] = {0,};
  SDL_bool bLoop = SDL_TRUE;
  while (bLoop)
  {
    SDL_SetRenderDrawColor(g_pRenderer, 0x00, 0x00, 0x00, 0xff);
    SDL_RenderClear(g_pRenderer);

    //select tile
    putTile(g_pRenderer, g_pTileTexture, 15, 0, g_nSelectTileIndex);

    //440,100
    {
      //pallete Rendering
      SDL_Rect _dstRt = {440, 100, 48 * 4, 72 * 4};
      SDL_RenderCopy(g_pRenderer, g_pTileTexture, NULL, &_dstRt);
    }

    //render world map
    {
      for (int i = 0; i < 64; i++)
      {
        int _index = g_worldMap_Layer_1[i];
        if (_index != -1)
        {
          putTile(g_pRenderer, g_pTileTexture, i % 8, i / 8, _index);
        }
      }
    }

    {//chracter Rect
      SDL_Rect srcRt = {16, 0, 16, 16};
      SDL_Rect dstRt = {_position.x * 32, _position.y * 32, 16 * 2, 16 * 2};
      SDL_RenderCopy(g_pRenderer, g_pChtrTexture, &srcRt, &dstRt);
    }
    //swap button Rendering
    g_pSwapButton->m_base.m_fpRender(g_pSwapButton, g_pRenderer);
    g_pClearButton->m_base.m_fpRender(g_pClearButton, g_pRenderer);

    // for multiple rendering
    SDL_RenderPresent(g_pRenderer);

    SDL_Event _event;
    while (SDL_PollEvent(&_event))
    {
      g_pSwapButton->m_base.m_fpDoEvent(g_pSwapButton, &_event);
      g_pClearButton->m_base.m_fpDoEvent(g_pClearButton, &_event);
      switch (_event.type)
      {
      case SDL_MOUSEBUTTONDOWN:
      {
        printf("%8d\r", _event.button.button);
        if (_event.button.button == 1) //좌클릭
        { //팔레트 처리
          {
            int _x = (_event.motion.x - 440) / 32;
            int _y = (_event.motion.y - 100) / 32;

            if ((_x >= 0 && _y >= 0) && (_x < 6 && _y < 9))
              g_nSelectTileIndex = _y * 6 + _x;
          }
          //월드맵 처리
          {
            int _x = (_event.motion.x) / 32;
            int _y = (_event.motion.y) / 32;

            if (_x < 8 && _y < 8)
            {
              int _tileIndex = _y * 8 + _x;
              g_worldMap_Layer_1[_tileIndex] = g_nSelectTileIndex;
            }
          }
        }
        else if (_event.button.button == 3) //우클릭
        {
          int _x = (_event.motion.x) / 32;
          int _y = (_event.motion.y) / 32;

          if (_x < 8 && _y < 8)
          {
            int _tileIndex = _y * 8 + _x;
            g_worldMap_Layer_1[_tileIndex] = -1;
          }
        }
      }
      break;
      case SDL_KEYDOWN:
        if (_event.key.keysym.scancode == 82) //up
          if(_position.y > 0) _position.y -= 1;
        else if (_event.key.keysym.scancode == 81) //down
          if(_position.y <= 6) _position.y += 1;
        else if (_event.key.keysym.scancode == 80) //left
          if(_position.x > 0) _position.x -= 1;
        else if (_event.key.keysym.scancode == 79) //right
          if(_position.x <= 6) _position.x += 1;
      
        if (_event.key.keysym.sym == SDLK_RETURN)
        {
          if (nInputFSM == 0)
          {
            printf("input msg : \n");
            SDL_StartTextInput();
            nInputFSM = 1;
          }
          else if (nInputFSM == 1)
          {
            printf("\n%s\n", strBuf);
            processCmd(strBuf, &bLoop);

            strBuf[0] = 0x00;
            SDL_StopTextInput();
            nInputFSM = 0;
          }
        }
        else if (_event.key.keysym.sym == SDLK_BACKSPACE)
        {
          int _count = strlen(strBuf);
          if (_count > 0) //버퍼에 값이 존재 할때만...
          {
            _count--;
            strBuf[_count] = 0x00;
            printf("%s \r", strBuf);
          }
        }
        break;
      case SDL_TEXTINPUT:
      {
        strcat(strBuf, _event.text.text);
        printf("%s \r", strBuf);
      }
      break;
      case SDL_QUIT:
        bLoop = SDL_FALSE;
        break;
      default:
        break;
      }
    }
  }

  g_pClearButton->m_base.m_fpDestory(g_pClearButton);
  g_pSwapButton->m_base.m_fpDestory(g_pSwapButton);

  SDL_DestroyTexture(g_pChtrTexture);
  TTF_CloseFont(g_pFont);
  SDL_DestroyTexture(g_pTileTexture);
  SDL_DestroyRenderer(g_pRenderer);
  SDL_DestroyWindow(gWindow);
  SDL_Quit();
  return 0;
}