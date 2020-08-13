#ifndef __BUTTON_H__
#define __BUTTON_H__

typedef struct _S_BUTTON
{
  Uint16 m_nType;
  SDL_bool m_bVisible;
  Uint16 m_nID;

  SDL_Texture *m_pLable;
  SDL_Rect m_rectLabel;

  SDL_Rect m_Rect;
  Uint16 m_nFSM;
  SDL_Color m_fillColor;
  void (*m_pCallbackBtnPush)(struct _S_BUTTON *);
  // SDL_bool bCheckHitRect;

  void (*m_fpDestory)(struct _S_BUTTON *pObj);
  void (*m_fpRender)(struct _S_BUTTON *pObj, SDL_Renderer *pRender);

} S_BUTTON;

void Button_Init(S_BUTTON *pBtn, int x, int y, int w, int h, Uint16 btnID,
                 void (*pCallbackBtnPush)(struct _S_BUTTON *));

// void Button_Render(S_BUTTON *pBtn,SDL_Renderer *pRender);
// void Button_DoEvent(S_BUTTON *pBtn,SDL_Event *pEvt);
// void destoryButton(S_BUTTON *pBtn);

S_BUTTON *createButton(SDL_Renderer *pRenderer,
                       int x, int y, int w, int h, Uint16 btnID,
                       const Uint16 *text,
                       TTF_Font *pFont,
                       void (*pCallbackBtnPush)(struct _S_BUTTON *));

#endif