#ifndef TEXTDRAW_H_INCLUDED
#define TEXTDRAW_H_INCLUDED

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <GL/gl.h>
#include <GL/glu.h>

void RenderText(std::string message, SDL_Color color, int x, int y, int sz) {


  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();

  gluOrtho2D(0, 1920, 1080, 0); // m_Width and m_Height is the resolution of window
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();

  glDisable(GL_DEPTH_TEST);
  glEnable(GL_TEXTURE_2D);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  GLuint texture;
  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);



  TTF_Font * font = TTF_OpenFont("fonts/DejaVuSansMono.ttf", sz);

  if(!font) {
    printf("TTF_OpenFont: %s\n", TTF_GetError());
    // handle error
  }

  SDL_Surface * sFont = TTF_RenderText_Blended(font,message.c_str(),color);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexImage2D(GL_TEXTURE_2D,0, GL_RGBA,sFont->w, sFont->h,0, GL_BGRA, GL_UNSIGNED_BYTE,sFont->pixels);

  glBegin(GL_QUADS);
  {
    glTexCoord2f(0,0); glVertex2f(x, y);
    glTexCoord2f(1,0); glVertex2f(x + sFont->w, y);
    glTexCoord2f(1,1); glVertex2f(x + sFont->w, y + sFont->h);
    glTexCoord2f(0,1); glVertex2f(x, y + sFont->h);
  }
  glEnd();

  glDisable(GL_BLEND);
  glDisable(GL_TEXTURE_2D);
  glEnable(GL_DEPTH_TEST);

  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();

  glDeleteTextures(1, &texture);
  TTF_CloseFont(font);
  SDL_FreeSurface(sFont);
}






#endif // TEXTDRAW_H_INCLUDED
