#include "../engine/core.h"
#include "../engine/tile.h"

tDE_S_Core *g_pEngineCore;
Sint16 g_WorldMap[64];
Sint16 g_WorldMap_attr_layer[64] = {
  1,1,1,1,1,1,1,1,
  1,0,0,0,0,0,0,1,
  1,0,0,0,0,0,0,1,
  1,0,0,0,0,0,0,1,
  1,0,0,0,0,0,0,1,
  1,0,0,0,0,0,0,1,
  1,0,0,0,0,0,0,1,
  1,1,1,1,1,1,1,1
};

SDL_Texture *g_pTileSet;
SDL_Texture *g_pTileSet2;

int main(int argc, char* argv[])
{
  g_pEngineCore = tDE_setup_1("game", 640, 480, 0);
  g_pTileSet = tDE_util_loadTexture(g_pEngineCore, "../res/dungeon.png");
  g_pTileSet2 = tDE_util_loadTexture(g_pEngineCore, "../res/gb_ft_rpg_tile_set.png");
  //10/28
  loadMap("./l1.map", g_WorldMap);

  SDL_bool bLoop = SDL_TRUE;
  while(bLoop)
  {
    SDL_SetRenderDrawColor(g_pEngineCore->m_pRender, 0x00,0x00,0xff,0xff);
    SDL_RenderClear(g_pEngineCore->m_pRender);

    //world map
    drawWorld(g_pEngineCore->m_pRender, g_pTileSet, 16,5,2,0,0,8,g_WorldMap);

    //character
    putTile(g_pEngineCore->m_pRender, g_pTileSet2, 0,0,190,16,10,2);

    SDL_RenderPresent(g_pEngineCore->m_pRender);

    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
      switch(event.type)
      {
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
  return 0;
}