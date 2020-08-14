#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "ui_base.h"
#include "input_text.h"

static void _destory(void *_pObj)
{
  S_INPUT_TEXT *pObj = _pObj;

  if (pObj->m_pTextTxture)
  {
    SDL_DestroyTexture(pObj->m_pTextTxture);
  }
  SDL_free(pObj);
}

static void _render(void *_pObj, SDL_Renderer *pRender)
{
  S_INPUT_TEXT *pInput = _pObj;

  //배경
  SDL_SetRenderDrawColor(pRender, pInput->m_bgColor.r, pInput->m_bgColor.g,
                         pInput->m_bgColor.b, pInput->m_bgColor.a);

  SDL_RenderFillRect(pRender, &pInput->m_Rect);

  //전경 텍스트
  if (strlen(pInput->m_szBuf) > 0)
  {
    SDL_Surface *textSurface = TTF_RenderText_Solid(pInput->m_pFont,
                                                    pInput->m_szBuf, pInput->m_fgColor);
    pInput->m_pTextTxture = SDL_CreateTextureFromSurface(pRender, textSurface);

    pInput->m_textSize.x = textSurface->w;
    pInput->m_textSize.y = textSurface->h;

    SDL_FreeSurface(textSurface);
  }
  if (pInput->m_pTextTxture)
  {
    SDL_Rect _dstRect = {pInput->m_Rect.x, pInput->m_Rect.y,
                         pInput->m_textSize.x, pInput->m_textSize.y};
    SDL_RenderCopy(pRender, pInput->m_pTextTxture, NULL, &_dstRect);
    SDL_DestroyTexture(pInput->m_pTextTxture);
    pInput->m_pTextTxture = NULL;
  }
}

static void _doEvent(void *_pObj, SDL_Event *evt)
{
  S_INPUT_TEXT *pObj = _pObj;
  if (evt->type == SDL_TEXTINPUT)
  {
    strcat(pObj->m_szBuf, evt->text.text);
    //   printf("%s \r", pObj->m_szBuf);
  }
  else if (evt->type == SDL_KEYDOWN)
  {
    if (evt->key.keysym.sym == SDLK_BACKSPACE)
    {
      int _len = strlen(pObj->m_szBuf);
      pObj->m_szBuf[_len - 1] = 0x00;
      SDL_Event evt;
      evt.type = SDL_TEXTINPUT;
      evt.text.text[0] = 0x00;
      SDL_PushEvent(&evt);
    }
  }
}

S_INPUT_TEXT *myui_createInputText(SDL_Renderer *pRenderer,
                                   int x, int y, int w, int h,
                                   Uint16 nID,
                                   TTF_Font *pFont,
                                   SDL_Color m_fgColor,
                                   SDL_Color m_bgColor)
{
  S_INPUT_TEXT *pObj = SDL_malloc(sizeof(S_INPUT_TEXT));

  pObj->m_base.m_nType = MYUI_TEXT_INPUT;
  pObj->m_base.m_nID = nID;

  pObj->m_Rect.x = x;
  pObj->m_Rect.y = y;
  pObj->m_Rect.w = w;
  pObj->m_Rect.h = h;

  pObj->m_szBuf[0] = 0x00;

  pObj->m_fgColor = m_fgColor;
  pObj->m_bgColor = m_bgColor;

  pObj->m_pFont = pFont;
  pObj->m_pTextTxture = NULL;
  pObj->m_base.m_fpRender = _render;
  pObj->m_base.m_fpDestory = _destory;
  pObj->m_base.m_fpDoEvent = _doEvent;

  return pObj;
}