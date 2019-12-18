#pragma once
#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#else
#include <SDL.h>
#include <SDL_image.h>
#endif
#include <cstdio>
#include <iostream>

//Texture wrapper class
class LTexture
{
private:
  SDL_Texture *texture;
  int width;
  int height;

public:
  LTexture();
  ~LTexture();

  bool LoadFromFile(std::string path, SDL_Renderer *gRenderer);

  void Free(); //Deallocates texture

  //Set color modulation
  void SetColor(Uint8 red, Uint8 green, Uint8 blue);

  //Set blending
  void SetBlendMode(SDL_BlendMode blending);

  //Set alpha modulation
  void SetAlpha(Uint8 alpha);

  void Render(int x, int y, SDL_Rect *clip = NULL,SDL_Renderer *gRenderer = NULL, double angle = 0.0, SDL_Point *center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE, int scaleby = 0);
  void render_screen(SDL_Renderer*);
  int GetWidth();
  int GetHeight();
};
