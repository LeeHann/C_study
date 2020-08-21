#include "../engine/core.h"
#include "../engine/tile.h"
#include "cmd_parser.h"

tDE_S_Core *g_pEngineCore;
SDL_Texture *g_pTileSet;
Sint16 g_worldMap_Layer_1[256];
Sint16 g_attrMMap_Layer_1[256];
Uint16 g_nSelectTileIndex = 0;

SDL_Rect g_rtTilePalette = {660, 0, 256, 716};
SDL_Rect g_rtWordMap = {0, 0, 512, 512};

SDL_bool g_bDrawGrid = SDL_TRUE;
Sint16 g_nCurrentAttr = 0;

int main(int argc, char *argv[])
{
  memset(g_worldMap_Layer_1, -1, sizeof(Sint16) * 256);
  memset(g_attrMMap_Layer_1, 0, sizeof(Sint16) * 256);

  g_pEngineCore = tDE_setup_1("MAP", 960, 720, 0);
  g_pTileSet = tDE_util_loadTexture(g_pEngineCore, "../res/gb_ft_rpg_tile_set.png");
  //160*448 / 10*28

  SDL_bool bLoop = SDL_TRUE;
  while (bLoop)
  {
    SDL_Renderer *pRender = g_pEngineCore->m_pRender;
    SDL_SetRenderDrawColor(pRender, 0, 0, 0, 1);
    SDL_RenderClear(pRender);

    // 480,0
    putTile(pRender, g_pTileSet, 6.5, 13, g_nSelectTileIndex, 16, 10, 3);

    //render palette
    {
      //660,0 / 256*716
      SDL_SetRenderDrawColor(pRender, 0xff, 0xff, 0xff, 0xff);
      SDL_RenderDrawRect(pRender, &g_rtTilePalette);

      SDL_Rect _dstRt = {660, 0, 160 * 1.6, 448 * 1.6};
      SDL_RenderCopy(pRender, g_pTileSet, NULL, &_dstRt);
    }

    //render map
    {
      SDL_SetRenderDrawColor(pRender, 0xff, 0xff, 0xff, 0xff);
      SDL_RenderDrawRect(pRender, &g_rtWordMap);

      //basic world map layer
      for (int i = 0; i < 256; i++)
      {
        Sint16 _index = g_worldMap_Layer_1[i];
        if (_index != -1)
        {
          putTile(pRender, g_pTileSet, (i % 16), (i / 16), _index, 16, 10, 2);
        }
      }

      //attr layer
      for (int i = 0; i < 256; i++)
      {
        SDL_SetRenderDrawBlendMode(pRender, SDL_BLENDMODE_BLEND);
        Sint16 _index = g_attrMMap_Layer_1[i];

        if (_index == 1) // wall or sth
        {
          SDL_SetRenderDrawColor(pRender, 0xff, 0xff, 0xff, 0x80);
          SDL_Rect _rt = {(i % 16) * 32, (i / 16) * 32, 32, 32};
          SDL_RenderFillRect(pRender, &_rt);
        }
        else if (_index == 2) // door or stair
        {
          SDL_SetRenderDrawColor(pRender, 0x00, 0xff, 0x00, 0x80);
          SDL_Rect _rt = {(i % 16) * 32, (i / 16) * 32, 32, 32};
          SDL_RenderFillRect(pRender, &_rt);
        }
        else if (_index == 3) // switch
        {
          SDL_SetRenderDrawColor(pRender, 0xff, 0xff, 0x00, 0x80);
          SDL_Rect _rt = {(i % 16) * 32, (i / 16) * 32, 32, 32};
          SDL_RenderFillRect(pRender, &_rt);
        }
        else if (_index == 4) // 숨은 문
        {
          SDL_SetRenderDrawColor(pRender, 0x00, 0xff, 0xff, 0x80);
          SDL_Rect _rt = {(i % 16) * 32, (i / 16) * 32, 32, 32};
          SDL_RenderFillRect(pRender, &_rt);
        }
        SDL_SetRenderDrawBlendMode(pRender, SDL_BLENDMODE_NONE);
      }

      //render grid
      if (g_bDrawGrid)
      {
        for (int ix = 0; ix < 16; ix++)
        {
          SDL_SetRenderDrawColor(pRender, 0xff, 0xff, 0x00, 0xff);
          SDL_RenderDrawLine(pRender,(ix * 32), 0, (ix * 32), 512);
        }
        for (int iy = 0; iy < 16; iy++)
        {
          SDL_SetRenderDrawColor(pRender, 0xff, 0xff, 0x00, 0xff);
          SDL_RenderDrawLine(pRender, 0, (iy * 32), 512, (iy * 32));
        }
      }
    }
    SDL_RenderPresent(pRender);

    SDL_Event _event;
    while (SDL_PollEvent(&_event))
    {
      static char szBuf[64];
      static Uint16 nInputFSM = 0;

      switch (_event.type)
      {
      case SDL_MOUSEMOTION:
      {
        SDL_Point m_pt = {_event.motion.x, _event.motion.y};
        if (_event.button.button == 1)
        {
          if (SDL_PointInRect(&m_pt, &g_rtWordMap) && !g_bDrawGrid)
          {
            putMap(m_pt.x / 32, m_pt.y / 32, g_nSelectTileIndex, g_worldMap_Layer_1, 16);
          }
        }
        else if (_event.button.button == 4 && !g_bDrawGrid) //우 클릭
        {
          if (SDL_PointInRect(&m_pt, &g_rtWordMap))
          {
            putMap(m_pt.x / 32, m_pt.y / 32, -1, g_worldMap_Layer_1, 16);
          }
        }
      }
      break;
      case SDL_MOUSEBUTTONDOWN:
      {
        SDL_Point mousePt = {_event.motion.x, _event.motion.y};
        printf("%8d\r", _event.button.button);

        if (_event.button.button == 1) //마우스 좌클릭
        {
          if (SDL_PointInRect(&mousePt, &g_rtTilePalette)) //palette handling
          {
            int _x = (_event.motion.x - 660) / (16 * 1.6);
            int _y = (_event.motion.y - 0) / (16 * 1.6);

            if ((_x >= 0 && _y >= 0) && (_x < 10 && _y < 28))
            {
              g_nSelectTileIndex = _y * 10 + _x;
            }
          }
          else if (SDL_PointInRect(&mousePt, &g_rtWordMap)) //map handling
          {
            int _x = (_event.motion.x) / 32;
            int _y = (_event.motion.y) / 32;

            if (g_bDrawGrid) //속성 바꾸기
            {
              g_attrMMap_Layer_1[_x + _y * 16] = g_nCurrentAttr;

              printf("%3d,%3d,%3d,%3d\r", _x, _y,
                     g_attrMMap_Layer_1[_x + _y * 16],
                     g_nCurrentAttr);
            }
            else
            {
              putMap(_x, _y, g_nSelectTileIndex, g_worldMap_Layer_1, 16);
            }
          }
        }
        else if (_event.button.button == 3) //마우스 우클릭
        {
          if (SDL_PointInRect(&mousePt, &g_rtWordMap))
          {
            int _x = (_event.motion.x) / 32;
            int _y = (_event.motion.y) / 32;
            putMap(_x, _y, -1, g_worldMap_Layer_1, 16);
          }
        }
      }
      break;
      case SDL_KEYDOWN:
      {
        switch (nInputFSM)
        {
        case 0: //대기상태
        {
          if (_event.key.keysym.sym == SDLK_RETURN)
          {
            printf("input cmd => \n");
            nInputFSM = 1; //입력 상태로 전이
          }
          else if (_event.key.keysym.sym == SDLK_g)
          {
            g_bDrawGrid = !g_bDrawGrid;
          }
          else if (_event.key.keysym.sym == SDLK_1)
          {
            parseCmd("brush change 1");
          }
          else if (_event.key.keysym.sym == SDLK_2)
          {
            parseCmd("brush change 2");
          }
          else if (_event.key.keysym.sym == SDLK_3)
          {
            parseCmd("brush change 3");
          }
          else if (_event.key.keysym.sym == SDLK_4)
          {
            parseCmd("brush change 4");
          }
          else if (_event.key.keysym.sym == SDLK_0)
          {
            parseCmd("brush change 0");
          }
        }
        break;
        case 1: //입력 상태
        {

          if (_event.key.keysym.sym == SDLK_RETURN)
          {
            nInputFSM = 0; //대기 상태로 전이
            //cmd parser
            {
              parseCmd(szBuf);
            }

            szBuf[0] = 0x00; //문자열 클리어
          }
          else if (_event.key.keysym.sym == SDLK_BACKSPACE)
          {
            int _len = strlen(szBuf);
            szBuf[_len - 1] = 0x00;
            printf("%s  \r", szBuf);
          }
        }
        break;
        default:
          break;
        }
      }
      break;
      case SDL_TEXTINPUT:
      {
        if (nInputFSM == 1)
        {
          strcat(szBuf, _event.text.text);
          printf("%s  \r", szBuf);
        }
      }
      break;
      case SDL_USEREVENT:
      {
        if (strcmp(_event.user.data1, "brush change") == 0)
        {
          g_nCurrentAttr = _event.user.code;
          printf("change brush %d \n", g_nCurrentAttr);
        }
        else if (strcmp(_event.user.data1, "save") == 0)
        {
          char *pFileName = ((char *)_event.user.data1 + 16);
          Sint16 *map[2] = {g_worldMap_Layer_1, g_attrMMap_Layer_1};
          saveMap(pFileName, map);

          printf("save file name %s \n", pFileName);
        }
        else if (strcmp(_event.user.data1, "load") == 0)
        {
          char *pFileName = ((char *)_event.user.data1 + 16);
          Sint16 *map[2] = {g_worldMap_Layer_1, g_attrMMap_Layer_1};
          loadMap(pFileName, map);
        }
        else if (strcmp(_event.user.data1, "new") == 0)
        {
          memset(g_worldMap_Layer_1, -1, sizeof(g_worldMap_Layer_1));
          memset(g_attrMMap_Layer_1, 0, sizeof(g_attrMMap_Layer_1));
        }
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

  SDL_DestroyTexture(g_pTileSet);
  tDE_closeCore(g_pEngineCore);
  SDL_Quit();
  return 0;
}