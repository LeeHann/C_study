#ifndef __TEXT_LABLE_H__
#define __TEXT_LABLE_H__

typedef struct text_lable
{
  Uint16 m_nType; //오브잭트 구분하기 위한 형식 식별자 
  SDL_bool m_bVisible;
  Uint16 m_nID;  

  TTF_Font *m_pFont;
  SDL_Texture *m_pLableTxture;
  
  SDL_Rect m_Rect;
  Uint16 m_nFSM;

  SDL_Color m_fgColor;
  SDL_Color m_bgColor; 

  void (*m_fpDestory)(struct text_lable *pObj);
  void (*m_fpRender)(struct text_lable *pObj, SDL_Renderer *pRender);

} S_TextLable;

S_TextLable *createLable(SDL_Renderer *pRenderer,
                          int x, int y,  Uint16 btnID,
                          const Uint16 *text,
                          TTF_Font *pFont);
// void TextLable_destory(S_TextLable *pObj);
// void TextLable_render(S_TextLable *pObj, SDL_Renderer *pRender);

#endif