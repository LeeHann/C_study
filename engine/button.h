#ifndef __BUTTON_H__
#define __BUTTON_H__

typedef struct _S_BUTTON
{
  SDL_Texture *m_pLable;
  SDL_Rect m_rectLabel;

  SDL_bool m_bVisible;
  Uint16 m_nID;
  SDL_Rect m_Rect;
  Uint16 m_nFSM;
  SDL_Color m_fillColor;
  void (*m_pCallbackBtnPush)(struct _S_BUTTON *);
  // SDL_bool bCheckHitRect;

} S_BUTTON;

void Button_Init(S_BUTTON *pBtn, int x, int y, int w, int h, Uint16 btnID,
  void (*pCallbackBtnPush)(struct _S_BUTTON *));
void Button_Render(S_BUTTON *pBtn,SDL_Renderer *pRender);
void Button_DoEvent(S_BUTTON *pBtn,SDL_Event *pEvt);
S_BUTTON *createButton(int x, int y, int w, int h, Uint16 btnID,
                       const Uint16 *text,
                       TTF_Font *pFont,
                       SDL_Renderer *pRenderer,
                       void (*pCallbackBtnPush)(struct _S_BUTTON *));
void destoryButton(S_BUTTON *pBtn);

#endif