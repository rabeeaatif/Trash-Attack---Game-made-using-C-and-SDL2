#pragma once
#include "SDL.h"
#include "LTexture.hpp"
#include "Point.hpp"


class Button{
private:
  LTexture* image;
  SDL_Rect* button_rect;
  Point Position;
  LTexture* font;
public:
    Button();
    Button(LTexture*, LTexture*, Point);
    void Render(SDL_Renderer*);
};