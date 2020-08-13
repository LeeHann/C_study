#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "text_lable.h"

S_TextLable *createLable(SDL_Renderer *pRenderer,
                         int x, int y, Uint16 nID,
                         const Uint16 *text,
                         TTF_Font *pFont)
{
  S_TextLable *pObj = SDL_malloc(sizeof(S_TextLable));

  pObj->m_Rect.x = x;
  pObj->m_Rect.y = y;
  pObj->m_nID = nID;

  //라벨생성
  {
    SDL_Color _whiteColor = {0xff, 0xff, 0xff, 0xff};
    SDL_Color _blackColor = {0, 0, 0, 0x00};
    SDL_Surface *textSurface = TTF_RenderUNICODE_Solid(pFont, text, _whiteColor);
    pObj->m_pLableTxture = SDL_CreateTextureFromSurface(pRenderer, textSurface);

    pObj->m_Rect.w = textSurface->w;
    pObj->m_Rect.h = textSurface->h;

    SDL_FreeSurface(textSurface);
  }
  return pObj;
}

void TextLable_destory(S_TextLable *pObj)
{
  SDL_DestroyTexture(pObj->m_pLableTxture);
  SDL_free(pObj);
}

void TextLable_render(S_TextLable *pObj, SDL_Renderer *pRender)
{
  SDL_SetRenderDrawBlendMode(pRender, SDL_BLENDMODE_BLEND);

  SDL_RenderCopy(pRender,pObj->m_pLableTxture,NULL,&pObj->m_Rect);

  SDL_SetRenderDrawBlendMode(pRender, SDL_BLENDMODE_NONE);
}