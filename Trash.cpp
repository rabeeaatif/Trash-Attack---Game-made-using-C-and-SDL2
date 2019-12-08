#include "Trash.hpp"

Trash::Trash()
{
}

Trash::~Trash()
{
  cout << "Trash Deallocated" << endl;
}

Trash::Trash(LTexture *image, float x, float y) : Unit(image, x, y)
{
  spriteSheetTexture = image;
}

void Trash::Move()
{
  //speedx = speedx * friction;
  //speedy = speedy * friction;

  //x = x + speedx;
  y = y + 2; //speedy;
  if (y > 900)
  {
    SetAlive(false);
  }
}

void Trash::Render(long int &frame, SDL_Renderer *gRenderer, bool debug)
{
  spriteSheetTexture->Render(x - width / 2, y - height / 2, &spriteClips[frame % MOVING_FRAMES], 0.0, NULL, SDL_FLIP_VERTICAL, gRenderer);
  if (debug == true)
  {
    SDL_Rect rect = {x - width / 2, y - height / 2, width, height};
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderDrawRect(gRenderer, &rect);
  }
}
