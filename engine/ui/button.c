#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "ui_base.h"
#include "button.h"

static void _destory(void *pObj)
{
  S_BUTTON *pBtn = pObj;

  SDL_DestroyTexture(pBtn->m_pLable);
  SDL_free(pBtn);
}

static void _render(void *pObj, SDL_Renderer *pRender)
{
  S_BUTTON *pBtn=pObj;

  if (pBtn->m_base.m_bVisible)
  {
    //반투명 모드 활성화
    SDL_SetRenderDrawBlendMode(pRender, SDL_BLENDMODE_BLEND);

    SDL_SetRenderDrawColor(pRender, 255, 255, 255, 255);
    SDL_RenderDrawRect(pRender, &pBtn->m_Rect);

    SDL_SetRenderDrawColor(pRender, pBtn->m_fillColor.r, pBtn->m_fillColor.g, pBtn->m_fillColor.b,
                           pBtn->m_fillColor.a);
    SDL_RenderFillRect(pRender, &pBtn->m_Rect);

    pBtn->m_rectLabel.x = pBtn->m_Rect.x + 2;
    pBtn->m_rectLabel.y = pBtn->m_Rect.y + 2;
    pBtn->m_rectLabel.w = pBtn->m_Rect.w - 4;
    pBtn->m_rectLabel.h = pBtn->m_Rect.h - 4;

    SDL_RenderCopy(pRender, pBtn->m_pLable, NULL, &pBtn->m_rectLabel);

    //반투명 모드 비 활성화
    SDL_SetRenderDrawBlendMode(pRender, SDL_BLENDMODE_NONE);
  }
}

static void _doEvent(void *pObj, SDL_Event *pEvt)
{
  S_BUTTON *pBtn = pObj;

  SDL_Point mousePos;
  mousePos.x = pEvt->motion.x;
  mousePos.y = pEvt->motion.y;

  if (pBtn->m_nFSM == 0)
  {
    switch (pEvt->type)
    {
    case SDL_MOUSEMOTION:
      if (SDL_PointInRect(&mousePos,&pBtn->m_Rect))
      {
        pBtn->m_fillColor.a = 0x80;
        pBtn->m_nFSM = 1;
      }
      break;
    }
  }
  else if (pBtn->m_nFSM == 1) //사각형 내부진입상태
  {
    switch (pEvt->type)
    {
    case SDL_MOUSEMOTION:
      if (!SDL_PointInRect(&mousePos,&pBtn->m_Rect) )
      {
        pBtn->m_fillColor.a = 0xff;
        pBtn->m_nFSM = 0;
      }
      break;
    case SDL_MOUSEBUTTONDOWN:
      if (SDL_PointInRect(&mousePos,&pBtn->m_Rect))
      {
        if (pBtn->m_pCallbackBtnPush != NULL)
        {
          pBtn->m_pCallbackBtnPush(pBtn);
        }
      }
      break;
    }
  }
}

S_BUTTON *myui_createButton(SDL_Renderer *pRenderer,
                       int x, int y, int w, int h, Uint16 btnID,
                       const Uint16 *text,
                       TTF_Font *pFont,
                       void (*pCallbackBtnPush)(struct _S_BUTTON *))
{
  S_BUTTON *pBtn;
  pBtn = SDL_malloc(sizeof(S_BUTTON));

  pBtn->m_base.m_nType = MYUI_BUTTON;
  pBtn->m_base.m_nID = btnID;
  pBtn->m_base.m_bVisible = SDL_TRUE;

  pBtn->m_base.m_fpRender = _render;
  pBtn->m_base.m_fpDestory = _destory;
  pBtn->m_base.m_fpDoEvent = _doEvent;

  pBtn->m_Rect.x = x;
  pBtn->m_Rect.y = y;
  pBtn->m_Rect.w = w;
  pBtn->m_Rect.h = h;

  pBtn->m_nFSM = 0;

  pBtn->m_fillColor.r = 0x80;
  pBtn->m_fillColor.g = 0x80;
  pBtn->m_fillColor.b = 0x80;
  pBtn->m_fillColor.a = 0xff;

  pBtn->m_pCallbackBtnPush = pCallbackBtnPush;

  //라벨생성
  {
    SDL_Color _whiteColor = {0xff, 0xff, 0xff, 0xff};
    SDL_Color _blackColor = {0, 0, 0, 0x00};
    SDL_Surface *textSurface = TTF_RenderUNICODE_Solid(pFont, text, _whiteColor);

    pBtn->m_pLable = SDL_CreateTextureFromSurface(pRenderer, textSurface);
    pBtn->m_rectLabel.x = 0;
    pBtn->m_rectLabel.y = 0;
    pBtn->m_rectLabel.w = textSurface->w;
    pBtn->m_rectLabel.h = textSurface->h;

    SDL_FreeSurface(textSurface);
  }
  
  return pBtn;
}