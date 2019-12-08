#include <iostream>
#include "Paper.hpp"

Paper::Paper()
{
}

Paper::~Paper()
{
  cout << "Paper Deallocated" << endl;
}

Paper::Paper(LTexture *image, float x, float y) : Trash(image, x, y)
{
  spriteSheetTexture = image;

  //Frame 0
  // spriteClips[ 0 ].x = image->;
  // spriteClips[ 0 ].y =   0;

  spriteClips[0].x = 0;
  spriteClips[0].y = 0;
  spriteClips[0].h = 96;
  spriteClips[0].w = 100;

  this->width = spriteClips[0].w;
  this->height = spriteClips[0].h;
}

void Paper::Move()
{
  //speedx = speedx * friction;
  //speedy = speedy * friction;

  //x = x + speedx;
  y = y + 2; //speedy;
  if (y > 700)
  {
    SetAlive(false);
  }
}

void Paper::Render(long int &frame, SDL_Renderer *gRenderer, bool debug)
{
  spriteSheetTexture->Render(x - width / 2, y - height / 2, &spriteClips[frame % MOVING_FRAMES], 0.0, NULL, SDL_FLIP_VERTICAL, gRenderer);
  if (debug == true)
  {
    SDL_Rect rect = {x - width / 2, y - height / 2, width, height};
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderDrawRect(gRenderer, &rect);
  }
}
